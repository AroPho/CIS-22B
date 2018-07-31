#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



enum Kind{business, maintenance, other, box, tank, flat, otherFreight,
chair, sleeper, otherPassenger };
const string KIND_ARRAY[] = {"business", "maintenance", "other", "box", "tank",
"flat", "otherFreight", "chair", "sleeper", "otherPassenger"};

string knd;

Kind type;

int main()
{
    type = business;
    knd = KIND_ARRAY[type];

    cout << knd;
}
