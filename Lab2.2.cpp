/*
Aaron Nguyen
Summer 2018
Lab 2
Problem 2.2
Description of Problem:
Asks for number for data from user to be stored as an object of a class
and to output object */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/** Declares a class **/
class Car
{
    /**Private data for car**/
    private:
        string reportingMark;
        int carNumber;
        string kind;
        bool loaded;
        string destination;
    /**Public member functions**/
    public:

        /**Car class prototype**/
        Car(string mark, int num, string type, bool load, string dest)
        {
            reportingMark = mark;
            carNumber = num;
            kind = type;
            loaded = load;
            destination = dest;
        }

        /**Creates car object and sets variable from local variable in functions**/
        Car* setUpCar(string mark, int num, string type, bool load, string dest)
        {
            Car *thecar = new Car(mark, num, type, load, dest);
            return thecar;
        }
        /**Destructor**/
        ~Car()
        {
        };
        /**Accessors**/
        string getreportingMark()const
        {
            return reportingMark;
        }
        int getcarNumber() const
        {
            return carNumber;
        }
        string getkind() const
        {
            return kind;
        }
        bool getloaded() const
        {
            return loaded;
        }
        string getdestination() const
        {
            return destination;
        }


};

/**Function Prototypes**/
void input(string &mark, int &num, string &type, bool &load, string &dest);
void output(string mark, int num, string type, bool load, string dest);

int main()
{
    /**Local Variables**/
    string mark;
    int num;
    string type;
    bool load;
    string dest;

    input(mark, num, type, load, dest);
    output(mark, num, type, load, dest);
    /**Pointer for Car Class**/
    Car *testcar;
    *testcar -> setUpCar(mark, num, type, load, dest);
    delete[] testcar;
    testcar = NULL;
    return 0;

}
/**Input Function**/
void input(string &mark, int &num, string &type, bool &load, string &dest)
{
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
    cin.ignore();
    if( check == "true" || "True" || "Yes" || "yes")
    {
        load = true;
        cout << "Please enter a destination: ";
        getline(cin,dest);
    }
    else
    {
        load = false;
    }
}

/**Outputs data inputed by user**/
void output(string mark, int num, string type, bool load, string dest)
{
    cout << "\n" << "*****Car Data*****" << "\n\n";
    cout << "Car Mark: " << mark << "\n";
    cout << "Car Number: " << num << "\n";
    cout << "Car Type: " << type << "\n";
    cout << "Car Load: " << boolalpha << load << "\n";
    cout << "Car Destination: " << dest << "\n";
}
