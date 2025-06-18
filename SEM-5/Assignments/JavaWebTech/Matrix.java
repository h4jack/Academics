// Write a java program to perform Addition and Transpose of Matrix.

import java.util.*;

class Matrix{
    int[][] arr;
    int m, n;
    Matrix(int m, int n){
        this.arr = new int[m][n];
        this.m = m;
        this.n = n;
    }

    public int [][] add(int x[][], int m, int n){
        int y[][] = new int[m][n];
        int i = 0;
        while(i < m){
            int j = 0;
            while(j < n){
                y[i][j] = arr[i][j] + x[i][j];
                j++;
            }
            i++;
        }
        return y;
    }

    public int [][] transpose(){
        int x[][] = new int[n][m];
        int i = 0;
        while(i < m){
            int j = 0;
            while(j < n){
                x[i][j] = arr[j][i];
                j++;
            }
            i++;
        }
        return x;
    }

    public void print(int arr[][]){
        int i = 0;
        while(i < m){
            int j = 0;
            while(j < n){
                System.out.print(arr[i][j] + " ");
                j++;
            }
            System.out.print("\n");
            i++;
        }
    }
    public void print(){
        int i = 0;
        while(i < m){
            int j = 0;
            while(j < n){
                System.out.print(arr[i][j] + " ");
                j++;
            }
            System.out.print("\n");
            i++;
        }
    }

    public void scan(int arr[][]){
        int i = 0;
        Scanner sc = new Scanner(System.in);
        while(i < m){
            int j = 0;
            while(j < n){
                arr[i][j] = sc.nextInt();
                j++;
            }
            i++;
        }
    }
    public void scan(){
        int i = 0;
        Scanner sc = new Scanner(System.in);
        while(i < m){
            int j = 0;
            while(j < n){
                arr[i][j] = sc.nextInt();
                j++;
            }
            i++;
        }
    }
}

class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the matrix(e.g: m n): ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        Matrix x = new Matrix(m, n);
        System.out.println("**Enter the values of the Matrix** ");
        // int[][] arr1 = new int[m][n];
        x.scan();
        System.out.println("**the transpose of the Matrix** ");
        int arr [][]= x.transpose();
        x.print(arr);
    }
}