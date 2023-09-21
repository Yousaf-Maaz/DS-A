#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class stackImplementation
{
    char *arr;
    int length;
    int capacity;
    int top;

public:
    stackImplementation(int s)
    {
        capacity = s;
        length = 0;
        top = -1;
        arr = new char[capacity];
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

    void push(char val)
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

    char pop()
    {
        if (isempty())
        {
            cout << "Stack underflow " << endl;
            return 0;
        }
        char value = arr[top];
        top--;
        length--;
        return value;
    }

    char peak()
    {
        if (isempty())
        {
            cout << "Stack underflow " << endl;
            return 0;
        }

        char value = arr[top];
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

    // cout << "This program reversed string using stack:" << endl;
    // string name;
    // cout << "Enter he string you want to reversed" << endl;
    // cin >> name;
    // char s[name.length()];
    // char element;

    // stackImplementation object(name.length());
    // for (int i = 0; i < name.length(); i++)
    // {
    //     s[i]=name[i];
    //     s.push([i]);

    //     // char newstring = name[i];
    //     // object.push(newstring);
    //     //name[i]=
    // }
    // cout << "After reversed the string is:" << endl;

    // while (!object.isempty())
    // {
    //     cout << object.pop();
    // }

    // return 0;

    string word;

    cout << "Enter word" << endl;

    cin >> word;

    char str[word.length()];

    char element;

    stackImplementation object(word.length());

    for (int i = 0; i < word.length(); i++)

    {

        str[i] = word[i];

        object.push(str[i]);
    }

    for (int i = 0; i < word.length(); i++)
    {

        element = object.pop();

        str[i] = element;
    }

    for (int i = 0; i < word.length(); i++)

    {

        cout << str[i];
    }
}