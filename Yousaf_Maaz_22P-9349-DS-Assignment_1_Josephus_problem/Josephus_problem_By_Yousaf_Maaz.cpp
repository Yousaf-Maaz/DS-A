#include <iostream>
using namespace std;
//node class here
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};
//circular linklist class here.
class CircularList
{
private:
    Node *head;
    int length;

public:
    CircularList()
    {
        head = nullptr;
        length = 0;
    }
//insert method
    void insert(int val, int position)
    {
        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input" << endl;
            return;
        }

        Node *n = new Node(val);

        if (head == nullptr)
        {
            head = n;
            head->next = head;
        }
        else if (position == 1)
        {
            Node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
            n->next = head;
            head = n;
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }
//remove method.
    void remove(int position)
    {
        if (head == nullptr || length == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        if (position < 1 || position > length)
        {
            cout << "Invalid input" << endl;
            return;
        }

        if (position == 1)
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            if (length == 1)
            {
                cout << "Person Removed: " << head->data << endl; // Print the removed person
                delete head;
                head = nullptr;
            }
            else
            {
                cout << "Person Removed: " << head->data << endl; // Print the removed person
                temp->next = head->next;
                Node *toDelete = head;
                head = head->next;
                delete toDelete;
            }
        }
        else
        {
            Node *curr = head;
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            Node *toDelete = curr->next;
            curr->next = toDelete->next;

            cout << "Person Removed: " << toDelete->data << endl; // Print the removed person
            delete toDelete;
        }
        length--;
    }
//josephus method.
    int josephus(int N, int M)
    {
        if (!head || M <= 0 || N <= 0)
        {
            return -1; // Invalid input
        }

        Node *current = head;
        Node *prev = nullptr;

                while (length > 1)
        {
            // Move to the M-th person
            for (int i = 1; i < M + 1; i++)
            {
                prev = current;
                current = current->next;
            }

            // Remove the M-th person
            prev->next = current->next;
            Node *leavethecircle = current;
            current = current->next;
            if (leavethecircle == head)
            {
                head = current;
            }

            cout << "Person Removed: " << leavethecircle->data << endl; // Print the removed person
            delete leavethecircle;
            length--;
        }

        return current->data;
    }
};

int main()
{
    CircularList circularList;

    int N, M;
    cout << "This program is for josephus Problem" << endl;

    cout << "Enter the number of people (N): ";
    cin >> N;

    if (N <= 0)
    {
        cout << "Invalid input for the number of people." << endl;
        return 1;
    }

    cout << "Enter the count number  (M): ";
    cin >> M;

    if (M <= 0)
    {
        cout << "Invalid input for the number  count." << endl;
        return 1;
    }

    // Insert values into the circular list
    for (int i = 1; i <= N; i++)
    {
        circularList.insert(i, i);
    }

    // Find the Josephus position
    int josephusPosition = circularList.josephus(N, M);

    cout << "The Josephus position for person who win is: " << josephusPosition << endl;

    return 0;
}
