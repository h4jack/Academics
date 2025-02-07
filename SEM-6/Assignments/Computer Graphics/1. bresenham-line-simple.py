import matplotlib.pyplot as plt

def bresenham_line(x1, y1, x2, y2):
    points = []

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    dp = 2*dy - dx

    while x1 <= x2:
        points.append((x1, y1))

        x1 += 1
        if dp < 0:
            dp += 2 * dy
        else:
            y1 += 1
            dp += 3 * (dy - dx)

    return points

def main():
    print("Bresenham's Line Drawing Algorithm")
    try:
        x1 = int(input("Enter x1: "))
        y1 = int(input("Enter y1: "))
        x2 = int(input("Enter x2: "))
        y2 = int(input("Enter y2: "))

        points = bresenham_line(x1, y1, x2, y2)
        print("Points on the line:", points)
        # Extract x and y coordinates
        x_coords, y_coords = zip(*points)
        print("X coordinates:", x_coords)
        print("Y coordinates:", y_coords)
        # Plotting the line
        plt.plot(x_coords, y_coords, marker='o', color='blue')
        plt.title("Bresenham's Line Drawing")
        plt.xlabel("X-axis")
        plt.ylabel("Y-axis")
        plt.grid(True)
        plt.gca().set_aspect('equal', adjustable='box')
        plt.show()
        
    except ValueError:
        print("Please enter valid integer values.")

if __name__ == "__main__":
    main()
