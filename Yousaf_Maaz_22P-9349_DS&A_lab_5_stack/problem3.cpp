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

class Stackimplementation
{
    Node *top;
    int capacity;
    int length;

public:
    Stackimplementation(int s)
    {
        capacity = s;
        top = NULL;
        length = 0;
    }

    ~Stackimplementation()
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
        return length == capacity;
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

    void peek()
    {
        if (!isEmpty())
        {
            cout << "Top of the stack: " << top->val << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            cout << "Stack Elements:" << endl;
            Node *temp = top;
            while (temp != NULL)
            {
                cout << temp->val << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
    //     void display()
    // {
    //     if (!isEmpty())
    //     {
    //         cout << "Stack Elements as Array:" << endl;

    //         int stackSize ; // Assuming you have a function to get the size of the stack
    //         int *stackArray = new int[stackSize]; // Create an array to store stack elements

    //         Node *temp = top;
    //         int index = 0;

    //         while (temp != NULL)
    //         {
    //             stackArray[index] = temp->val;
    //             temp = temp->next;
    //             index++;
    //         }

    //         // Display the elements as if they were in an array
    //         for (int i = stackSize - 1; i >= 0; i--)
    //         {
    //             cout << stackArray[i] << endl;
    //         }

    //         delete[] stackArray; // Don't forget to free the allocated memory
    //         cout << endl;
    // //     }
    // }
};

int main()
{
    string word;
    cout << "Enter the word:" << endl;
    cin >> word;

    Stackimplementation object1(word.length());
    Stackimplementation object2(word.length());

    for (int i = 0; i < word.length(); i++)
    {
        char newstring = word[i];
        object1.push(newstring);
    }

    while (true)
    {
        int choice;
        cout << "Enter what you want:" << endl;
        cout << "1.undo." << endl;
        cout << "2.redo." << endl;
        cout << "3.Exit." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            object2.push(object1.pop());
            object1.display();
            break;
        case 2:
            object1.push(object2.pop());
            object1.display();
            break;
        case 3:
            exit(0);
        }
    }

    return 0;
}
