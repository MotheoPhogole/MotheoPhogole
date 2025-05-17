import java.util.Scanner;

public class JavaBasicCalculator {
    public static void main(String[] args) {
        // Create a simple calculator that performs basic arithmetic operations
        // such as addition, subtraction, multiplication, and division.
        // The program should prompt the user for two numbers and an operator,
        // then display the result of the operation.
        // The calculator should handle invalid input gracefully and provide
        // appropriate error messages.
        // The program should also allow the user to perform multiple calculations
        
        //Defining a Scanner object to read user input
        // and a loop to allow multiple calculations
        Scanner scanner = new Scanner(System.in);

        //Prompting user for input
        System.out.print("Enter first number: ");
        double num1 = scanner.nextDouble();
        System.out.print("Enter second number: ");
        double num2 = scanner.nextDouble();
        System.out.print("Choose an operation (+, -, *, /, ^): ");
        char operation = scanner.next().charAt(0);

        //Performing the calculation based on user input
        //Using switch-case to handle different operations
        double result;
        switch (operation) {
            case '+':
                result = num1 + num2; // Addition
                break;
            case '-':
                result = num1 - num2; // Subtraction
                break;
            case '*':
                result = num1 * num2; // Multiplication
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2; // Division
                } else {
                    System.out.println("Error! Division by zero.");
                    return;
                }
                break;
            case '^':
                result = Math.pow(num1, num2);//Power of,NB: num2 will always be the power of num1
                break;
            default:
                System.out.println("Invalid operation!");
                return;
        }
        //Displaying the result of the calculation
        System.out.println("Result: "+ num1 +" "+ operation +" "+ num2 +" = "+ result);
    }
}
