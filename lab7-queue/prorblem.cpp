// #include <iostream>
// #include <string>
// using namespace std;
// class Queue
// {
// private:
//     string *arr;
//     int length;
//     int front;
//     int rear;
//     int capacity;

// public:
//     Queue(int size)
//     {
//         capacity = size;
//         arr = new string[size];
//         int front = 0;
//         int length = 0;
//         int rear = -1;
//     }
//     void Enqueue(string val)
//     {
//         if (length == capacity)
//         {
//             cout << "Queue overflow" << endl;
//             return;
//         }
//         if (rear == (capacity - 1))
//         {
//             rear = 0;
//         }
//         else
//         {
//             rear++;
//         }
//         arr[rear] = val;
//         length++;
//     }
//     void Dequeue()
//     {
//         if (length == 0)
//         {
//             cout << "Queue underflow" << endl;
//             return;
//         }
//         // char  val=arr[front];
//         if (front == (capacity - 1))
//         {
//             front = 0;
//         }
//         else
//         {
//             front++;
//         }
//         length--;
//         // return val;
//     }

//     string getFront()
//     {
//         if (length != 0)
//         {
//             // cout << "Patient: " << arr[front] << "Is with doctor...." << endl;
//             // cout<< arr[front];
//             return arr[front];
//         }
//         else
//         {
//             cout << "Queue is empty or under flow " << endl;
//         }
//     }

//     void Display()
//     {
//         if (length == 0)
//         {
//             cout << "Queue is underflow" << endl;
//             return;
//         }

//         {
//             int index = front;
//             for (int i = 1; i < length; i++)
//             {
//                 cout << arr[index] << " ";
//                 index = (index + 1) % capacity;
//             }
//             cout << endl;
//         }

//         {
//             cout << "queue is empty" << endl;
//         }
//     }
// };
// int main()
// {
//     int Number;
//     cout << "Enter the number of seat in waiting area\n";
//     cin >> Number;

//     Queue Patient(Number);

//     int choice;

//     while (true)
//     {
//         cout << "1.Enter a patient in waiting Queue.\n";
//         cout << "2.send the next patient to the doctors.\n";
//         cout << "3.see who is the next.\n";
//         cout << "4.Display all the patient.\n";
//         cout << "5.exit\n";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//         {
//             string val;
//             cin.ignore();
//             cout<<"Enter the name\n";
//             getline(cin, val);
//             Patient.Enqueue(val);
//             cout << "Patient:" << val << "Is now waiting......" << endl;
//         }
//         case 2:
//         {
//             // Patient.getFront();
//             cout << "Patient: " << Patient.getFront() << "Is with doctor...." << endl;
//             Patient.Dequeue();
//         }
//         case 3:
//         {
//             cout << " Next Patient is :" << Patient.getFront();
//         }
//         case 4:
//         {
//             Patient.Display();
//         }
//         case 5:
//         {
//             return 0;
//         }
//         }
//     }

//     return 0;
// }
#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    string *arr;
    int length;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new string[size];
        front = 0;
        length = 0;
        rear = -1;
    }

    void Enqueue(string val)
    {
        if (length == capacity)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = val;
        length++;
    }

    string Dequeue()
    {
        if (length == 0)
        {
            cout << "Queue underflow" << endl;
            return "";
        }

        string val = arr[front];
        front = (front + 1) % capacity;
        length--;

        return val;
    }

    string getFront()
    {
        if (length == 0)
        {
            cout << "Queue is empty or under flow " << endl;
            return "";
        }

        return arr[front];
    }

    void Display()
    {
        if (length == 0)
        {
            cout << "Queue is underflow" << endl;
            return;
        }

        int index = front;
        for (int i = 0; i < length; i++)
        {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    int number;
    cout << "Enter the number of seat in waiting area\n";
    cin >> number;

    Queue Patient(number);

    int choice;

    while (true)
    {
        cout << "1.Enter a patient in waiting Queue.\n";
        cout << "2.send the next patient to the doctors.\n";
        cout << "3.see who is the next.\n";
        cout << "4.Display all the patient.\n";
        cout << "5.exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string val;
            cout << "Enter the name\n";
            cin.ignore();
            getline(cin, val);
            Patient.Enqueue(val);
            cout << "Patient:" << val << "Is now waiting......" << endl;
            break;
        }
        case 2:
        {
            string val = Patient.Dequeue();
            if (val != "")
            {
                cout << "Patient: " << val << "Is with doctor...." << endl;
            }
            break;
        }
        case 3:
        {
            string val = Patient.getFront();
            if (val != "")
            {
                cout << " Next Patient is :" << val;
            }
            cout << endl;
            break;
        }
        case 4:
        {
            Patient.Display();
            break;
        }
        case 5:
        {
            return 0;
            break;
        }
        }
    }

    return 0;
}