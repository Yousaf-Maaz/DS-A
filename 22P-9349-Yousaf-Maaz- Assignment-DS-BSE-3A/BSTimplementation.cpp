#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BSTImplementation
{
private:
    Node *root;

public:
    BSTImplementation()
    {
        root = nullptr;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    bool search(int n)
    {
        return searchNode(root, n);
    }

    bool searchNode(Node *node, int n)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (n == node->data)
        {
            return true;
        }
        else if (n < node->data)
        {
            return searchNode(node->left, n);
        }
        else
        {
            return searchNode(node->right, n);
        }
    }

    void insert(int n)
    {
        root = insertNode(root, n);
    }

    Node *insertNode(Node *node, int n)
    {
        if (node == nullptr)
        {
            return new Node(n);
        }

        if (n < node->data)
        {
            node->left = insertNode(node->left, n);
        }
        else if (n > node->data)
        {
            node->right = insertNode(node->right, n);
        }

        return node;
    }

    void remove(int n)
    {
        root = removeNode(root, n);
    }

    Node *removeNode(Node *node, int n)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (n < node->data)
        {
            node->left = removeNode(node->left, n);
        }
        else if (n > node->data)
        {
            node->right = removeNode(node->right, n);
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

            Node *temp = findMinimum(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
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

    void inOrderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
    void preOrder(Node *n)
    {
        if (n == nullptr)
        {
            return;
        }

        cout << n->data << " ";
        preOrder(n->left);
        preOrder(n->right);
    }
    void postOrder(Node *n)
    {
        if (n == nullptr)
        {
            return;
        }

        postOrder(n->left);
        postOrder(n->right);
        cout << n->data << " ";
    }

    Node *getRoot()
    {
        return root;
    }
};

int main()
{
    BSTImplementation binaryTree;

    cout << "---------------------------------------------------------------------\n";
    cout << "welcome to Binary search implementation By Yousaf Maaz" << endl;
    cout << "---------------------------------------------------------------------\n";

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Is the BST empty\n";
        cout << "2. Insert an item\n";
        cout << "3. Search for an item\n";
        cout << "4. Remove an item\n";
        cout << "5. Traverse the BST\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            if (binaryTree.isEmpty())
            {
                cout << "The BST is empty.\n";
            }
            else
            {
                cout << "The BST is not empty.\n";
            }
        }
        else if (choice == 2)
        {
            int item;
            cout << "Enter the item to insert: ";
            cin >> item;
            binaryTree.insert(item);
            cout << "Inserted " << item << " into the BST.\n";
        }
        else if (choice == 3)
        {
            int item;
            cout << "Enter the item to search for: ";
            cin >> item;
            if (binaryTree.search(item))
            {
                cout << "Item " << item << " is found in the BST.\n";
            }
            else
            {
                cout << "Item " << item << " is not found in the BST.\n";
            }
        }
        else if (choice == 4)
        {
            int item;
            cout << "Enter the item to remove: ";
            cin >> item;
            binaryTree.remove(item);
            cout << "Removed " << item << " from the BST.\n";
        }
        else if (choice == 5)
        {
            cout << "Choose a traversal method:\n";
            cout << "1. In-order\n";
            cout << "2. Pre-order\n";
            cout << "3. Post-order\n";
            cout << "Enter your choice: ";
            int traversalChoice;
            cin >> traversalChoice;

            switch (traversalChoice)
            {
            case 1:
                cout << "In-order traversal: ";
                binaryTree.inOrderTraversal(binaryTree.getRoot());
                cout << endl;
                break;
            case 2:
                cout << "Pre-order traversal: ";
                binaryTree.preOrder(binaryTree.getRoot());
                cout << endl;
                break;
            case 3:
                cout << "Post-order traversal: ";
                binaryTree.postOrder(binaryTree.getRoot());
                cout << endl;
                break;
            default:
                cout << "Invalid traversal choice.\n";
                break;
            }
        }
        else if (choice == 6)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
