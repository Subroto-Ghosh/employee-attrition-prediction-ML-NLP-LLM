import java.util.Scanner;

public class SimpleLexer {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter expression: ");
        String input = sc.nextLine();

        int i = 0;

        while (i < input.length()) {

            char ch = input.charAt(i);

            if (ch == ' ') {
                i++;
                continue;
            }

            if (Character.isLetter(ch)) {
                String word = "";

                while (i < input.length() &&
                       Character.isLetterOrDigit(input.charAt(i))) {
                    word += input.charAt(i);
                    i++;
                }

                System.out.println("IDENTIFIER: " + word);
            }

            else if (Character.isDigit(ch)) {
                String num = "";

                while (i < input.length() &&
                       Character.isDigit(input.charAt(i))) {
                    num += input.charAt(i);
                    i++;
                }

                System.out.println("NUMBER: " + num);
            }

            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                System.out.println("OPERATOR: " + ch);
                i++;
            }

            else if (ch == '(' || ch == ')') {
                System.out.println("PARENTHESIS: " + ch);
                i++;
            }

            else {
                System.out.println("UNKNOWN: " + ch);
                i++;
            }
        }

        sc.close();
    }
}