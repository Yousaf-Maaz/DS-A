#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    string song;
    node *next;

    node(string val)
    {
        song = val;
        next = nullptr;
    }
};

class Songlist
{
private:
    node *head;
    int length;

public:
    Songlist()
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
        node *n = new node(val);
        node *curr=head;
        if (position < 1 || position > length + 1)
        {
            cout << "Invalid input" << endl;
            return;
        }
        if (head == nullptr)
    {
       
        head = n;
        head->next = head;
    }
    else if (position == 1)
    {
       n->next=head;
       while(curr->next!=head)
        curr=curr->next;
        curr->next=n;
        head=n;
    }
    else
    {
        node *curr = head;
        for (int i = 1; i < position - 1; i++)
        {
            curr = curr->next;
        }
        curr->next = curr->next;
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
        node *temp=head;

        if (position == 1)
        {
            while (temp->next!=head)
            {
                temp->next=head;/* code */
            }
            
            head = head->next;
            temp->next=head;
            if(head->next==head)
            {
                head=nullptr;
            }
            delete curr;
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
            delete curr;
        }
        length--;
    }

    int search(string val)
    {
        if (head == nullptr || length == 0)
        {
            cout << "Empty" << endl;
            return 0;
        }

        node *curr = head;

        for (int i = 1; i <= length; i++)
        {
            if (curr->song == val)
            {
                return i;
            }
            curr = curr->next;
        }

        return 0;
    }

    void update(string val, int position)
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

        curr->song = val;
    }

    void printList()
    {
        //node *curr = head;
        node *curr = nullptr;
        while (curr->next != head)
        {
            if(curr==nullptr)
            curr=head;
            cout << curr->song << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    string getSong(int position)
    {
        if (position < 1 || position > length)
        {
            cout << "Invalid input" << endl;
            return "";
        }

        node *curr = head;
        for (int i = 1; i < position; i++)
        {
            curr = curr->next;
        }
        return curr->song;
    }
 ~Songlist()
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
    Songlist listofsong;

    while (true)
    {
        cout << "-------------------------------------------------\n";
        cout << "Menu:" << endl;
        cout << "1. Add a Song" << endl;
        cout << "2. Delete a Song" << endl;
        cout << "3. Search for a Song" << endl;
        cout << "4. Update a Song" << endl;
        cout << "5. Print Playlist" << endl;
        cout << "6. Play Song" << endl;
        cout << "7. Exit" << endl;
        cout << "-------------------------------------------------\n";

        int choice;
        cout << "-------------------------------------------------\n";
        cout << "Enter your choice: ";
        cout << "\n-------------------------------------------------\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string songName;
            cout << "Enter the name of the song: ";
            cin.ignore();
            getline(cin, songName);

            cout << "Select the favorite level:" << endl;
            cout << "1. Top Favorite" << endl;
            cout << "2. Least Favorite" << endl;
            cout << "3. Somewhere Between" << endl;

            int favoriteType;
            cout << "Enter your choice: ";
            cin >> favoriteType;

            if (favoriteType == 1)
                listofsong.insert(songName, 1);
            else if (favoriteType == 2)
                listofsong.insert(songName, listofsong.getLength() + 1);
            else if (favoriteType == 3)
            {
                int songselection;
                cout << "Enter the song where you want to add(like somehere between) (1 to " << listofsong.getLength() + 1 << "): ";
                cin >> songselection;
                listofsong.insert(songName, songselection);
            }
            else
                cout << "Invalid choice!" << endl;

            listofsong.printList();
            break;
        }
        case 2:
        {
            int position;
            cout << "Enter the position of the song you want to delete: ";
            cin >> position;
            listofsong.remove(position);
            listofsong.printList();
            break;
        }
        case 3:
        {
            string songName;
            cout << "Enter the name of the song you want to search: ";
            cin.ignore();
            getline(cin, songName);

            int position = listofsong.search(songName);
            if (position > 0)
            {
                cout << "Song found at position " << position << ": " << listofsong.getSong(position) << endl;
            }
            else
            {
                cout << "Song not found." << endl;
            }
            break;
        }
        case 4:
        {
            int position;
            cout << "Enter the position of the song you want to update: ";
            cin >> position;

            string newSongName;
            cout << "Enter the new name for the song: ";
            cin.ignore();
            getline(cin, newSongName);

            listofsong.update(newSongName, position);
            listofsong.printList();
            break;
        }
        case 5:
            cout << "Current Playlist:" << endl;
            listofsong.printList();
            break;
        case 6:
        {
            if (listofsong.getLength() == 0)
            {
                cout << "Playlist is empty." << endl;
            }
            else
            {
                cout << "Playing the first song: " << listofsong.getSong(1) << endl;

                                cout << "Enter the level (1-" << listofsong.getLength() << ") to play next: ";
                int numberyouwant;
                cin >> numberyouwant;

                if (numberyouwant < 1 || numberyouwant > listofsong.getLength())
                {
                    cout << "Invalid level." << endl;
                }
                else
                {
                    cout << "Playing song at level " << numberyouwant << ": " << listofsong.getSong(numberyouwant) << endl;
                }
            }
            break;
        }

        case 7:
            cout << "Program end " << endl;
            cout << "-------------------------------------------------\n";
            exit(0);
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
