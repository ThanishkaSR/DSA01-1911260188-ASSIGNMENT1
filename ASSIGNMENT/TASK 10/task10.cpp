#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
    long long journeys[] = {20000, 500000, 3000000};

    double fare = 36.0;
    long long farePaise = 3600;

    cout << fixed << setprecision(2);

    for (int i = 0; i < 3; i++)
    {
        double doubleTotal = journeys[i] * fare;

        long long paiseTotal = journeys[i] * farePaise;

        cout << "Journeys: " << journeys[i] << endl;

        cout << "Double total: Rs "
             << doubleTotal << endl;

        cout << "Paise total: "
             << paiseTotal << " paise" << endl;

        cout << "Difference: Rs "
             << doubleTotal - paiseTotal / 100.0 << endl;

        if (paiseTotal > INT_MAX)
            cout << "int is not enough.\n";
        else
            cout << "int can store this total.\n";

        cout << endl;
    }

    // Precision test
    double total = 0.0;
    long long totalPaise = 0;

    for (int i = 0; i < 10; i++)
    {
        total = total + 0.1;
        totalPaise = totalPaise + 10;
    }

    cout << "PRECISION TEST\n";
    cout << setprecision(17);

    cout << "Double total: " << total << endl;
    cout << "Integer paise total: "
         << totalPaise << " paise" << endl;

    cout << "Maximum int value: " << INT_MAX << endl;

    return 0;
}
