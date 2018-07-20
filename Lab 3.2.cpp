/*
Aaron Nguyen
Summer 2018
Lab 3
Problem 3.2
Description of Problem:
Asks for inputs from user to be stored as an object of a class
as well as create multiple constructors for Car class and output data*/

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


        /**Car class constructors**/

        Car()
        {
            reportingMark = "";
            carNumber = 0;
            kind = "other";
            loaded = 0;
            destination = "NONE";
        }

        Car(const Car &carobj)
        {
            reportingMark = carobj.reportingMark;
            carNumber = carobj.carNumber;
            kind = carobj.kind;
            loaded = carobj.loaded;
            destination = carobj.destination;
        }

        Car(string &mark, int &num, string &type, bool &load, string &dest)
        {
            setUp(mark, num, type, load, dest);
        }

        /**Destructor**/
        ~Car()
        {
        };

        /**Sets variables for a car object**/
        void setUp(string &mark, int &num, string &type, bool &load, string &dest);

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
        /**Mutator**/

        void output();


};

/**Input Function Prototype**/
void input(string &mark, int &num, string &type, bool &load, string &dest);

int main()
{
    string mark;
    int num;
    string type;
    bool load;
    string dest;

    /**Take inputs from User**/
    input(mark, num, type, load, dest);

    /**Object creation**/
    Car car1(mark, num, type, load, dest);
    Car car2(car1);
    Car car3;


    /**Output object Data**/
    cout << "\n" << "Car 1 " << "\n";
    car1.output();
    cout << "\n" << "Car 2 " << "\n";
    car2.output();
    cout << "\n" << "Car 3 " << "\n";
    car3.output();
    return 0;

}

/**Outputs data inputed by user**/
void Car :: output()
{
    cout << "\n" << "*****Car Data*****" << "\n\n";
    cout << "Car Mark: " << reportingMark << "\n";
    cout << "Car Number: " << carNumber << "\n";
    cout << "Car Type: " << kind << "\n";
    cout << "Car Load: " << boolalpha << loaded << "\n";
    cout << "Car Destination: " << destination << "\n";
}

/**Sets variables for a car object**/
void Car :: setUp(string &mark, int &num, string &type, bool &load, string &dest)
{

    reportingMark = mark;
    carNumber = num;
    kind = type;
    loaded = load;
    destination = dest;
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


