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
};
int main()
{
    stackImplementation object(3);
    int a, b;
    cout << "This Program swaps number using stack:" << endl;
    cout << "Enter the number: " << endl;
    cin >> a;
    cout << "Enter another the number : " << endl;
    cin >> b;

    cout << "Before" << endl;
    object.push(a);
    object.push(b);
    object.display();
    a = object.pop();
    b = object.pop();
    cout << "After" << a << " " << b << endl;

    return 0;
}