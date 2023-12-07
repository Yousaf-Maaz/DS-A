// University Admission Queue System
// (Implement queue using linked list)

// You are tasked with designing a queue-based admission system for a FAST university.
// Each year, a large number of students apply for admission, and the admission process is
// managed by three admission officers. To ensure efficient processing, students will be
// directed to the shortest queue for document verification. In your program the student’s
// object should consist of the following info:
// • Student name
// • Student merit.
// So, in your program the Node class should contain the object of student as a data member.
// Create a menu-driven program that simulates the university admission queue system. The
// program should include the following menu options:
// 1. Add Student to Queue: This option allows you to add a new student to the shortest
// available queue for document verification. In case all the queues has the same
// number of students, so randomly enqueue in any of the queues.
// 2. Process Admissions: This option begins the admission processing. It will process
// admissions for each queue in a First-Come-First-Serve (FCFS) manner. Once the
// shortest queue is empty, the program will automatically start processing the next
// shortest queue. Make sure your queue is empty after that operation. You will process
// a student by checking his merit score, if greater than 50, he can secure his admission,
// else he cannot so just display a message accordingly on screen.
// 3. Check Queue Status: Display the current status of all three queues, including the
// number of students in each queue and their details.
// 4. See who is next: User can see who is the next student waiting in the specific queue
// (by entering the queue number).
// 5. Exit: Quit the program.



#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Student
{
public:
    string name;
    int merit;

    Student(string n, int m)
    {
        name = n;
        merit = m;
    }
};

class Node
{
public:
    Student data;
    Node *next;

    Node(Student s) : data(s), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(Student s)
    {
        Node *newNode = new Node(s);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Student dequeue()
    {
        if (isEmpty())
        {
            cerr << "Queue Underflow" << endl;
            return Student("", 0); // Return a dummy student when the queue is empty
        }
        Node *temp = front;
        front = front->next;
        Student data = temp->data;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return data;
    }

    int size()
    {
        int count = 0;
        Node *temp = front;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Student peakFront()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        return Student("", 0);
    }
};

class AdmissionSystem
{
private:
    Queue queues[3]; // three officer

public:
    void addStudentToQueue()
    {
        string name;
        int merit;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter student merit: ";
        cin >> merit;

        int shortestQueue = findShortestQueue();
        queues[shortestQueue].enqueue(Student(name, merit));

        cout << "Student added to Queue " << shortestQueue + 1 << endl;
    }

    void processAdmissions()
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << "Processing Queue " << i + 1 << ":\n";
            while (!queues[i].isEmpty())
            {
                Student currentStudent = queues[i].dequeue();
                cout << "Checking admission for student " << currentStudent.name << " with merit " << currentStudent.merit << "...\n";
                if (currentStudent.merit > 50)
                {
                    cout << "Admission granted!\n";
                }
                else
                {
                    cout << "Admission denied.\n";
                }
            }
        }
    }

    void checkQueueStatus()
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << "Queue " << i + 1 << " Status - Size: " << queues[i].size() << "\n";
            Student currentStudent = queues[i].peakFront();

            while (currentStudent.name != "")
            {
                cout << "Student: " << currentStudent.name << ", Merit: " << currentStudent.merit << "\n";
                queues[i].dequeue(); // Remove the processed student from the queue
                currentStudent = queues[i].peakFront();
            }
            cout << endl;
        }
    }

    void seeWhoIsNext()
    {
        cout << "Enter queue number to see the next student: ";
        int queueNumber;
        cin >> queueNumber;
        if (queueNumber >= 1 && queueNumber <= 3)
        {
            Student nextStudent = queues[queueNumber - 1].peakFront();
            if (nextStudent.name != "")
            {
                cout << "Next student in Queue " << queueNumber << ": " << nextStudent.name << ", Merit: " << nextStudent.merit << "\n";
            }
            else
            {
                cout << "Queue " << queueNumber << " is empty.\n";
            }
        }
        else
        {
            cout << "Invalid queue number.\n";
        }
    }

private:
    int findShortestQueue()
    {
        int shortest = 0;
        for (int i = 1; i < 3; ++i)
        {
            if (queues[i].size() < queues[shortest].size())
            {
                shortest = i;
            }
        }
        return shortest;
    }
};

int main()
{
    srand(time(0)); // for change the time
    AdmissionSystem admissionSystem;

    while (true)
    {
        cout << "\nMenu for Fast National university Peshawar Addimission Process :\n";
        cout << "-----------------------------------------------------\n";
        cout << "1. Add Student to Queue\n";
        cout << "2. Process Admissions\n";
        cout << "3. Check Queue Status\n";
        cout << "4. See who is next\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            admissionSystem.addStudentToQueue();
            break;
        case 2:
            admissionSystem.processAdmissions();
            break;
        case 3:
            admissionSystem.checkQueueStatus();
            break;
        case 4:
            admissionSystem.seeWhoIsNext();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice! .\n";
        }
    }

    return 0;
}
