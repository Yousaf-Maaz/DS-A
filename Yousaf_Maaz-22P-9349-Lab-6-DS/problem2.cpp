#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string data;
    node *next;

    node(string val)
    {
        data = val;
        next = nullptr;
    }
};

class circularlist
{
private:
    node *head;
    int length;

public:
    circularlist()
    {
        head = nullptr;
        length = 0;
    }

    int getLength()
    {
        return length;
    }

    void insert(string val, int position)
    {
        node *n = new node(val);
        node *curr = head;

        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input" << endl;
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
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);

        cout << endl;
    }

    bool isPalindrome()
    {
        // Check if the list is empty.
        if (head == nullptr)
        {
            return true;
        }

        // Find the middle node of the list.
        node *slow = head;
        node *fast = head;

        while (fast != nullptr && fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list length is odd, move slow to the next node.
        if (fast->next == head)
        {
            slow = slow->next;
        }

        // Reverse the second half of the list.
        node *prev = nullptr;
        node *curr = slow;
        node *next;

        do
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != slow);

        // Compare the reversed second half with the first half of the list.
        node *left = head;
        node *right = prev;

        while (left != slow && right != nullptr)
        {
            if (left->data != right->data)
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }

    ~circularlist()
    {
        while (head != nullptr)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    circularlist myList;
    int choice;

    do
    {
        cout << "Circular Linked List Menu:" << endl;
        cout << "1. Insert an element" << endl;
        cout << "2. Check if the list is a palindrome" << endl;
        cout << "3. Print the list" << endl;
        cout << "4. Get the length of the list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string val;
            int position;
            cout << "Enter the value to insert: ";
            cin >> val;
            cout << "Enter the position to insert: ";
            cin >> position;
            myList.insert(val, position);
            break;
        }
        case 2:
        {
            bool isPal = myList.isPalindrome();
            if (isPal)
                cout << "The list is a not  palindrome." << endl;
            else
                cout << "The list is  a palindrome." << endl;
            break;
        }
        case 3:
            myList.printList();
            break;
        case 4:
            cout << "Length of the list: " << myList.getLength() << endl;
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}