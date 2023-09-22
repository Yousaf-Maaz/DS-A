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
            cout << "Lsit is full" << endl;
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

        tail();
        for (int i = length; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            back();
        }
        *(curr + 1) = val;
        length++;
    }

    void remove(int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Not possible at this position" << endl;
            return;
        }
        if (length == 0)
        {
            cout << "List is empty" << endl;
        }
        // start();
        curr = arr + pos - 1;
        for (int i = pos; i <= length; i++)
        {
            *curr = *(curr + 1);
            next();
        }
        length--;
    }

    void printlist()
    {
        if (length == 0)
        {
            cout << "List is empty" << endl;
        }
        start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr << " ";
            next();
        }
    }

    void Find_or_Search(int val)
    {
        if (length == 0)
        {
            cout << "List is empty" << endl;
            return; // Exit the function if the list is empty
        }

        start();
        for (int i = 0; i < length; i++)
        {
            if (*curr == val)
            {
                cout << "Value found at pos " << i + 1 << endl;
                return; // Exit the function when the value is found
            }
            next();
        }

        // If the loop completes and the value is not found, then print this message
        cout << val << " Value is not exist in the list" << endl;
    }

    void updated(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Not possible at this position" << endl;
            return;
        }
        if (length == 0)
        {
            cout << "List is empty" << endl;
        }
        curr = arr + pos - 1;
        *curr = val;
    }

    void copylist(Arraylist object1, Arraylist object2)
    {
        if (object1.length != object2.length)
        {
            cout << "Both ArrayLists must have the same length for copying." << endl;
            return;
        }

        object1.start(); // Assuming you have a start() method in your ArrayList class
        object2.start();

        for (int i = 0; i < object1.length; i++)
        {
            *object2.curr = *object1.curr;
            object1.curr++;
            object2.curr++;
        }

        cout << "The array is successfully copied." << endl;
        object2.start();
        for (int i = 0; i < object2.length; i++)
        {
            cout << *object2.curr << " ";
            object2.curr++;
        }
    }

    void sort_in_accessendingorder()
    {
        for (int i = 0; i < length; i++)
        {

            start();
            int *temp = curr + 1;
            for (int i = 0; i < length - 1; i++)
            {
                if (*temp < *curr)
                {
                    int a = *curr;
                    *curr = *temp;
                    *temp = a;
                }
                curr++;
                temp++;
            }
        }
        start();
        cout << "Array is succuessfully sorted in accending order" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << *curr << " " << endl;
            curr++;
        }
    }

    void reverse_list()
    {
        start();
        int s = length;
        int n = (length / 2);
        for (int i = 0; i < n; i++)
        {
            int temp = *curr;
            *curr = *(arr + (s - 1));
            *(arr + (s - 1)) = temp;
            curr++;
            s--;
        }
    }

 void Shift(int s)
    {
        int temp;
        if (s >= 0)
            for (int i = 0; i < s; i++)
            {
                tail();
                temp = *curr;
                for (int i = length; i > 1; i--)
                {
                    curr = (curr - 1);
                    back();
                }
                *curr = temp;
            }

        else
        {
            for (int i = 0; i < (-1 * s); i++)
            {
                start();
                temp = *curr;
                for (int i = 1; i < length; i++)
                {
                    curr = (curr + 1);
                    next();
                    *curr = temp;
                }
            }
        }
    }
};

int main()
{
    int s, s1;
    cout << "Enter size for array 1." << endl;
    cin >> s;
    Arraylist obj(s); // creating object of the class

    Arraylist obj1(s); // creating object of the class

    Arraylist obj2(0); // creating object of the class

    int input; // this will store the user choice

    do //  using this loop for creating menu driven program
    {
        cout << "Enter the option number.Press 0 to exit." << endl;
        cout << "1)InsertElementAt()" << endl;
        cout << "2)PrintList" << endl;

        cout << "3)SearchElement()" << endl;
        cout << "4)DeleteElement ()" << endl;
        cout << "5)ReverseList()" << endl;

        cout << "6)copyList()" << endl;
        cout << "7)sort()" << endl;
        // cout<<"13)compareList()"<<endl;

        cin >> input;

        switch (input)
        {

        case 1:
            int pos;
            int value;
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
            int val;
            // int position;
            cout << "Enter the value you want to search." << endl;
            cin >> val;
            obj.Find_or_Search(val);
            // cout<<"position = "<<position;
            // cout<<endl;
            break;

        case 4:
            int valll;
            // bool a;
            cout << "Enter the position you want to delete" << endl;
            cin >> valll;
            obj.remove(valll);
            // if(a)
            // {
            //     cout<<"Value is deleted"<<endl;
            // }
            // else
            // {
            //     cout<<"Value doesnot exist"<<endl;
            // }
            cout << endl;
            break;

        case 5:
            obj.reverse_list();
            cout << endl;
            break;

        case 6:
            obj.copylist(obj, obj1);
            cout << endl;
            break;

        case 7:
            obj.sort_in_accessendingorder();
            break;

            // case 13:
            // bool c;
            // c=obj.compareList(obj,obj2);
            // if(c)
            // {
            //     cout<<"Lists are same."<<endl;
            // }
            // else
            // {
            //     cout<<"Lists are not same."<<endl;
            // }
            // break;

        default:
            cout << "Enter correct option number." << endl;
            break;
        }
    } while (input != 0);

    return 0;
}
