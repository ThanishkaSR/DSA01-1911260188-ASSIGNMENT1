PROCEDURAL CODE

#include <iostream>
using namespace std;

const int MIN_BALANCE = 5000;

bool canTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE;
}

void deduct(long long &balance, long long fare)
{
    if (canTravel(balance, fare))
    {
        balance = balance - fare;
        cout << "Journey allowed\n";
    }
    else
    {
        cout << "Journey denied\n";
    }
}

int main()
{
    long long balance = 10000;
    long long fare = 3000;

    deduct(balance, fare);

    cout << "Remaining balance: Rs "
         << balance / 100 << endl;

    return 0;
}



C++ CODE

  #include <iostream>
using namespace std;

class SmartCard
{
private:
    long long balance;
    const long long MIN_BALANCE = 5000;

public:
    SmartCard(long long b)
    {
        balance = b;
    }

    bool canTravel(long long fare)
    {
        return balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare)
    {
        if (canTravel(fare))
        {
            balance = balance - fare;
            cout << "Journey allowed\n";
        }
        else
        {
            cout << "Journey denied\n";
        }
    }

    void showBalance()
    {
        cout << "Remaining balance: Rs "
             << balance / 100 << endl;
    }
};

int main()
{
    SmartCard card(10000);

    card.deduct(3000);

    card.showBalance();

    return 0;
}
