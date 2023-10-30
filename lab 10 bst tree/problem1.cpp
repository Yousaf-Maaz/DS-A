#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Node
{
public:
    int power;
    string name;
    Node *right;
    Node *left;

    Node(int p, string n)
    {
        power = p;
        name = n;
        right = NULL;
        left = NULL;
    }
};

class BinarysearchTree
{
public:
    Node *root;

public:
    BinarysearchTree()
    {
        root = nullptr;
    }

    void preOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }

        cout << n->name << "\t";
        cout << n->power << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }

    void inOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }

        inOrder(n->left);
        cout << n->name << "\t";
        cout << n->power << "\t";
        inOrder(n->right);
    }

    void postOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }

        postOrder(n->left);
        postOrder(n->right);
        cout << n->name << "\t";
        cout << n->power << "\t";
    }

    Node *insert(Node *curr, string name, int power)
    {
        if (curr == nullptr)
        {
            return new Node(power, name);
        }

        else if (power < curr->power)
            curr->left = insert(curr->left, name, power);
        else
        {
            curr->right = insert(curr->right, name, power);
        }

        return curr;
    }
    Node *Getroot()
    {
        return root;
    }

    bool searchNode(Node *r, int val)
    {
        if (r == NULL)
            return false;

        else if (r->power == val)
            return true;

        else if (val < r->power)
            return searchNode(r->left, val);
        else
            return searchNode(r->right, val);
    }

    Node *findmaxium(Node *n)
    {
        if (n == NULL || n->right == nullptr)
        {
            return n;
        }

        return findmaxium(n->right);
    }

    Node *removeNode(Node *root, int power)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (power < root->power)
        {
            root->left = removeNode(root->left, power);
        }
        else if (power > root->power)
        {
            root->right = removeNode(root->right, power);
        }
        else
        {

            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = findmaxium(root->right);

            root->power = temp->power;
            root->name = temp->name;

            root->right = removeNode(root->right, temp->power);
        }

        return root;
    }

    void removeGem(int power)
    {
        root = removeNode(root, power);
    }
};

int main()
{
    BinarysearchTree magicalbag;
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Diamond", 50);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Ruby", 30);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Sapphire", 70);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Pearl", 40);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Opal", 10);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Garnet", 60);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Zircon", 20);
    magicalbag.root = magicalbag.insert(magicalbag.Getroot(), "Jade", 5);

    cout << "Welcome to the forest prince/ princess \n";

    int choice;
    int power;
    int X = 500;
    int Totalpower_in_bag_ = X;

    do
    {
        cout << "Menu:\n";
        cout << "1. Display the magical tree\n";
        cout << "2. Search for a gem by power\n";
        cout << "3. Find the gem with the highest magical power\n";
        cout << "4. Pluck (remove) a gem from the BST\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int traversalChoice;
            cout << "Select the traversal method:\n";
            cout << "1. Pre-order\n";
            cout << "2. In-order\n";
            cout << "3. Post-order\n";
            cout << "Enter your choice: ";
            cin >> traversalChoice;
            if (traversalChoice == 1)
            {
                cout << "Pre-order traversal:\n";
                magicalbag.preOrder(magicalbag.Getroot());
                cout << endl;
            }
            else if (traversalChoice == 2)
            {
                cout << "In-order traversal:\n";
                magicalbag.inOrder(magicalbag.Getroot());
                cout << endl;
            }
            else if (traversalChoice == 3)
            {
                cout << "Post-order traversal:\n";
                magicalbag.postOrder(magicalbag.Getroot());
                cout << endl;
            }
            else
            {
                cout << "Invalid choice for traversal.\n";
            }
        }
        break;

        case 2:
            cout << "Enter the power to search: ";
            cin >> power;
            if (magicalbag.searchNode(magicalbag.Getroot(), power))
            {
                cout << "Gem with power " << power << " found.\n";
            }
            else
            {
                cout << "Gem with power " << power << " not found.\n";
            }
            break;

        case 3:
        {
            Node *max = magicalbag.findmaxium(magicalbag.root);
            cout << "The max power element : \n";
            cout << max->power << " " << max->name << endl;
        }

        break;

        case 4:
        {
            int powerToRemove;
            cout << "Enter the power of the gem to remove: " << endl;
            cin >> powerToRemove;

            if (magicalbag.searchNode(magicalbag.Getroot(), powerToRemove))
            {
                magicalbag.removeGem(powerToRemove);
                cout << "Gem with power " << powerToRemove << " removed from the tree and put in your bag.\n";
                Totalpower_in_bag_ += powerToRemove;
                if (Totalpower_in_bag_ >= X)
                {
                    if (Totalpower_in_bag_ == X)
                    {
                        cout << "You won! Now take your bag and run from the forest.\n";
                    }
                    else
                    {
                        cout << "You lost! Your bag burst. Now run and save yourself from the witch.\n";
                    }
                    return 0;
                }
            }

            else
            {
                cout << "Gem with power " << powerToRemove << " not found in the tree.\n";
            }
        }
        break;

        case 5:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}