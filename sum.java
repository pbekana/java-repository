// functions in a java

import java.util.Scanner;

public class sum{
    public static int sum(int a,int b){
        return a+b;
    }
    public static void input(){
        Scanner scanner = new Scanner(System.in);

        // Ask for the user's name
        System.out.println("Please enter your name: ");
        String name = scanner.nextLine();

        // Ask for the user's age
        System.out.print("Please enter your age: ");
        int age = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Ask for the user's city
        System.out.print("Please enter your city: ");
        String city = scanner.nextLine();

        // Display the entered information
        System.out.println("\n--- User Information ---");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("City: " + city);

        // Close the scanner
        scanner.close();
    }
    public static void main(String[] args){
int num1=78,num2=22;
// calling function
int result = sum(num1,num2);
input();
System.out.println("the sum of two number is :"+result);

    }
}