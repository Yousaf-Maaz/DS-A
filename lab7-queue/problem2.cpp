#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    node *next;
    string data;
    node(string val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
private:
    node *rear;
    node *front;
    int length;

public:
    Queue()
    {
        front = nullptr;
        rear = NULL;
        length = 0;
    }
    int size()
    {
        return length;
    }
    bool isEmpty()
    {
        return length == 0; // Fix the isEmpty function
    }
    void enqueue(string val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
        length++;
    }
    string dequeue()
    {
        if (!front)
        {
            cout << "Queue Under Flow" << endl;
            return ""; // Return an empty string when the queue is empty
        }
        else
        {
            node *temp = front;
            front = front->next;
            length--;
            string data = temp->data;
            delete temp;
            return data;
        }
    }

    void display()
    {
        node *curr = front;
        while (curr != NULL)
        {
            cout << curr->data << "\t";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue visitor;
    Queue Rollercoaster;
    Queue Roundwheel;
    Queue motionride;

    while (true)
    {
        cout << "1. Enter a visitor in the purchase queue\n";
        cout << "2. Sell a ticket\n";
        cout << "3. Process all the queues\n";
        cout << "4. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter the name: ";
            cin.ignore();
            getline(cin, name);
            visitor.enqueue(name);
            break;
        }
        case 2:
        {

            string newvistor = visitor.dequeue();
            if (!newvistor.empty())
            {
                cout << "Selling ticket to: " << newvistor << endl;
                cout << "Choose attraction \n1 - Roller Coaster\n 2 - Round Wheel\n 3 - Motion Ride\n ";
                int attr_choice;
                cin >> attr_choice;

                switch (attr_choice)
                {
                case 1:
                    Rollercoaster.enqueue(newvistor);
                    break;
                case 2:
                    Roundwheel.enqueue(newvistor);
                    break;
                case 3:
                    motionride.enqueue(newvistor);
                    break;
                default:
                    cout << "Invalid attraction choice!" << endl;
                }
            }
            else
            {
                cout << "No visitors in the purchase queue." << endl;
            }
            break;
        }
        case 3:
        {

            cout << "Processing queues...\n";

            cout << "Roller Coaster Queue:\n";
            while (!Rollercoaster.isEmpty())
            {
                cout << Rollercoaster.dequeue() << " ";
            }
            cout << endl;

            cout << "Round Wheel Queue:\n";
            while (!Roundwheel.isEmpty())
            {
                cout << Roundwheel.dequeue() << " ";
            }
            cout << endl;

            cout << "Motion Ride Queue:\n";
            while (!motionride.isEmpty())
            {
                cout << motionride.dequeue() << " ";
            }
            cout << endl;
            break;
        }
        case 4:
            return 0;
            break;
        default:
            cout << "Invalid choice! Please choose a valid option.\n";
        }
    }

    return 0;
}
