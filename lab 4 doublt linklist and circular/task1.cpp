/*
Scenario: You are tasked with developing a basic to-do list application. Users should be able to
add tasks to their list, along with their priority, mark tasks as completed, and remove completed
tasks. The application will be implemented using a doubly linked list data structure to manage
tasks.
Menu Options:
• Add Task: Allow users to add a new task to their to-do list, along with the priority level.
Priority level is simply the position where you want to insert in the list. By default the task
is not completed so it’s completion status is false.
• Mark as Completed: Let users mark a task as completed when they have finished it. So
display the list of tasks and user will mark any task as completed, so the Boolean variable
completed will become true.
• Remove Completed Tasks: Allow users to remove all completed tasks from the list.
• Display Tasks: Display the current list of tasks, showing their completion status. User
should be prompted to display tasks in which order. Forward or reserve. The display the
tasks accordingly. Each task in the doubly linked list will have a description (string), a
completed flag (boolean), a next pointer (pointing to the next task), and a prev pointer
(pointing to the previous task).
• Implement the destructor as well.
*/






#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string learning;
    node *next;
    node *pervious;
    bool taskstatus;

    node(string val)
    {
        learning = val;
        next = nullptr;
        pervious = nullptr;
        taskstatus = false;
    }
};

class taskcomplete
{
private:
    node *head;
    int length;

public:
    taskcomplete()
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
        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input" << endl;
            return;
        }
        node *n = new node(val);

        if (position == 1)
        {
            n->next = head;
            head = n;
        }
        if (head != nullptr)
        {
            head->pervious = n;
            head = n;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            // n->next = curr->next;
            // curr->next = n;
            n->pervious = curr;
            n->next = curr->next;

            if (curr->next != nullptr)
            {
                curr->next->pervious = n;
            }
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

        node *curr = head;

        if (position == 1)
        {
            head = head->next;
            delete curr;
            if (head != NULL)
            {
                head->pervious = NULL;
            }
        }
        else
        {
            node *slow = nullptr;
            for (int i = 1; i < position; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            if (curr->next != NULL)
            {
                curr->next->pervious = slow;
            }
            delete curr;
        }
        length--;
    }

    // int search(string val)
    // {
    //     if (head == nullptr || length == 0)
    //     {
    //         cout << "Empty" << endl;
    //         return 0;
    //     }

    //     node *curr = head;

    //     for (int i = 1; i <= length; i++)
    //     {
    //         if (curr->learning == val)
    //         {
    //             return i;
    //         }
    //         curr = curr->next;
    //     }

    //     return 0;
    // }

    // void update(string val, int position)
    // {
    //     if (length == 0)
    //     {
    //         cout << "Empty" << endl;
    //         return;
    //     }

    //     if (position < 1 || position > length)
    //     {
    //         cout << "Invalid input" << endl;
    //         return;
    //     }

    //     node *curr = head;

    //     for (int i = 1; i < position; i++)
    //     {
    //         curr = curr->next;
    //     }

    //     curr->learning = val;
    // }

    // void printList()
    // {
    //     node *curr = head;
    //     while (curr != nullptr)
    //     {
    //         cout << curr->learning << " ";
    //         curr = curr->next;
    //     }
    //     cout << endl;
    // }

    void printList(int value)
    {
        if (head == nullptr || length == 0)
        {
            cout << "Empty" << endl;
            return;
        }
        node *curr = head;
        if (value == 1)
        {
            for (int i = 0; i < length; i++)
            {
                cout << curr->learning << " ";
                curr = curr->next;
                cout<<"";
            }

            if (value == 2)
            {
                for (int i = 0; i < length; i++)
                {
                    curr = curr->next;
                }
                do
                {
                    cout << curr->learning << " ";
                    curr = curr->next;
                } while (curr != head);
                cout << endl;
            }
        }

        // do
        // {
        //     cout << curr->learning << " ";
        //     curr = curr->next;
        // } while (curr != head);
        // cout << endl;
        //         node *curr = head;
        // for (int i=0; curr != head; curr = curr->next)
        // {
        //     cout << curr->learning << " ";
        // }
        // cout << endl;
    }

    // string getSong(int position)
    // {
    //     if (position < 1 || position > length)
    //     {
    //         cout << "Invalid input" << endl;
    //         return "";
    //     }

    //     node *curr = head;
    //     for (int i = 1; i < position; i++)
    //     {
    //         curr = curr->next;
    //     }
    //     return curr->learning;
    //}

    void confrimation(int position)
    {
        if (length == 0)
        {
            cout << "Empty" << endl;
            return;
        }

        if (position < 1 || position > length)
        {
            cout << "Invalid input" << endl;
            return;
        }

        node *curr = head;

        for (int i = 1; i < position; i++)
        {
            curr = curr->next;
        }

        curr->taskstatus = true;
        cout << "task  mark as a completed" << endl;
    }
    ~taskcomplete()
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
    taskcomplete Timetable;
    int count = 0;

    while (true)
    {
        cout << "1. Add Task" << endl;
        cout << "2. Mark as Completed" << endl;
        cout << "3. Remove Completed Tasks" << endl;
        cout << "4. Display Tasks" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline character from the buffer

        switch (choice)
        {
        case 1:
        {
            string task;
            cout << "Enter the description of the task: ";
            getline(cin, task);
            int level;
            cout << "Select the priority level: ";
            cin >> level;
            Timetable.insert(task, level);
            count++;
            Timetable.printList(count);
            break;
        }
        case 2:
        {
            int position;
            cout << "Enter the position of the task you want to mark as complete: ";
            cin >> position;
            Timetable.confrimation(position);
            break;
        }
        case 3:
        {
            Timetable.remove(count);
            Timetable.printList(count);
            break;
        }
        case 4:
        {
            cout << "Display tasks in forward or reverse order?" << endl;
            cout << "1. Forward" << endl;
            cout << "2. Reverse" << endl;
            int check;
            cout << "Enter your choice: ";
            cin >> check;
            switch (check)
            {
            case 1:
                Timetable.printList(1);
                break;
            case 2:
                Timetable.printList(2);
                break;
            default:
                cout << "Invalid choice for display order." << endl;
            }
            break;
        }
        case 5:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
        }
    }
}