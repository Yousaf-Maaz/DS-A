#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class node
{
public:
    string names;
    node *next;

    node(string n)
    {
        names = n;
        next = nullptr;
    }
};

class Championofpotion
{

    node *head;
    int length;

public:
    Championofpotion()
    {
        length = 0;
        head = nullptr;
    }

    void insert(string val, int position)
    {
        node *n = new node(val);
        node *curr = head;

        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input,not possible" << endl;
            return;
        }

        if (head == nullptr)
        {
            head = n;
            head->next = head;
        }
        else if (position == 1)
        {
            n->next = head;
            while (curr->next != head)
                curr = curr->next;
            curr->next = n;
            head = n;
        }
        else
        {
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }

        length++;
    }

    void remove(int position)
    {
        if (head == nullptr || length == 0)
        {
            cout << "Empty ,we can't sorry" << endl;
            return;
        }
        if (position < 1 || position > length)
        {
            cout << "Invalid input" << endl;
            return;
        }
        if (position == 1)
        {
            node *current = head;
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete current;
        }
        else
        {
            node *current = head;
            node *slow = nullptr;
            for (int i = 1; i < position; i++)
            {
                slow = current;
                current = current->next;
            }
            slow->next = current->next;
            delete current;
        }

        length--;
    }
    void printList()
    {
        node *curr = head;

        if (curr == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        do
        {
            cout << curr->names << " ";
            curr = curr->next;
        } while (curr != head);

        cout << endl;
    }
};

int main()
{
    Championofpotion wizard;
    wizard.insert("yousaf", 1);
    wizard.insert("khan", 2);
    wizard.insert("Abc", 3);
    wizard.insert("xyz", 4);
    wizard.insert("mno", 5);
    int r = rand() % 5 + 1;

    while (true)
    {
        cout << "1. Traverse\n";
        cout << "2. Start game\n";
        cout << "3. End Game\n";
        int choice;
        cout << "Enter the number\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "All the list:" << endl;
            wizard.printList();
            break;

        case 2:
            cout << "Remove by random number\n";
            wizard.remove(r);
            cout << "Now the list is:\n";
            wizard.printList();
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
