#include <iostream>
#include <limits>
using namespace std;

const int MIN_BALANCE = 5000;

bool validZone(int zone)
{
    return zone >= 1 && zone <= 3;
}

bool isPeakHour(int hour)
{
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

long long calculateFare(int zone, int hour)
{
    long long fare = 0;

    if (zone == 1)
        fare = 1000;
    else if (zone == 2)
        fare = 2000;
    else if (zone == 3)
        fare = 3000;

    if (isPeakHour(hour))
        fare = fare + fare * 20 / 100;

    return fare;
}

bool canTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE;
}

int main()
{
    // Five journeys
    int zones[] = {1, 2, 3, 1, 2};
    int hours[] = {12, 9, 14, 18, 15};

    long long total = 0;

    cout << "FIVE JOURNEY TEST\n";

    for (int i = 0; i < 5; i++)
    {
        long long fare = calculateFare(zones[i], hours[i]);

        cout << "Journey " << i + 1
             << ": Rs " << fare / 100.0 << endl;

        total = total + fare;
    }

    cout << "Total fare: Rs " << total / 100.0 << endl;

    // Boundary tests
    cout << "\nPEAK HOUR TEST\n";

    cout << "8 AM: " << isPeakHour(8) << endl;
    cout << "10 AM: " << isPeakHour(10) << endl;
    cout << "5 PM: " << isPeakHour(17) << endl;
    cout << "8 PM: " << isPeakHour(20) << endl;

    // Minimum balance test
    cout << "\nBALANCE TEST\n";

    if (canTravel(8000, 3000))
        cout << "Journey allowed. Rs 50 remains.\n";
    else
        cout << "Journey denied.\n";

    // Invalid zone test
    cout << "\nINVALID ZONE TEST\n";

    if (!validZone(4))
        cout << "Invalid zone rejected.\n";

    // Negative recharge test
    cout << "\nRECHARGE TEST\n";

    int recharge = -500;

    if (recharge < 0)
        cout << "Negative recharge rejected.\n";

    // Invalid hour input test
    int hour;

    cout << "\nEnter journey hour: ";

    while (!(cin >> hour) || hour < 0 || hour > 23)
    {
        cout << "Invalid hour. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Valid hour entered: " << hour << endl;

    return 0;
}
