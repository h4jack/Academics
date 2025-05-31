import java.util.*;

class GCDLCM{
    private static int gcd(int a, int b){
            if(a == b){
                return a;
            }else if(a < b){
                b = b - a;
            }else{
                a = a - b;
            }
            return gcd(a, b);
    }

    private static int lcm(int a, int b){
        return (a*b)/gcd(a,b);
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("...Find GCD and LCM of Two Number...");
        System.out.print("Enter the first Number: ");
        int a = sc.nextInt();
        System.out.print("Enter the second Number: ");
        int b = sc.nextInt();
        System.out.print("\n The GCD of Two Number "+a+", "+b+" is: "+gcd(a,b));
        System.out.print("\n The LCM of Two Number "+a+", "+b+" is: "+lcm(a,b));
    }
}