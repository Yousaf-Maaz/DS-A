
// Organizational Hierarchy Management
// (Implement using AVL Tree)

// An HR manager in a large corporation, need a system to efficiently manage the hierarchical
// structure of the organization. The system should store employee information and allow for
// efficient searching, reporting, and manipulation of the organizational hierarchy.
// Design a program with a menu-driven interface that uses an AVL tree to represent the
// organizational hierarchy of the company. Each node in the tree should contain information
// about an employee, including their ID, name, and designation.
// Menu Options:
// Add Employee: This option allows you to add a new employee to the organizational
// hierarchy. You should input the employee's name, title, department, and any other relevant
// information. The program should ensure that the tree remains balanced, and employees are
// added in a way that maintains the hierarchical structure. You should insert the employee at
// the proper location in the tree based on the employee ID.
// 1. Search for Employee: This option enables you to search for an employee by his ID
// and the program should display the employee details including his ID, name, and
// designation. The program should efficiently navigate the tree to find the desired
// employee and display their information.
// 2. Generate Organizational Chart: This option generates an organizational chart
// that visualizes the hierarchical structure of the company. The chart should display
// the names of all employees in a structured manner. You can use the ready-made
// code to display the tree in a hierarchal manner from internet or from existing codes.
// 3. Modify Employee Information: This option allows you to update the information
// of an existing employee, such as their name, and designation only (not the employee
// ID to avoid the tree imbalance).
// 4. Remove Employee: This option lets you remove an employee from the
// organizational hierarchy. The program should consider various cases, such as the
// removal of a leaf node, a node with one child, or a node with two children, while
// maintaining the balanced hierarchy.
// 5. Exit: This option allows you to quit the program.









#include <iostream>
#include <string>

using namespace std;


struct Employee
{
    int id;
    string name;
    string designation;

    Employee(int id, string name, string designation) : id(id), name(name), designation(designation) {}
};


class AVLNode
{
public:
    Employee employee;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(Employee emp) : employee(emp), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree
{
private:
    AVLNode *root;

    int height(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balancecheck(AVLNode *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode *insert(AVLNode *node, Employee emp)
    {
        if (node == nullptr)
            return new AVLNode(emp);

        if (emp.id < node->employee.id)
            node->left = insert(node->left, emp);
        else if (emp.id > node->employee.id)
            node->right = insert(node->right, emp);
        else
            return node; 

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balancecheck(node);

        // Left Left Case
        if (balance > 1 && emp.id < node->left->employee.id)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && emp.id > node->right->employee.id)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && emp.id > node->left->employee.id)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && emp.id < node->right->employee.id)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    AVLNode *minValueNode(AVLNode *node)
    {
        AVLNode *current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    AVLNode *deleteNode(AVLNode *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->employee.id)
            root->left = deleteNode(root->left, key);
        else if (key > root->employee.id)
            root->right = deleteNode(root->right, key);
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                AVLNode *temp = root->left ? root->left : root->right;

                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else
            {
                AVLNode *temp = minValueNode(root->right);

                root->employee = temp->employee;

                root->right = deleteNode(root->right, temp->employee.id);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balancecheck(root);

        // Left Left Case
        if (balance > 1 && balancecheck(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && balancecheck(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && balancecheck(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && balancecheck(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preOrder(AVLNode *root)
    {
        if (root != nullptr)
        {
            cout << "ID: " << root->employee.id << ", Name: " << root->employee.name << ", Designation: " << root->employee.designation << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void printTree(AVLNode *root, string indent, bool last)
    {
        if (root != nullptr)
        {
            cout << indent;

            if (last)
            {
                cout << "└──";
                indent += "    ";
            }
            else
            {
                cout << "├──";
                indent += "│   ";
            }

            cout << "ID: " << root->employee.id << ", Name: " << root->employee.name << ", Designation: " << root->employee.designation << endl;

            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    AVLNode *getRoot()
    {
        return root;
    }

    void addEmployee(Employee emp)
    {
        root = insert(root, emp);
    }

    Employee *searchEmployees(AVLNode *root, int key)
    {
        if (root == nullptr || root->employee.id == key)
        {
            return &(root->employee);
        }
        if (root->employee.id > key)
        {
            return searchEmployees(root->left, key);
        }
        if (root->employee.id < key)
        {
            return searchEmployees(root->right, key);
        }
        return nullptr; 
    }

    void modifyEmployee(int key, string newName, string newDesignation)
    {
        Employee *employee = searchEmployees(root, key);
        if (employee != nullptr)
        {
            cout << "Enter new Name for Employee (ID: " << key << "): ";
            cin.ignore();
            getline(cin, newName);
            cout << "Enter new Designation for Employee (ID: " << key << "): ";
            getline(cin, newDesignation);
            cout << "Employee information modified successfully." << endl;
        }
        else
        {
            cout << "Employee not found." << endl;
        }
    }

    void generateOrganizationalChart()
    {
        printTree(root, "", true);
    }

    void removeEmployee(int id)
    {
        root = deleteNode(root, id);
    }

    void displayMenu()
    {
        cout << "Menu Options:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Search for Employee" << endl;
        cout << "3. Generate Organizational Chart" << endl;
        cout << "4. Modify Employee Information" << endl;
        cout << "5. Remove Employee" << endl;
        cout << "6. Exit" << endl;
    }
};

int main()
{
    AVLTree avlTree;

    while (true)
    {
        avlTree.displayMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name, designation;

            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Employee Designation: ";
            getline(cin, designation);

            Employee emp(id, name, designation);
            avlTree.addEmployee(emp);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            Employee *foundEmployee = avlTree.searchEmployees(avlTree.getRoot(), id);
            if (foundEmployee != nullptr)
            {
                cout << "Employee found: ID: " << foundEmployee->id << ", Name: " << foundEmployee->name << ", Designation: " << foundEmployee->designation << endl;
            }
            else
            {
                cout << "Employee not found." << endl;
            }
            break;
        }
        case 3:
            avlTree.generateOrganizationalChart();
            break;
        case 4:
        {
            int id;
            string newName, newDesignation;

            cout << "Enter Employee ID to modify: ";
            cin >> id;
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, newName);
            cout << "Enter new Designation: ";
            getline(cin, newDesignation);

            avlTree.modifyEmployee(id, newName, newDesignation);
            break;
        }
        case 5:
        {
            int id;
            cout << "Enter Employee ID to remove: ";
            cin >> id;
            avlTree.removeEmployee(id);
            break;
        }
        case 6:
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
