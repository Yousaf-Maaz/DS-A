#include <iostream>
#include <vector>
using namespace std;

class Employee
{
public:
	int employeeID;
	string name;
	float sales;
	float customerSatisfaction;
	float projectCompletion;
	float performanceScore;

	Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion)
	{
		this->employeeID = employeeID;
		this->name = name;
		this->customerSatisfaction = customerSatisfaction;
		this->projectCompletion = projectCompletion;
	}

	void calculatePerformanceScore()
	{

		performanceScore = sales + customerSatisfaction + projectCompletion;
	}
};

class MaxHeap
{
public:
	vector<Employee> employeeHeap;

	int getParent(int child)
	{
		if (child <= 0)
		{
			cout << "invalid input.\n";
			return -1;
		}

		return (child - 1) / 2;
	}

	int getLeft(int parent)
	{

		if (parent < 0)
		{
			cout << "invalid input\n";
			return -1;
		}

		return (parent * 2) + 1;
	}

	int getRight(int parent)

	{

		{
			if (parent < 0)
			{
				cout << "invalid input \n";
				return -1;
			}

			return (parent * 2) + 2;
		}
	}

	void swap(Employee *a, Employee *b)
	{
		Employee temp = *a;
		*a = *b;
		*b = temp;
	}

	void heapifyUp(int node)
	{
		int parent;

		{
			if (node > 0)
			{
				parent = getParent(node);
			}

			if (employeeHeap[node] > employeeHeap[parent])
			{
				swap(&employeeHeap[node], &employeeHeap[parent]);
			}
			heapifyUp(parent);
		}
	}

	void heapifyDown(int node)
	{

		{
			int leftChild = GetLeftChild(node);
			int rightChild = GetRightChild(node);
			int l = node;

			if (leftChild < employeeHeap.size() && employeeHeap[leftChild] > employeeHeap[l])
			{
				l = leftChild;
			}

			if (rightChild < employeeHeap.size() && employeeHeap[rightChild] > employeeHeap[l])
			{
				l = rightChild;
			}

			if (l != node)
			{
				swap(&employeeHeap[node], &employeeHeap[l]);
				heapifyDown(l);
			}
		}
	}

	void insertEmployee(Employee emp)
	{

		{
			if (employeeHeap.size() - 1 == 0)
			{
				employeeHeap.push_back(emp);
				return;
			}

			employeeHeap.push_back(emp);
			heapifyUp(employeeHeap.size() - 1);
		}
	}

	void getTopRankingEmployee()
	{
		if (employeeHeap.calculatePerformanceScore >= employeeHeap.performanceScore)
		{
			cout << " Top score:" << employeeHeap.calculatePerformanceScore << endl;
		}
		else
		{
			cout << " Top score is: " << employeeHeap.performanceScore << endl;
		}
	}

	void updatePerformance(int employeeID, float newSales, float newCS, float newPCE)
	{

		employeeHeap.employeeID == employeeID;
		employeeHeap.newSales == newSales;
		employeeHeap.newCS == newCS;
		employeeHeap.newPCE == newPCE;
	}

	void displayEmployees()
	{
		if (employeeHeap.empty())
		{
			cout << "No Employees." << endl;
			return;
		}
		cout << "Employee Rankings:" << endl;
		for (const Employee &emp : employeeHeap)
		{
			cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
		}
	}
};

int main()
{
	MaxHeap employeeMaxHeap;

	while (true)
	{
		cout << "\nMenu:\n";
		cout << "1. Enter a new employee details\n";
		cout << "2. Get the top-ranking employee\n";
		cout << "3. Update an employee's scores\n";
		cout << "4. Display employee rankings\n";
		cout << "5. Exit\n";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int id;
			string name;
			float sales, cs, pce;
			cout << "Enter Employee ID: ";
			cin >> id;
			cin.ignore(); // Clear newline character from the buffer
			cout << "Enter Employee Name: ";
			getline(cin, name);
			cout << "Enter Sales (in percentage): ";
			cin >> sales;
			cout << "Enter Customer Satisfaction (in percentage): ";
			cin >> cs;
			cout << "Enter Project Completion Efficiency (in percentage): ";
			cin >> pce;

			Employee newEmployee(id, name, cs, pce, sales);
			newEmployee.calculatePerformanceScore();
			employeeMaxHeap.insertEmployee(newEmployee);
			cout << "Employee added successfully!" << endl;
			break;
		}
		case 2:
		{
			employeeMaxHeap.getTopRankingEmployee();
			break;
		}
		case 3:
		{
			int empID;
			float newSales, newCS, newPCE;
			cout << "Enter Employee ID to update scores: ";
			cin >> empID;
			cout << "Enter new Sales (in percentage): ";
			cin >> newSales;
			cout << "Enter new Customer Satisfaction (in percentage): ";
			cin >> newCS;
			cout << "Enter new Project Completion Efficiency (in percentage): ";
			cin >> newPCE;
			employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
			break;
		}
		case 4:
		{
			employeeMaxHeap.displayEmployees();
			break;
		}
		case 5:
			cout << "Exiting the program." << endl;
			return 0;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	return 0;
}
