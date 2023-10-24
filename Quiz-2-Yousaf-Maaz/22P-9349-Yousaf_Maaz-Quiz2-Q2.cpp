#include <iostream>
using namespace std;

class Node
{
public:
    char val;
    Node *next;
    Node(char val)
    {
        this->val = val;
        next = NULL;
    }
};

class stack_based_escape
{
    Node *top;
    int length;

public:
    stack_based_escape()
    {

        top = NULL;
        length = 0;
    }

    ~stack_based_escape()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    bool isFull()
    {
        return length;
    }

    void push(char val)
    {
        if (!isFull())
        {
            Node *temp = new Node(val);
            temp->next = top;
            top = temp;
            length++;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            char val = top->val;
            top = top->next;
            delete temp;
            length--;
            return val;
        }
        return '\0';
    }
};
int main()
{

    cout << "Welcome to the cave\n";
    stack_based_escape cave;

    while (true)
    {
        cout << "1.Go forward\n";
        cout << "2.Go Back\n";
        cout << "3.Run from the cave........I saw mummy\n";

        int choice;
        cout << "Enter the choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the location:so that you can back\n";
            char a;
            cin >> a;
            cave.push(a);
            break;
        }

        case 2:
        {
            char a = cave.pop();
            cout << "You are now at this location\ns"
                 << " " << a;
            break;
        }
        case 3:
        {
            cout<<"I saw a mummy\n";
            return 0;
        }
        default:
            break;
        }
    }

    return 0;
}
