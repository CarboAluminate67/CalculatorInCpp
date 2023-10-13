#include <iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> split(string expression, char del) // Function to split expression into parts consisting of 2 numbers and 1 operator
{
    int pos = expression.find_first_of("+-*/");
    try
    {
        expression.insert(pos, " "); // ensuring whitespace is included to split properly
        expression.insert(pos + 2, " ");
    }
    catch (...)
    {
        cout << "Valid operators are + - * /\n";
        return{ "" };
    }

    string temp = "";
    vector<string> parts;
    for (int i = 0; i < (int)expression.length(); i++) // Splitng words at whitespace
    {
        if (expression[i] != del)
        {
            temp += expression[i];
        }
        else
        {
            if (temp != "")
            {
                parts.insert(parts.end(), temp);
            }
            temp = "";
        }
    }
    parts.insert(parts.end(), temp);
    return parts; // Returns vector {number1, operator, number2}
}

int main()
{
    cout << "Welcome to Calculator. Operation Syntax: {Number_1 (+ - * /) Number_2}. Enter 'quit' to quit.\n";
    string expression = "";
       
    while (true) // loops until user quits
    {
        cout << "\nExpression: ";
        getline(cin, expression);

        if (expression == "quit")
        {
            break;
        }

        vector<string> parts = split(expression, ' '); // Initializes and splits expression vector
        
        try
        {
            double num1 = stod(parts[0]);
            double num2 = stod(parts[2]);
            string oper = parts[1];
            if (oper == "+") // Calculations and printing
            {
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            }
            else if (oper == "-")
            {
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            }
            else if (oper == "*")
            {
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            }
            else if (oper == "/")
            {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
        }
        catch (invalid_argument) // catches incorrect input for further error handling
        {
            cout << "Please enter a number, an operator, and another number.\n";
        }
    }
    return 0;
}

