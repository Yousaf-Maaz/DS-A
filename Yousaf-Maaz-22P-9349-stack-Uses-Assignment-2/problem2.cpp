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

    bool areBracketsMatched(const string &str)
    {
        stackImplementation bracketStack(str.length());
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                bracketStack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (bracketStack.isempty())
                {
                    return false;
                }
                char top = bracketStack.peak();
                bracketStack.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
            }
        }

        return bracketStack.isempty();
    }
};
int main()
{
    cout << "Enter the size of the string\n";

    int size;
    cin >> size;

    string input;
    cout << "Enter a string with brackets: ";
    cin >> input;

    stackImplementation obj(size);

    if (obj.areBracketsMatched(input))
    {
        cout << "Brackets are properly matched." << endl;
    }
    else
    {
        cout << "Brackets are not properly matched." << endl;
    }

    return 0;
}