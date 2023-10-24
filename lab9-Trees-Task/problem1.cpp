#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = nullptr;
    }

    void preOrder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }

        cout << n->val << "\t";
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
        cout << n->val << "\t";
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
        cout << n->val << "\t";
    }
    Node *Search(Node *root, int value)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root->val == value)
        {
            return root;
        }
        else
        {
            Node *n;
            n = Search(root->left, value);

            if (n != nullptr)
            {
                return n;
            }
            else
            {
                n = Search(root->right, value);

                if (n != nullptr)
                {
                    return n;
                }
            }
        }
    }

    void setleft(Node *n, int val)
    {
        Node *temp = new Node(val);
        n->left = temp;
    }

    void setRight(Node *n, int val)
    {
        Node *temp = new Node(val);
        n->right = temp;
    }

    void insert(int value, bool left, int par)
    {
        if (root == nullptr)
        {
            root = new Node(par);
        }
        Node *n = Search(root, par);
        if (left)
        {
            setleft(n, value);
        }
        else
        {
            setRight(n, value);
        }
    }
    int maxDepth(Node *n)
    {
        if (n == NULL)
            return -1;
        else
        {

            int leftDepth = maxDepth(n->left);
            int rightDepth = maxDepth(n->right);

            if (leftDepth > rightDepth)
                return (leftDepth + 1);
            else
                return (rightDepth + 1);
        }
    }
    void deleteTree(Node *leaf)
    {
        if (leaf != NULL)
        {
            deleteTree(leaf->left);
            deleteTree(leaf->right);
            delete leaf;
        }
    }

    int checklevel(Node *par, Node *n, int level)
    {
        if (par == NULL)
            return 0;
        if (par == n)
            return level;

        int left = checklevel(par->left, n, level + 1);
        int right = checklevel(par->right, n, level + 1);

        if (left == 0)
            return right;
        else if (right == 0)
            return left;
        else
            return 0;
    }
    Node *Getroot()
    {
        return root;
    }
};

int main()
{
    Tree t;

    while (1)
    {
        cout << "Select any choice\n";
        cout << "1.Insert in the tree\n";
        cout << "2.Traverse the tree:\n";
        cout << "3.Find the depth of the tree\n";
        cout << "4.Find the level of a specific node\n";
        cout << "5.Search in the tree\n";
        cout << "6.Delete the tree\n";
        cout << "7.Exit\n";

        int choice;
        cout << "Enter the option\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            int par;
            int count = 0;
            cout << "Enter the value to insert\n";
            cin >> data;

            cout << "Enter the value of the root node\n";
            cin >> par;
            cout << "Do you want to insert on the left or right?\n";
            cout << "1.Left\n";
            cout << "2.Right\n";
            cin >> choice;
            if (choice == 1)
            {
                t.insert(data, true, par);
            }
            else if (choice == 2)
            {
                t.insert(data, false, par);
            }
            break;
        }
        case 2:
        {
            cout << "1.PreOrder" << endl;
            cout << "2.InOrder" << endl;
            cout << "3.Postorder" << endl;

            cin >> choice;
            if (choice == 1)
            {
                t.preOrder(t.Getroot());
            }
            else if (choice == 2)
            {
                t.inOrder(t.Getroot());
            }
            else if (choice == 3)
            {
                t.postOrder(t.Getroot());
            }
            break;
        }
        case 3:
        {
            cout << "The depth of the tree is: " << t.maxDepth(t.Getroot()) << endl;
            break;
        }
        case 4:
        {
            int value;
            cout << "Enter the value of the specific node to find its level\n";
            cin >> value;
            int level = t.checklevel(t.Getroot(), t.Search(t.Getroot(), value), 0);
            if (level != 0)
            {
                cout << "The level of the node is: " << level << endl;
            }
            else
            {
                cout << "Node not found in the tree." << endl;
            }
            break;
        }
        case 5:
        {
            int find;
            cout << "Enter the value to search  in the tree\n";
            cin >> find;
            Node *Ans = t.Search(t.Getroot(), find);
            if (Ans != nullptr)
            {
                cout << "The search value is " << Ans->val << endl;
            }
            else
            {
                cout << "Value not found in the tree." << endl;
            }
            break;
        }
        case 6:
        {
            cout << "The tree is deleted\n";
            t.deleteTree(t.Getroot());
            break;
        }
        case 7:
        {
            cout << "Exiting the program\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}