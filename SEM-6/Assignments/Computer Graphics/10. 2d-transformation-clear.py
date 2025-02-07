import numpy as np
import matplotlib.pyplot as plt

# ----------- INPUT AND PLOTTING FUNCTIONS -----------

def get_polygon():
    n = int(input("Enter number of vertices: "))
    points = []
    for i in range(n):
        x, y = map(float, input(f"x[{i+1}] y[{i+1}]: ").split())
        points.append([x, y, 1])
    return np.array(points)

def plot(polygon, transformed):
    def close(p): return np.vstack([p[:, :2], p[0, :2]])  # Close the polygon
    plt.clf()
    plt.plot(*close(polygon).T, 'ro--', label="Original")
    plt.plot(*close(transformed).T, 'go-', label="Transformed")
    plt.title("2D Transformation")
    plt.xlabel("X"); plt.ylabel("Y")
    plt.legend(); plt.axis('equal'); plt.grid(True)
    plt.pause(0.1)

def apply_transformation(points, matrix):
    return points @ matrix.T

# ----------- TRANSFORMATION FUNCTIONS -----------

def translate():
    tx = float(input("tx: "))
    ty = float(input("ty: "))
    return np.array([
        [1, 0, tx],
        [0, 1, ty],
        [0, 0, 1]
    ])

def scale():
    sx = float(input("sx: "))
    sy = float(input("sy: "))
    return np.array([
        [sx, 0, 0],
        [0, sy, 0],
        [0, 0, 1]
    ])

def rotate():
    angle = float(input("Angle (in degrees): "))
    rad = np.radians(angle)
    return np.array([
        [np.cos(rad), -np.sin(rad), 0],
        [np.sin(rad),  np.cos(rad), 0],
        [0, 0, 1]
    ])

def shear():
    shx = float(input("shx: "))
    shy = float(input("shy: "))
    return np.array([
        [1, shx, 0],
        [shy, 1, 0],
        [0, 0, 1]
    ])

def reflect():
    axis = input("Reflect across which axis? (x / y / origin): ").lower()
    if axis == 'x':
        return np.array([
            [1, 0, 0],
            [0, -1, 0],
            [0, 0, 1]
        ])
    elif axis == 'y':
        return np.array([
            [-1, 0, 0],
            [0, 1, 0],
            [0, 0, 1]
        ])
    elif axis == 'origin':
        return np.array([
            [-1, 0, 0],
            [0, -1, 0],
            [0, 0, 1]
        ])
    else:
        print("Invalid axis!")
        return np.identity(3)

# ----------- MAIN FUNCTION -----------

def main():
    print("2D Transformations using Homogeneous Coordinates")
    polygon = get_polygon()
    transformed = polygon.copy()

    plt.ion()
    plt.figure()

    while True:
        print("\nOptions:")
        print("1: Translate")
        print("2: Scale")
        print("3: Rotate")
        print("4: Shear")
        print("5: Reflect")
        print("q: Quit")

        choice = input("Choose transformation: ")

        if choice == 'q':
            break

        try:
            if choice == '1':
                mat = translate()
            elif choice == '2':
                mat = scale()
            elif choice == '3':
                mat = rotate()
            elif choice == '4':
                mat = shear()
            elif choice == '5':
                mat = reflect()
            else:
                print("Invalid choice!")
                continue

            transformed = apply_transformation(transformed, mat)
            plot(polygon, transformed)

        except Exception as e:
            print("Error:", e)

    plt.ioff()
    plt.show()

# ----------- RUN MAIN -----------

if __name__ == "__main__":
    main()
