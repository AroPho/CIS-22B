#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



enum Kind{business, maintenance, other, box, tank, flat, otherFreight,
chair, sleeper, otherPassenger };

Kind kind;

int main()
{
    cin >> kind;

    cout << kind;
}
