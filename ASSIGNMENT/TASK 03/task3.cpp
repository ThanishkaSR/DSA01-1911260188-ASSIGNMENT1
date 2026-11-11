
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    // Checking data type sizes
    cout << "DATA TYPE SIZES\n";

    cout << "bool: " << sizeof(bool) << " bytes\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "long: " << sizeof(long) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";

    // Checking integer ranges
    cout << "\nINTEGER RANGES\n";

    cout << "Minimum int: " << INT_MIN << endl;
    cout << "Maximum int: " << INT_MAX << endl;
    cout << "Maximum unsigned int: " << UINT_MAX << endl;
    cout << "Maximum long long: " << LLONG_MAX << endl;

    // Calculating daily metro collection
    long long journeys = 3000000;
    long long fare = 3600;

    long long collection = journeys * fare;

    cout << "\nDAILY COLLECTION\n";
    cout << "Total collection: " << collection << " paise\n";

    if (collection > INT_MAX)
    {
        cout << "Integer is not enough for this amount.\n";
        cout << "So, long long is used.\n";
    }

    // Comparing double and integer paise
    double rupees = 0.0;
    long long paise = 0;

    for (int i = 0; i < 1000000; i++)
    {
        rupees = rupees + 0.1;
        paise = paise + 10;
    }

    cout << "\nPRECISION TEST\n";
    cout << setprecision(15);

    cout << "Double value: " << rupees << endl;
    cout << "Integer paise value: " << paise << endl;

    return 0;
}

