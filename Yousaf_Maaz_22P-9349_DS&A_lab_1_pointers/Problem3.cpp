#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int Rows = 4;
int column = 7;

string Nameofday[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; // output the name

int main()
{
    srand(time(nullptr));

    int Array[Rows][column];

    for (int i = 0; i < Rows; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            *(*(Array + i) + j) = rand() % 21 + 10; // first 0-20 and  shift with 10-30
        }
    }

    // Display the temperatures
    cout << "Temperature of the each week:\n";
    for (int i = 0; i < Rows; ++i)
    {
        cout << "Week " << i + 1 << ": ";
        for (int j = 0; j < column; ++j)
        {
            cout << *(*(Array + i) + j) << "C ";
        }
        cout << "\n";
    }

    // Find the hottest day of each week
    for (int i = 0; i < Rows; ++i)
    {
        int High_temputure = *(*(Array + i));
        int maxTempDay = 0;
        for (int j = 1; j < column; ++j)
        {
            if (*(*(Array + i) + j) > High_temputure)
            {
                High_temputure = *(*(Array + i) + j);
                maxTempDay = j;
            }
        }
        cout << "\nHottest day of Week " << i + 1 << ": " << Nameofday[maxTempDay]
             << " with temperature " << High_temputure << " C\n";
    }

    return 0;
}
