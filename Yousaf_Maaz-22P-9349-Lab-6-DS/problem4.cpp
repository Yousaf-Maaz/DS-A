#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    int length;

public:
    LinkedList()
    {
        head = nullptr;
        length = 0;
    }

    int getLength()
    {
        return length;
    }

    void insert(int val, int position)
    {
        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input" << endl;
            return;
        }
        Node *n = new Node(val);

        if (position == 1)
        {
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

        Node *curr = head;

        if (position == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            Node *slow = nullptr;
            for (int i = 1; i < position; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            delete curr;
        }
        length--;
    }

    void printList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    Node *reverseKNodes(Node *current, int k, bool reverse)
    {
        if (current == nullptr || k == 1)
        {
            return current;
        }

        Node *next = nullptr;
        Node *prev = nullptr;
        int count = 0;

        // Reverse k nodes if 'reverse' is true, otherwise, keep them in order
        while (current != nullptr && count < k)
        {
            next = current->next;
            if (reverse)
            {
                current->next = prev;
            }
            prev = current;
            current = next;
            count++;
        }

        // If we are reversing, then the new head of this group is 'prev'
        // Otherwise, 'prev' is the last node of the group in its original order

        Node *newhead;
        if (reverse)
        {
            newhead = prev;
        }
        else
        {
            newhead = head;
        }

        // If 'reverse' is true, set the 'next' of the last node of the previous group to 'prev'
        if (reverse && prev != nullptr)
        {
            head->next = prev;
        }

        // Recursively process the next group
        if (next != nullptr)
        {
            // Reverse the next group and pass 'reverse' as false to keep it in order
            prev = reverseKNodes(next, k, !reverse); // i have learn this !reverse new thing due to AI tech...
        }

        return newhead;
    }

    // Public method to access the head
    Node *getHead()
    {
        return head;
    }
};

int main()
{
    LinkedList llist;

    llist.insert(1, 1);
    llist.insert(2, 2);
    llist.insert(3, 3);
    llist.insert(4, 4);
    llist.insert(5, 5);
    llist.insert(6, 6);
    llist.insert(7, 7);
    llist.insert(8, 8);
    llist.insert(9, 9);

    cout << "Given linked list:" << endl;
    llist.printList();

    int k = 3;
    Node *head = llist.reverseKNodes(llist.getHead(), k, true);

    cout << "\nReversed Linked list:" << endl;
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}