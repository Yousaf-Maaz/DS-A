#include <iostream>
#include <string>
using namespace std;

int main()
{
    string letters;
    while (true)
    {
        cout << "(1) Check if the string is a palindrome" << endl;
        cout << "(2) Check the frequency of a certain character" << endl;
        cout << "(3) Exit" << endl;
        char choose;
        cout << "Enter what you want to do: ";
        cin >> choose;

        switch (choose)
        {
        case '1':
        {
            cout << "Enter the string: ";
            cin.ignore();
            getline(cin, letters);

            int length = letters.length();
            char *first = &letters[0];
            char *last = &letters[length - 1];

            while (first < last)
            {
                if (*first != *last)
                {
                    cout << "Not a palindrome" << endl;
                    break;
                }
                ++first;
                --last;
            }

            if (first >= last)
            {
                cout << "Yes, the word is a palindrome" << endl;
            }
            break;
        }
        case '2':
        {
            cout << "Enter the string: ";
            cin.ignore();
            getline(cin, letters);

            cout << "Enter the character which you want to find the frequency: ";
            char check;
            cin >> check;

            int count = 0;
            for (int i = 0; i < letters.size(); i++)
            {
                if (letters[i] == check)
                {
                    ++count;
                }
            }

            cout << "Number of " << check << " : " << count << endl;
            break;
        }
        case '3':
            cout << "Ended" << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
