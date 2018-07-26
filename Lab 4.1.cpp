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

        Car();


        Car(string &mark, int &num, string &type, bool &load, string &dest);


        Car(const Car &carobj);


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
        friend bool operator == (const Car &car1, const Car &car2);


};

/**Input Function Prototype**/
void input();

int main()
{
    input();
    return 0;

}

/**Car class constructors**/

Car :: Car()
    {
        reportingMark = "";
        carNumber = 0;
        kind = "other";
        loaded = 0;
        destination = "NONE";
    }

Car:: Car(string &mark, int &num, string &type, bool &load, string &dest)
    {
        setUp(mark, num, type, load, dest);
    }

Car:: Car(const Car &carobj)
    {
        reportingMark = carobj.reportingMark;
        carNumber = carobj.carNumber;
        kind = carobj.kind;
        loaded = carobj.loaded;
        destination = carobj.destination;
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

bool operator == (const Car &car1, const Car &car2)
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


/**Input Function**/
void input()
{
    int check;
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

            Car temp(mark, num, type, load, dest);

            if(check != temp.getcarNumber())
            {
                temp.output();
                check = temp.getcarNumber();
            }
            else
            {
                inputFile.close();
                exit(0);
            }

        }

    }
    else
    {
        cout << "File not found";
        exit(1);
    }

}

