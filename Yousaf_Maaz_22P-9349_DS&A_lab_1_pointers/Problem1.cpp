// Task 1
#include <iostream>

using namespace std;

void functionswap(int *ptr, int *ptr2)
{
    // Swapping the values using pointers
    int temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
}

int main()
{
    // Program that swaps two numbers.
    int num1, num2;
    int *ptr = &num1;
    int *ptr2 = &num2;

    cout << "Enter the value(1):" << endl;
    cin >> num1;

    cout << "Enter the value(2):" << endl;
    cin >> num2;

    functionswap(ptr, ptr2);

    cout << "After swapping:" << endl;
    cout << "Value(1): " << num1 << endl;
    cout << "Value(2): " << num2 << endl;

    return 0;
}
