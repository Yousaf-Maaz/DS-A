#include <iostream>

using namespace std;

class Arraylist
{
public:
    int *arr;
    int *curr;
    int length;
    int size;

public:
    // constructor
    Arraylist(int s)
    {
        arr = new int[s];
        size = s;
        length = 0;
    }
    // destructor
    ~Arraylist()
    {
        delete[] arr;
    }
    // pointing at start 1
    void start()
    {
        curr = arr;
    }
    // pointing at end
    void tail()
    {
        curr = arr + (length - 1);
    }
    // back the pointer
    void back()
    {
        curr--;
    }
    // move the pointer in forward
    void next()
    {
        curr++;
    }

    // now towards insert methods

    void insert(int val, int pos)
    {
        if (length == size)
        {
            cout << "List is full" << endl;
            return;
        }

        // logic for insert at first position is

        if (pos < 1 || pos > length + 1)
        {
            cout << "Not possible at this position" << endl;
            return;
        }
        if (pos == 1) // if the array is empty and the position is 1
        {
            curr = arr;
            *curr = val;
        }
        else
        {
            tail();
            for (int i = length; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                back();
            }
            *(curr + 1) = val;
        }
        length++;
    }

    void rearrangeList()
    {
        int temp;
        int *ptr = arr;

        while (ptr < (arr - 1) + length)
        {
            if (*ptr % 2 != 0)
            {
                temp = *ptr;
                *ptr = *(ptr + 1);
                *(ptr + 1) = temp;
                ptr += 2;
            }
            else
            {
                ptr++;
            }
        }
    }

    void printlist()
    {
        if (length == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }
};

int main()
{
    int s;
    cout << "Enter size for array." << endl;
    cin >> s;
    Arraylist obj(s); // creating object of the class

    int input; // this will store the user's choice

    do
    {
        cout << "Enter the option number. Press 0 to exit." << endl;
        cout << "1) InsertElementAt()" << endl;
        cout << "2) PrintList" << endl;

        cout << "3) RearrangeList()" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            int pos, value;
            cout << "Enter the position" << endl;
            cin >> pos;
            cout << "Enter the value" << endl;
            cin >> value;
            obj.insert(value, pos);
            cout << endl;
            break;

        case 2:
            obj.printlist();
            cout << endl;
            break;

        case 3:
            obj.rearrangeList();
            cout << "Array rearranged." << endl;
            break;

        default:
            cout << "Enter correct option number." << endl;
            break;
        }
    } while (input != 0);

    return 0;
}
