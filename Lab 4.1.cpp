/*
Aaron Nguyen
Summer 2018
Lab 3
Problem 3.1
Description of Problem:
Asks for inputs from user to be stored as an object of a class
as well as create multiple constructors for Car class. Then compare data
in each object and outputs data and results of comparison.*/

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

        Car(string &mark, int &num, string &type, bool &load, string &dest)
        {
            setUp(mark, num, type, load, dest);
        }

        Car(const Car &carobj)
        {
            reportingMark = carobj.reportingMark;
            carNumber = carobj.carNumber;
            kind = carobj.kind;
            loaded = carobj.loaded;
            destination = carobj.destination;
        }

        /**Sets variables for a car object**/
        void setUp(string &mark, int &num, string &type, bool &load, string &dest);

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
        /**Mutator**/

        void output();

        /**Operator that compares variables within objects**/
        friend bool operator == (const Car &car1, const Car &car2)
        {
            if( car1.getreportingMark() == car2.getreportingMark() && car1.getcarNumber() == car2.getcarNumber())
            {
                return true;
            }
            else
            {
                return false;
            }

        }


};

/**Input Function Prototype**/
void input();

int main()
{
    input();
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
void input()
{

    string obj;
    string mark;
    int num;
    string type;
    bool load;
    string dest;

    ifstream inputFile ("cardata4.txt");
    if(inputFile.is_open())
    {
        while(!inputFile.eof())
        {
            inputFile >> obj >> mark >> num >> type;
            inputFile >> boolalpha >> load;
            getline(inputFile, dest);


        }

    }
    else
    {
        cout << "File not found";
        exit(1);
    }







    Car temp(mark, num, type, load, dest);
    temp.output();

}

/*Checks for proper input*/
    /*while (mark.length() > 5 || mark.length() == 0)
    {
        cin >> mark;
    }
    for (int x = 0; x < mark.length(); x++)
    {
        mark[x] = toupper(mark[x]);
    }

    cin >> num;
    /*Checks for proper input*/
    /*
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cin >> num;
    }


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
    }*/

