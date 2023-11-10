#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVL_BST
{
public:
    Node *root;

    AVL_BST()
    {
        root = nullptr;
    }

    int height(Node *h)
    {
        if (h == nullptr)
            return 0;
        return h->height;
    }

    int getBalance(Node *b)
    {
        if (b == nullptr)
            return 0;
        return height(b->left) - height(b->right);
    }

    Node *leftRotate(Node *r)
    {
        Node *n = r->right;
        Node *t = n->left;

        n->left = r;
        r->right = t;

        r->height = 1 + max(height(r->left), height(r->right));
        n->height = 1 + max(height(n->left), height(n->right));

        return n;
    }

    Node *rightrotate(Node *r)
    {
        Node *n = r->left;
        Node *t = n->right;

        n->right = r;
        r->left = t;

        r->height = 1 + max(height(r->left), height(r->right));
        n->height = 1 + max(height(n->left), height(n->right));

        return n;
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

    void insert(int value)
    {
        root = insertToAVL(root, value);
    }

    Node *insertToAVL(Node *root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        else if (data > root->data)
        {
            root->right = insertToAVL(root->right, data);
        }
        else if (data < root->data)
        {
            root->left = insertToAVL(root->left, data);
        }
        else
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && data < root->left->data)
        {
            return rightrotate(root);
        }
        if (balance < -1 && data > root->right->data)
        {
            return leftRotate(root);
        }
        if (balance > 1 && data > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightrotate(root);
        }
        if (balance < -1 && data < root->right->data)
        {
            root->right = rightrotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    bool search(int value)
    {
        return searchNode(root, value);
    }

    bool searchNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (value == node->data)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }
    }

    void remove(int value)
    {
        root = removeNode(root, value);
    }

    Node *removeNode(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (value < node->data)
        {
            node->left = removeNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeNode(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *temp = findMinimum(node->right);
                node->data = temp->data;
                node->right = removeNode(node->right, temp->data);
            }
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rightrotate(node);
        }
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightrotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightrotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *findMinimum(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    Node *findMaximum(Node *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    void inOrder(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        inOrder(node->left);
        cout << node->data << "\t";
        inOrder(node->right);
    }
    Node *Getroot()
    {
        return root;
    }
};

int main()
{
    AVL_BST avl_tree;

    while (true)
    {
        int choice;
        cout << "\nAVL Tree Menu\n";
        cout << "1. Insert a value\n";
        cout << "2. Delete a value\n";
        cout << "3. Display tree (In order traversal)\n";
        cout << "4. Update a value\n";
        cout << "5. Search a value\n";
        cout << "6. Find max\n";
        cout << "7. Find min\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            avl_tree.insert(value);
            cout << "Value " << value << " inserted into the tree.\n";
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            if (avl_tree.search(value))
            {
                avl_tree.remove(value);
                cout << "Value " << value << " deleted from the tree.\n";
            }
            else
            {
                cout << "Value not found in the tree.\n";
            }
            break;
        }
        case 3:
        {
            cout << "In-order traversal of the tree: ";
            avl_tree.inOrder(avl_tree.Getroot());
            cout << endl;
            break;
        }
        case 4:
        {
            int oldValue, newValue;
            cout << "Enter the value to update: ";
            cin >> oldValue;
            cout << "Enter the new value: ";
            cin >> newValue;
            if (avl_tree.search(oldValue))
            {
                avl_tree.remove(oldValue);
                avl_tree.insert(newValue);
                cout << "Value " << oldValue << " updated to " << newValue << ".\n";
            }
            else
            {
                cout << "Value not found in the tree.\n";
            }
            break;
        }
        case 5:
        {
            int value;
            cout << "Enter the value to search: ";
            cin >> value;
            if (avl_tree.search(value))
            {
                cout << "Value " << value << " found in the tree.\n";
            }
            else
            {
                cout << "Value not found in the tree.\n";
            }
            break;
        }
        case 6:
        {
            Node *maxNode = avl_tree.findMaximum(avl_tree.Getroot());
            cout << "Maximum value in the tree: " << maxNode->data << endl;
            break;
        }
        case 7:
        {
            Node *minNode = avl_tree.findMinimum(avl_tree.Getroot());
            cout << "Minimum value in the tree: " << minNode->data << endl;
            break;
        }
        case 8:
        {
            cout << "Exiting the program.\n";
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}