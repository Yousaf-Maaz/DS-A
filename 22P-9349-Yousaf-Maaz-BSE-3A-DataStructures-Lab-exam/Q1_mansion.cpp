#include <iostream>
using namespace std;
class Node
{
public:
	string value;
	Node *next;
	Node(string val)
	{
		this->value = value;
		next = NULL;
	}
};
class Stack
{
public:
	Node *top;
	int size;
	int length;

	Stack(int size)
	{
		top = nullptr;
		this->size = size;
		length = 0;
	}
	~Stack()
	{
		while (!isEmpty())
		{
			pop();
		}
	}

	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
			cout << "Stack is empty(underflow)" << endl;
		}
		else
		{
			return false;
		}
	}

	bool isFull()
	{
		if (length == size)
		{
			return true;
			cout << "Stackoverflow" << endl;
		}
		else
		{
			return false;
		}
	}

	void push(string val)
	{

		if (!isFull())
		{
			Node *temp = new Node(val);
			temp->next = top;
			top = temp;
			length++;
		}
	}

	string pop()
	{

		if (!isEmpty())
		{
			Node *temporary = top;
			string val = top->value;
			top = top->next;
			delete temporary;
			length--;
			return val;
		}
		return '\0';
	}
	// display method for show at the end.
	void display()
	{
		if (!isEmpty())
		{
			cout << "Stack Encounters currently at:" << endl;
			Node *temp = top;
			while (temp != NULL)
			{
				cout << temp->value << endl;
				temp = temp->next;
			}
			cout << endl;
		}
	}
};

class Queue
{
	int front;
	int rear;
	int size;
	int length;
	string *arr;

public:
	Queue(int size)
	{
		front = -1;//we can also start from 0.
		rear = -1;
		length = 0;
		this->size = size;
		arr = new string[size];
	}
	bool isEmpty()
	{
		if (size == 0)
		{
			cout << "Queue Underflow \n";
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (size == length)
		{
			cout << "Queue  overflow\n ";
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(string val)
	{
		if (size == length)
		{
			cout << "Queue overflow" << endl;
			return;
		}

		rear = (rear + 1) % size;
		arr[rear] = val;
		length++;
	}

	string dequeue()
	{

		if (length == 0)
		{
			cout << "Queue underflow" << endl;
			return "";
		}

		string val = arr[front];
		front = (front + 1) % size;
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
};

int main()
{
	int choice;
	// Set up the stack for encounters
	Stack encounters(6);

	Queue mansionQueue(6);
	mansionQueue.enqueue("The Gateway to Darkness");
	mansionQueue.enqueue("The Creeping Corridor");
	mansionQueue.enqueue("The Abandoned Lounge");
	mansionQueue.enqueue("The Haunted Gallery");
	mansionQueue.enqueue("The Shadowed Library");
	mansionQueue.enqueue("The Broken Window");

	while (true)
	{
		cout << "Start exploring the mansion? " << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;
		if (choice == 1)
		{
			// encounters.push("The Gateway to Darkness");

			encounters.push("The Gateway to Darkness");
			encounters.display();
			encounters.pop();
			cout << "Did you encounter a ghost or an evil sprit? \n what did you see" << endl;
			int choice;

			
		}
		else
		{
			cout << "See you next time" << endl;
			return 0;
		}
	}
}
