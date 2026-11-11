#include <iostream>
using namespace std;

enum class Zone
{
    Inner, Middle, Outer, Airport
};

class Pass
{
private:
    Zone zone1, zone2;

public:
    Pass(Zone a, Zone b)
    {
        zone1 = a;
        zone2 = b;
    }

    bool covers(Zone z)
    {
        return z == zone1 || z == zone2;
    }
};

class SmartCard
{
private:
    long long balance;
    Pass pass;

public:
    SmartCard(long long b, Zone a, Zone c)
        : balance(b), pass(a, c)
    {
    }

    void travel(Zone z, bool peak, bool weekend)
    {
        long long fare = 0;

        switch (z)
        {
            case Zone::Inner:
                fare = 1000;
                break;

            case Zone::Middle:
                fare = 2000;
                break;

            case Zone::Outer:
                fare = 3000;
                break;

            case Zone::Airport:
                fare = 6000;
                break;
        }

        if (pass.covers(z))
        {
            fare = 0;
            cout << "Monthly pass used. ";
        }
        else if (weekend)
        {
            fare = fare - fare * 10 / 100;
        }
        else if (peak)
        {
            fare = fare + fare * 20 / 100;
        }

        if (balance - fare >= 5000)
        {
            balance = balance - fare;

            cout << "Journey allowed. Fare: Rs "
                 << fare / 100.0;
        }
        else
        {
            cout << "Journey denied. Low balance.";
        }

        cout << " Balance: Rs "
             << balance / 100.0 << endl;
    }
};

int main()
{
    // Monthly pass for Inner and Middle zones
    SmartCard card(20000, Zone::Inner, Zone::Middle);

    card.travel(Zone::Inner, false, false);

    card.travel(Zone::Outer, true, false);

    card.travel(Zone::Airport, true, true);

    card.travel(Zone::Middle, false, true);

    return 0;
}
