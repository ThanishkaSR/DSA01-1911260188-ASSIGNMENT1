
#include <iostream>
using namespace std;

int main()
{
    int x = 5, y = 3;

    cout << x + y * 2 << " " << (x + y) * 2 << endl;

    int z = x++ + ++y;

    cout << z << " " << x << " " << y << endl;

    cout << (x > y ? x : y) << " " << x % 4 * 2 << endl;

    cout << 10 / 3 << " " << 10 % 3 << " "
         << -10 / 3 << " " << -10 % 3 << endl;

    int k = 0;

    for (int i = 0; i < 10; i += 3)
    {
        k += i;
    }

    cout << k << endl;

    return 0;
}

