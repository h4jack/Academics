import java.util.Scanner;

class avg3{
    private static float avgof3(int a, int b, int c){
        return (a+b+c)/3;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int a, b, c;
        System.out.println("****Find Averate of Three Number*****");
        System.out.print("Enter Three Number: ");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        System.out.print("The Averate of the Three Number: "+a+", "+b+", "+c+" is : "+avgof3(a,b,c));
    }
}