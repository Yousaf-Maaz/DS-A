#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class stackImplementation
{
    int *arr;
    int length;
    int capacity;
    int top;

public:
    stackImplementation(int s)
    {
        capacity = s;
        length = 0;
        top = -1;
        arr = new int[capacity];
    }

    bool isfull()
    {
        if (length == capacity)
        {
            return true;
        }
        else
            return false;
    }
    bool isempty()
    {
        if (length == 0)
        {
            return true;
        }
        else
            return false;
    }

    void push(int val)
    {
        if (isfull())
        {
            cout << "Stack overflow :)" << endl;
            return;
        }
        top++;
        arr[top] = val;
        length++;
    }

    int pop()
    {
        if (isempty())
        {
            cout << "Stack underflow " << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        length--;
        return value;
    }

    int peak()
    {
        if (isempty())
        {
            cout << "Stack underflow " << endl;
            return -1;
        }

        int value = arr[top];
        return value;
    }

    void display()
    {
        if (!isempty())
        {
            cout << "Swap elements: " << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
            cout << endl;
        }
    }
    ~stackImplementation()
    {
        while (!isempty())
        {
            pop();
        }
    }

    int evalatepostfixexpression(string postfix)
    {
        stackImplementation operands(postfix.length());

        for (int i = 0; i < postfix.length(); i++)
        {
            char c = postfix[i];

            if (isdigit(c))
            {

                operands.push(c - '0');
            }
            else if (c == ' ')
            {
                // Ignore spaces
                continue;
            }
            else
            {
                int operand2 = operands.pop();
                int operand1 = operands.pop();

                switch (c)
                {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0)
                    {
                        cout << "Division by zero!" << endl;
                        return INT_MIN;
                        operands.push(operand1 / operand2);
                        break;
                    default:
                        cout << "Invalid operator: " << c << endl;
                        return INT_MIN;
                    }
                }
            }

            if (!operands.isempty())
            {
                return operands.peak();
            }
            else
            {
                cout << "Invalid postfix expression" << endl;
                return INT_MIN; // use pre defined from c++ liabary.
            }
        }
    }
};

int main()
{

    stackImplementation stack(10);

    // hard coding..

    string postfixExpression = "34*2+";

    int result = stack.evalatepostfixexpression(postfixExpression);

    if (result != -1)
    {
        cout << "Result: " << result << endl;
    }
    else
    {
        cout << "Invalid postfix expression" << endl;
    }

    return 0;
}
