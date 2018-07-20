/*
Aaron Nguyen
Summer 2018
Lab 1
Problem 2.1
Description of Problem:
Asks for number for data from user to be stored in a structure
and to be outputted */
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

/**Function Prototypes**/
 void input(Car *thecar);
 void output(Car *thecar);

int main()
{
    /**Creates pointer to Car structure**/
    Car* thecar = new Car();
    input(thecar);
    output(thecar);
    delete[] thecar;
    thecar = NULL;
}

/**Function that takes inputs from users and stores it in a structure**/
void input(Car *thecar)
{
    string mark;
    int num;
    string type;
    bool load;
    string dest = "NONE";

    cout << "Please enter the reporting mark (maximum of 5 characters): ";
    cin >> mark;
    /*Checks for proper input*/
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
    /*Checks for proper input*/
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

    /**Transfers local variables to structure**/
    thecar -> reportingMark = mark;
    thecar -> carNumber = num;
    thecar -> kind = type;
    thecar -> loaded = load;
    thecar -> destination = dest;


}

/**Outputs stored data in car structure**/
void output(Car *thecar)
{
    cout << "\n" << "*****Car Data*****" << "\n\n";
    cout << "Car Mark: " << thecar -> reportingMark << "\n";
    cout << "Car Number: " << thecar -> carNumber << "\n" ;
    cout << "Car Type: " << thecar -> kind << "\n";
    cout << "Car Load: " << boolalpha << thecar -> loaded << "\n";
    cout << "Car Destination: " << thecar -> destination << "\n";
}
