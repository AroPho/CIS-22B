/*
Aaron Nguyen
Summer 2018
Lab 4
Problem 4.2
Description of Problem:
Takes input from text file and stores the data in an array of objects.
Then runs a series of tests to test the code.*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/** Declares a class **/
class Car
{
    /**Private data for car**/
    public:
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

        /**Operator Overload**/
        Car &  operator = (const Car & carB);



};

/** Declares a class **/
class StringOfCars
{
    /**Private data for StringOfCars**/
    private:
        Car *ptr;
        static const int ARRAY_MAX_SIZE = 10;
        int scount = 0;

    /**Public member functions**/
    public:

        /**Constructors**/
        StringOfCars();

        StringOfCars(const StringOfCars &);

        /**Destructor**/
        ~StringOfCars();

        /**Adds car objects to array of car objects**/
        void push( Car &car);

        /**deletes car objects in array of car objects**/
        void pop( Car &car);

        /**Outputs StringOfCars**/
        void output();

};

/**Input Function Prototype**/
void input(StringOfCars &strings);

int main()
{
    string mark = "SP";
    int num = 34567;
    string type = "box";
    bool load = true;
    string dest = "Salt Lake City";
    cout << "TEST 1" << "\n";
    Car car1(mark, num, type, load, dest);
    Car car2(car1);
    car2.output();

    StringOfCars string1;
    cout << "\n" <<"TEST 2" << "\n";
    input(string1);
    string1.output();

    cout << "\n" << "TEST 3" << "\n";

    Car car3;
    string1.pop(car3);
    car3.output();
    string1.output();

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

/**Operator Overload**/

Car &Car :: operator=(const Car &carB)
    {
        reportingMark = carB.reportingMark;
        carNumber     = carB.carNumber;
        kind          = carB.kind;
        loaded        = carB.loaded;
        destination   = carB.destination;

        return * this;
    }

/**Constructors**/

StringOfCars :: StringOfCars()
{
    ptr = new Car[ARRAY_MAX_SIZE];
    scount = 0;
}

StringOfCars :: StringOfCars(const StringOfCars &cars)
{
    ptr = new Car[ARRAY_MAX_SIZE];
    for( int c = 0; c < ARRAY_MAX_SIZE; c++)
    {
        *(ptr + c) = *(cars.ptr + c);
        scount = c;
    }
}

/**Destructor**/

StringOfCars :: ~StringOfCars()
{
    delete[] ptr;
}

/**Outputs StringOfCars**/

void StringOfCars :: output()
{
    if(scount == 0)
    {
        cout << "No Cars";
    }
    for(int x = 0; x <= scount; x++)
    {
     ptr[x].output();
    }

}

/**Adds car objects to array of car objects**/

void StringOfCars :: push(Car &car)
{
    if(scount >= ARRAY_MAX_SIZE)
    {
        cout << "String of Cars is at max capacity" << "\n";
        return;
    }
    ptr[scount] = car;
    scount++;
}

/**deletes car objects in array of car objects**/

void StringOfCars :: pop(Car &car)
{
    if(scount < 0)
    {
        cout << "No Cars" << "\n";
        return;
    }
    car = ptr[scount - 1];
    scount--;
}

/**Friend operator overload function for Car class**/

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
void input(StringOfCars &string1)
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
                check = temp.getcarNumber();
                string1.push(temp);
            }
            else
            {
                inputFile.close();
                return;
            }

        }

    }
    else
    {
        cout << "File not found";
        exit(1);
    }

}
