#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Car
{
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;
};

 void input(Car *thecar);
 void output(Car *thecar);

int main()
{
    Car* thecar = new Car();
    input(thecar);
    output(thecar);
    delete[] thecar;
    thecar = NULL;
}

void input(Car *thecar)
{
    string mark;
    int num;
    string type;
    bool load;
    string dest = "NONE";

    cout << "Please enter the reporting mark (maximum of 5 characters): ";
    cin >> mark;
    while (mark.length() > 5 || mark.length() == 0)
    {
        cout << "Invalid input please re-input mark: ";
        cin >> mark;
    }
    for (int x = 0; x < mark.length(); x++)
    {
        mark[x] = toupper(mark[x]);
    }

    cout << "Please input the Car Number: ";
    cin >> num;
    while (cin.fail())
    {
        cout << "Invalid please enter valid Number: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> num;
    }

    cout << "Please enter Car type (box, tank, flat, or other): ";
    cin >> type;

    cout << "Is the car loaded? (true or false): ";
    string check;
    cin >> check;
    if( check == "true" || "True" || "Yes" || "yes")
    {
        load = true;
        cout << "Please enter a destination: ";
        cin >> dest;
    }
    else
    {
        load = false;
    }


    thecar -> reportingMark = mark;
    thecar -> carNumber = num;
    thecar -> kind = type;
    thecar -> loaded = load;
    thecar -> destination = dest;


}

void output(Car *thecar)
{
    cout << "\n" << "*****Car Data*****" << "\n\n";
    cout << "Car Mark: " << thecar -> reportingMark << "\n";
    cout << "Car Number: " << thecar -> carNumber << "\n" ;
    cout << "Car Type: " << thecar -> kind << "\n";
    cout << "Car Load: " << boolalpha << thecar -> loaded << "\n";
    cout << "Car Destination: " << thecar -> destination << "\n";
}
