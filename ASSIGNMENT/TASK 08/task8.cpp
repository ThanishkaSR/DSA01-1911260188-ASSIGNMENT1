#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    int zone, hour;
    long long balance;

    // Read zone
    cout << "Enter zone (1-Inner, 2-Middle, 3-Outer): ";

    while (!(cin >> zone) || zone < 1 || zone > 3)
    {
        cout << "Invalid zone. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Read hour
    cout << "Enter journey hour (0-23): ";

    while (!(cin >> hour) || hour < 0 || hour > 23)
    {
        cout << "Invalid hour. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Read balance
    cout << "Enter card balance in rupees: ";

    while (!(cin >> balance) || balance < 0)
    {
        cout << "Invalid balance. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Calculate base fare in paise
    long long fare = 0;

    if (zone == 1)
        fare = 1000;
    else if (zone == 2)
        fare = 2000;
    else
        fare = 3000;

    // Check peak hours
    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
    {
        fare = fare + fare * 20 / 100;
    }

    // Convert balance into paise
    balance = balance * 100;

    cout << "\n--- JOURNEY REPORT ---\n";

    cout << "Base fare: Rs "
         << fixed << setprecision(2)
         << (zone * 1000) / 100.0 << endl;

    if (balance - fare >= 5000)
    {
        balance = balance - fare;

        cout << "Journey Status: Allowed\n";
    }
    else
    {
        cout << "Journey Status: Denied\n";
    }

    cout << "Fare: Rs " << fare / 100.0 << endl;

    cout << "Remaining Balance: Rs "
         << balance / 100.0 << endl;

    return 0;
}
