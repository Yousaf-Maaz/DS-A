// Tower of Hanoi - A Historical Challenge
// (Use iterative solution with an array-based stack)

// Background: The Tower of Hanoi is a classic puzzle that has its origins in an ancient city
// of Hanoi in Vietnam. According to an information, there was once a temple in Hanoi with
// three tall pegs (rods) and 64 gold disks of different sizes. These disks were said to represent
// the universe, and the monks in the temple were tasked with the challenge of moving the
// entire stack of disks from one peg to another, following three simple rules:
// • Only one disk can be moved at a time.
// • A disk can only be placed on top of a larger disk or an empty peg.
// • The monks must complete the task as quickly as possible.
// It has been said that the world would end when the monks successfully moved all the disks
// from one peg to another (just a fictitious story, nothing to do with reality).
// Your mission is to implement the Tower of Hanoi puzzle using C++ and the stack data
// structure. The puzzle will involve moving a specified number of disks from one peg (stack)
// to another, following the same rules:
// • You can only move one disk at a time.
// • A larger disk cannot be placed on top of a smaller one.
// • You must use an additional peg as an auxiliary rod to accomplish the task efficiently.
// Implement a C++ program that can solve the Tower of Hanoi puzzle for a specified number
// of disks (you can choose the number, e.g., 3, 4, or 5, etc). In your program the numbers
// will indicate the disk eg. In 3 disks. 1 is the smallest disk, 2 is larger than 1 and 3 is larger
// than both. When you move disk, show from which rod to which rod which disk was moved
// in console output.
// Your program should display the step-by-step sequence of moves required to solve the
// puzzle for the chosen number of disks, adhering to the three rules mentioned above. At the
// end, show that in how many moves, your program placed all of the disk to another stack.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack
{
    int *arr;
    int length;
    int capacity;
    int top;

public:
    Stack(int s)
    {
        capacity = s;
        length = 0;
        top = -1;
        arr = new int[capacity];
    }

    bool isFull()
    {
        return length == capacity;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow :)" << endl;
            return;
        }
        top++;
        arr[top] = val;
        length++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow " << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        length--;
        return value;
    }

    int peak()
    {
        if (isEmpty())
        {
            cout << "Stack underflow " << endl;
            return -1;
        }

        return arr[top];
    }

    ~Stack()
    {
        delete[] arr;
    }
};

class StackImplementation
{
    vector<Stack> rods;
    vector<string> rodNames = {"Rod 1", "Rod 2", "Rod 3"};

public:
    StackImplementation(int numRods, int capacity)
    {
        rods.resize(numRods, Stack(capacity));
    }

    void moveDisk(int a, int b)
    {
        if (!rods[a].isEmpty() && (rods[b].isEmpty() || rods[a].peak() < rods[b].peak()))
        {
            cout << "Move disk " << rods[a].peak() << " from " << rodNames[a] << " to " << rodNames[b] << "\n";
            rods[b].push(rods[a].pop());
        }
        else
            moveDisk(b, a);
    }

    void towerOfHanoi(int n)
    {
        cout << "Tower of Hanoi for " << n << " disks:\n";

        int totalMoves = (1 << n) - 1;
        int source, tempory, destinition;

        // Determine the order of rods based on the number of disks
        if (n % 2 == 0)
        {
            source = 0;
            tempory = 2;
            destinition = 1;
        }
        else
        {
            source = 0;
            tempory = 1;
            destinition = 2;
        }

        for (int i = n; i > 0; i--)
            rods[source].push(i);

        stack<pair<int, int>> moveStack;//simple pair of two elements
        for (int i = 1; i <= totalMoves; i++)
        {
            if (i % 3 == 1)
            {
                moveStack.push({source, destinition});
            }
            else if (i % 3 == 2)
            {
                moveStack.push({source, tempory});
            }
            else
            {
                moveStack.push({tempory, destinition});
            }
        }

        while (!moveStack.empty())
        {
            pair<int, int> move = moveStack.top();
            moveStack.pop();
            moveDisk(move.first, move.second);
        }
    }
};

int main()
{
    int numDisks;

    cout << "Enter The Number Of Disks: ";
    cin >> numDisks;

    StackImplementation stackImpl(3, 2 * numDisks); // The number of rods in the Tower of Hanoi problem
    // The capacity of the individual rods. It's given as 2 * numDisks,
    stackImpl.towerOfHanoi(numDisks);

    cout << "Total moves: " << (1 << numDisks) - 1 << endl;

    return 0;
}