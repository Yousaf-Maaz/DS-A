// Books Management System for a Digital Library

// (Double Linked List)

// You are part of a development team, tasked with building a book management system for
// a digital library. The system is expected to handle a vast collection of digital books, and it
// should provide a user-friendly interface with menu-driven options to perform various
// operations. Each book has attributes such as ISBN_Num number, author, title, genre, and
// publication date (Make a date class in your program to handle dates).
// The system should have a user-friendly menu-driven interface with options for different
// operations. Users should be able to navigate through the following menu items:
// 1. Add a New Book: Users can input book details (ISBN_Num number, author, title, genre,
// and publication date), and the book will be added to the linked list. When inserting
// a new book, maintain the order of the books, i-e books must be sorted according to
// the publication date. Decide where to insert at the time of insertion.
// 2. Search for a book: Using ISBN_Num no or name.
// 3. Display Books: Simple display the linked list.
// 4. Filter Books by Author: Users can input an author's name, and the system should
// display all books by that author.
// 5. Recommend Related Books: Input a book name, and provide max 3
// recommendations for similar books (hint: display books of the same genre).
// 6. Delete a Book: Using it’s ISBN_Num number.

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
};

class node
{
public:
    int ISBN_Num;
    string title;
    string author;
    string genre;
    Date publicationDate;
    node *next;
    node *previous;

    node(int ISBN, string t, string a, string g, Date date)
    {
        ISBN_Num = ISBN;
        title = t;
        author = a;
        genre = g;
        publicationDate = date;
        next = NULL;
        previous = NULL;
    }
};

class BookManagementSystem
{
private:
    node *head;

public:
    BookManagementSystem()
    {
        head = NULL;
    }

    ~BookManagementSystem()
    {
        // Destructor
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addBook(int ISBN_Num, string title, string author, string genre, Date publicationDate)
    {
        node *newNode = new node(ISBN_Num, title, author, genre, publicationDate);

        if (head == NULL || head->publicationDate.year > publicationDate.year ||
            (head->publicationDate.year == publicationDate.year && head->publicationDate.month > publicationDate.month) ||
            (head->publicationDate.year == publicationDate.year && head->publicationDate.month == publicationDate.month && head->publicationDate.day > publicationDate.day))
        {
            newNode->next = head;
            if (head)
            {
                head->previous = newNode;
            }
            head = newNode;
        }
        else
        {
            node *current = head;
            while (current->next != NULL &&
                   (current->next->publicationDate.year < publicationDate.year ||
                    (current->next->publicationDate.year == publicationDate.year &&
                     (current->next->publicationDate.month < publicationDate.month ||
                      (current->next->publicationDate.month == publicationDate.month &&
                       current->next->publicationDate.day < publicationDate.day)))))
            {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->previous = current;
            if (current->next != NULL)
            {
                current->next->previous = newNode;
            }
            current->next = newNode;
        }
    }

    node *searchBook(int key, bool byISBN = true)
    {
        node *current = head;
        while (current != NULL)
        {
            if ((byISBN && current->ISBN_Num == key) || (!byISBN && current->title == to_string(key)))
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    void displayBooks()
    {
        node *curr = head;
        cout << "Books Available:" << endl;
        while (curr != NULL)
        {
            cout << "ISBN_Num: " << curr->ISBN_Num << "  Title: " << curr->title << "  Author: " << curr->author << "  Genre: " << curr->genre << " Publication Date: " << curr->publicationDate.day << "/" << curr->publicationDate.month << "/" << curr->publicationDate.year << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void FilterBooksbyauthorname(string author)
    {
        node *current = head;
        bool check = false;
        cout << "Books Related to the search '" << author << "':" << endl;
        while (current != NULL)
        {
            if (current->author == author)
            {
                cout << "ISBN_Num: " << current->ISBN_Num << "  Title: " << current->title << "  Genre: " << current->genre << " | Publication Date: " << current->publicationDate.day << "/" << current->publicationDate.month << "/" << current->publicationDate.year << endl;
                check = true;
            }
            current = current->next;
        }
        if (!check)
        {
            cout << "No Books Found By this Author " << author << " " << endl;
        }
        cout << endl;
    }

    void recommendBooks(string bookTitle)
    {
        node *curr = head;
        bool check = false;
        while (curr != NULL)
        {
            if (curr->title == bookTitle)
            {
                check = true;
                break;
            }
            curr = curr->next;
        }

        if (check)
        {
            curr = head;
            int count = 0;
            cout << "Recommended Books Based on genre:" << endl;
            while (curr != NULL && count < 3)
            {
                if (curr->genre == bookTitle && curr->title != bookTitle)
                {
                    cout << "ISBN_Num: " << curr->ISBN_Num << " Title: " << curr->title << " Author: " << curr->author << " Genre: " << curr->genre << "  Publication Date: " << curr->publicationDate.day << "-" << curr->publicationDate.month << "-" << curr->publicationDate.year << endl;
                    count++;
                }
                curr = curr->next;
            }

            if (count == 0)
            {
                cout << "No recommendations available." << endl;
            }
        }
        else
        {
            cout << "Book Not Found." << endl;
        }
        cout << endl;
    }

    void deleteBook(int ISBN_Num)
    {
        node *curr = head;

        while (curr != NULL)
        {
            if (curr->ISBN_Num == ISBN_Num)
            {
                if (curr->previous != NULL)
                {
                    curr->previous->next = curr->next;
                }
                else
                {
                    head = curr->next;
                }

                if (curr->next != NULL)
                {
                    curr->next->previous = curr->previous;
                }

                delete curr;
                cout << "Book with ISBN_Num " << ISBN_Num << " Deleted Successfully." << endl;
                return;
            }
            curr = curr->next;
        }

        cout << "Book with ISBN_Num " << ISBN_Num << " Not Found." << endl;
    }
};

int main()
{
    BookManagementSystem DigitalLibrary;

    int choice;
    do
    {
        cout << endl
             << "-------------------------Digital Library-------------------" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "1. Add a New Book" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "2. Search for a Book" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "3. Display Books" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "4. Filter Books by Author" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "5. Recommend Related Books" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "6. Delete a Book" << endl;
        cout << "\n------------------------------------------------------\n";
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ISBN_Num;
            string title, author, genre;
            Date publicationDate;

            cout << "Enter ISBN_Num: ";
            cin >> ISBN_Num;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Genre: ";
            getline(cin, genre);

            cout << "Enter Publication Date (Day Month Year e:g(01 12 2020)): ";
            cin >> publicationDate.day >> publicationDate.month >> publicationDate.year;

            DigitalLibrary.addBook(ISBN_Num, title, author, genre, publicationDate);
            cout << "Book Added Successfully!" << endl;

            cin.ignore();
            break;
        }
        case 2:
        {
            int forsearch;
            cout << "Enter Book ISBN_Num or Title to Search: ";
            cin >> forsearch;

            node *result = DigitalLibrary.searchBook(forsearch, isdigit(to_string(forsearch)[0])); // here the logic Convert to String
            if (result != NULL)
            {
                cout << "Book Found:" << endl;
                cout << "ISBN_Num: " << result->ISBN_Num << "  Title: " << result->title << " Author: " << result->author << "Genre: " << result->genre << " | Publication Date: " << result->publicationDate.day << "/" << result->publicationDate.month << "/" << result->publicationDate.year << endl;
            }
            else
            {
                cout << "Book Not Found." << endl;
            }

            break;
        }
        case 3:
        {
            DigitalLibrary.displayBooks();
            break;
        }
        case 4:
        {
            string author;
            cout << "Enter Author Name: ";
            cin.ignore();
            getline(cin, author);
            DigitalLibrary.FilterBooksbyauthorname(author);
            break;
        }
        case 5:
        {
            string bookTitle;
            cout << "Enter The Title Of The Book: ";
            cin.ignore();
            getline(cin, bookTitle);
            DigitalLibrary.recommendBooks(bookTitle);
            break;
        }
        case 6:
        {
            int ISBN_Num;
            cout << "Enter the ISBN_Num of The Book To Delete: ";
            cin >> ISBN_Num;
            DigitalLibrary.deleteBook(ISBN_Num);
            break;
        }
        case 7:
        {
            cout << "BYE BYE. " << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    } while (choice != 7);

    return 0;
}
