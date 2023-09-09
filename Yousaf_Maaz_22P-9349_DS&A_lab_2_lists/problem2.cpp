/*You're given an initial sequence of characters in a dynamic array (shuffled
string e.g efabir). Your goal is to arrange these characters to perfectly match
a given target string (fariba). You have access to a set of operations—insert
and remove—that allow you to manipulate the arrangement of characters
within the array. With each operation, you'll transform the array, getting closer
to the final arrangement.
Instructions:
• You have a sequence of characters already present in the dynamic array
(insert the 6 characters hard coded by calling the insert method).
• Implement the ArrayList class methods, insert, delete, search, printList,
get. However, we will use make use of only three methods, rest are for
practice only.
• After each operation, you'll observe the array changing, and you should
keep track of the steps taken.
• Your arrangement should eventually match the provided target string.
• Let’s see who arranges my name with the minimum number of steps. I
have done myself using 6 steps
Note that the task must be performed using dynamic array, and all the

operations must be performed using pointers. Plus, you can use any built-
in function/ easy method to match the strings.*/

#include <iostream>
#include <cstring>
using namespace std;

class List
{
private:
    char *arr;
    char *current;
    // int *cuurent;
    int capacity;
    int length;

public:
    List(int c)
    {
        capacity = c;
        arr = new char[c];
        length = 0;
        current = arr;
    }

    void start()
    {
        current = arr;
    }

    void next()
    {
        current++;
    }

    void back()
    {
        current--;
    }

    void tail()
    {
        current = arr + (length - 1);
    }

    void insert(char val, int pos)
    {
        if (length == capacity)
        {
            cout << "Array is full" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid input" << endl;
            return;
        }

        tail();
        for (int i = length; i >= pos; i--)
        {
            *(current + 1) = *current;
            back();
        }

        *(current + 1) = val;
        length++;
    }

    void remove(int pos)
    {
        if (length == 0)
        {
            cout << "Empty" << endl;
            return;
        }

        if (pos < 1 || pos > length)
        {
            cout << "Invalid input" << endl;
            return;
        }

        current = arr + pos - 1;

        for (int i = pos; i < length; i++)
        {
            *current = *(current + 1);
            current++;
        }

        length--;
    }

    void printList()
    {
        start();
        for (int i = 0; i < length; i++)
        {
            cout << *current << " ";
            next();
        }
        cout << endl;
    }

    void update(int val, int pos)
    {
        if (length == 0)
        {
            cout << "Empty" << endl;
            return;
        }

        if (pos < 1 || pos > length)
        {
            cout << "Invalid input" << endl;
            return;
        }

        //*current = arr + (pos - 1);
        *current = val;
    }

    void isMatch(const char *target)
    {
        start();
        for (int i = 0; i < length; i++)
        {
            if (*current != target[i])
            {
                cout << "Oops, string does not match" << endl;
                return;
            }
            next();
        }
        cout << "Wow, correct!" << endl;
    }

    void copy(List &source)
    {
        // Clear the current list
        // clear();

        // Set the capacity and length to match the source list
        capacity = source.capacity;
        length = source.length;

        // Allocate memory for the new list
        arr = new char[capacity];

        // Copy the elements from the source list to the current list using pointers
        char *sourcePtr = source.arr;
        char *destPtr = arr;

        for (int i = 0; i < length; i++)
        {
            *destPtr = *sourcePtr;
            destPtr++;
            sourcePtr++;
        }

        // Reset the current pointer to the beginning of the list
        current = arr;
    }
};

int main()
{
    List myList(6);
    const char *target = "fariba";

    myList.insert('e', 1);
    myList.insert('f', 2);
    myList.insert('a', 3);
    myList.insert('b', 4);
    myList.insert('i', 5);
    myList.insert('r', 6);
    cout << "------------------------------------------------------------\n";
    cout << "Initial List: ";
    myList.printList();

    while (true)
    {
        char choice;
        cout << "------------------------------------------------------------\n";
        cout << "Enter your choice:\n1. Insert\n2. Remove\n3. Exit\n";
        cin >> choice;

        if (choice == '1')
        {
            myList.printList();
            cout << "In which position: ";
            int position;
            cin >> position;
            char value;
            cout << "Enter value: ";
            cin >> value;
            myList.insert(value, position);
            cout << "------------------------------------------------------------\n";
            myList.printList();
            cout << "------------------------------------------------------------\n";
            myList.isMatch(target);
        }
        else if (choice == '2')
        {
            cout << "which position you want to remove:" << endl;
            int position;
            cin >> position;
            myList.remove(position);
            cout << "------------------------------------------------------------\n";
            myList.printList();
        }

        else if (choice == '3')
        {
            break;
        }
    }

    return 0;
}

