/*
Create a menu-driven music playlist manager program using a singly linked list to manage your
favorite songs. Each song in the playlist will have a name.
The program should offer the following options:
• Add a Song: When the user adds a song, the program should ask the name of the song,
after that the user will be prompted to specify its "favorite level." They can choose from
the following options:
1. (Top Favorite): The song will be inserted at the beginning of the playlist.
2. (Lease Favorite): The song will be inserted at the end of the playlist.
3. Somewhere between (let me specify the number): If the user selects a custom
favorite level (e.g., 2 to 4), the program will display valid priority levels based
on the current number of songs in the playlist (e.g., 2 to 5 for a playlist of 5
songs). The song will be inserted at the specified custom priority position.
• Delete a Song: Users can remove a song from the playlist by entering its name/ position
(depends on you).
• Search for a Song: Users can search for a song by its name and display the name and
level of how much favorite it is.
• Update a song name: Thie function will take the song number, and the new name, and
update the song name on that position.
• Print Playlist: This option will display the entire playlist with song names.
• Play Song: Users can start playing songs from the beginning of the playlist. When the
user clicks on Play Song, play the first song in the list. After that the user can select the
option of play next song, so the program will play the next song from the list (just a
simulation by displaying the song name.
• Exit: Exit the program.
Note: After each insertion, update, or removal operation, print the playlist. Your program
should have all the checks for invalid input. The update song option is not showed in the
sample output, but you must implement it in your code, and display the menu accordingly.
*/

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
        else
        {
            node *curr = head;
            for (int i = 1; i < position - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
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
        node *curr = head;
        while (curr != nullptr)
        {
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
