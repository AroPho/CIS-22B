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



enum Kind{business, maintenance, other, box, tank, flat, otherFreight,
chair, sleeper, otherPassenger };
const string KIND_ARRAY[10] = {"business", "maintenance", "other", "box", "tank",
"flat", "otherFreight", "chair", "sleeper", "otherPassenger"};


/** Declares a class **/
class Car
{
    /**Private data for car**/
    protected:
        string reportingMark;
        int carNumber;
        Kind kind;
        bool loaded;
        string destination;
        string knd;

    /**Public member functions**/
    public:


        /**Car class constructors**/

        Car();


        Car(string &mark, int &num, Kind &type, bool &load, string &dest);


        Car(const Car &carobj);


        /**Sets variables for a car object**/
        void setUp(string &mark, int &num, Kind &type, bool &load, string &dest, string &k);

        /**Destructor**/
        virtual ~Car()
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
        Kind getkind() const
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

        virtual void setKind(string &k);

        /**Operator that compares variables within objects**/
        friend bool operator == (const Car &car1, const Car &car2);

        /**Operator Overload**/
        Car &  operator = (const Car & carB);




};

class FreightCar : public Car
{
    public:
        FreightCar() : Car()
        {   }

        FreightCar(const Car &carobj) : Car(carobj)
        {   }
        FreightCar( string &mark,  int &num, Kind &type,  bool &load,
                    string &dest) : Car(mark, num, type, load, dest)
                   {
                       knd = KIND_ARRAY[type];
                       setKind(knd);
                   }
        void setKind(string &k)
            {
                for (int x = box; x < otherFreight; ++x)
                    {
                        if (KIND_ARRAY[x] == k)
                        {
                            kind = static_cast<Kind>(x);
                            return;
                        }
                        else
                        {
                            kind = otherFreight;
                        }
                    }
            }


};

class PassengerCar : public Car
{
    public:
        PassengerCar() : Car()
            {   }
        PassengerCar(const Car &carobj) : Car(carobj)
            {   }
        PassengerCar( string &mark,  int &num, Kind &type,  bool &load,
                    string &dest) : Car(mark, num, type, load, dest)
                {
                    knd = KIND_ARRAY[type];
                    setKind(knd);
                }
        void setKind(string &k)
            {
                for (int x = chair; x < otherPassenger; ++x)
                    {
                        if (KIND_ARRAY[x] == k)
                        {
                            kind = static_cast<Kind>(x);
                            return;
                        }
                        else if(KIND_ARRAY[x] != k)
                        {
                            kind = otherPassenger;
                        }
                    }
            }



};

/** Declares a class **/
class StringOfCars
{
    /**Private data for StringOfCars**/
    private:
        Car **ptr;
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

/**Function Prototypes**/
void input(StringOfCars &strings);
void buildCar(Car *&ptr, string &mark,  int &num,  Kind &type,  bool &load,  string &dest, StringOfCars &string1, string &k);
void buildFreightCar(FreightCar *&ptr, string &mark,  int &num,  Kind &type,  bool &load,  string &dest, StringOfCars &string1, string &k);
void buildPassengerCar(PassengerCar *&ptr, string &mark,  int &num,  Kind &type,  bool &load,  string &dest, StringOfCars &string1, string &k);

int main()
{
    StringOfCars string1;
    input(string1);
    return 0;

}

/**Car class constructors**/

Car :: Car()
    {
        reportingMark = "";
        carNumber = 0;
        kind = other;
        loaded = 0;
        destination = "NONE";
    }

Car:: Car(string &mark, int &num, Kind &type, bool &load, string &dest)
    {
        string k;
        setUp(mark, num, type, load, dest, k);
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
    cout << "Car Type: " << KIND_ARRAY[kind] << "\n";
    cout << "Car Load: " << boolalpha << loaded << "\n";
    cout << "Car Destination: " << destination << "\n";
}

/**Sets variables for a car object**/
void Car :: setUp(string &mark, int &num, Kind &type, bool &load, string &dest, string &k)
{
    reportingMark = mark;
    carNumber = num;
    setKind(k);
    loaded = load;
    destination = dest;
    cout << k;
    cout << kind;
}

void Car :: setKind(string &k)
{
    for (int x = business; x < other; ++x)
            {
                if (KIND_ARRAY[x] == k)
                {
                    kind = static_cast<Kind>(x);
                    return;
                }
                else
                {
                    kind = other;
                }
            }
}

/**Operator Overload**/

Car &Car :: operator = (const Car &carB)
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
    *ptr = new Car[ARRAY_MAX_SIZE];
    scount = 0;
}

StringOfCars :: StringOfCars(const StringOfCars &cars)
{
    for( int c = 0; c < ARRAY_MAX_SIZE; c++)
    {
        *(ptr + c) = *(cars.ptr + c);
        scount = c;
    }
}

/**Destructor**/

StringOfCars :: ~StringOfCars()
{
    delete[] *ptr;
}

/**Outputs StringOfCars**/

void StringOfCars :: output()
{
    if(scount == 0)
    {
        cout << "No Cars";
    }
    for(int x = 0; x < scount; x++)
    {
     ptr[x] -> output();
    }

}

/**Adds car objects to array of car objects**/

void StringOfCars :: push(Car &car)
{
    int i =0;
    if(scount >= 10)
    {
        cout << "String of Cars is at max capacity" << "\n";
        return;
    }
    (ptr)[scount++] = &car;
    i++;
    cout << i;

}

/**deletes car objects in array of car objects**/

void StringOfCars :: pop(Car &car)
{
    /*if(scount < 0)
    {
        cout << "No Cars" << "\n";
        return;
    }
    car = *ptr[scount - 1];
    scount--;*/
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
    int check = 0;
    string obj;
    string carnum;
    string mark;
    int num;
    string k;
    Kind type;
    bool load;
    string dest;

    ifstream inputFile ("cardata5.txt");
    if(inputFile.is_open())
    {
        while(inputFile.peek() != EOF)/*!inputFile.eof()*/
        {
            inputFile >> obj >> carnum >> mark >> num >> k;
            inputFile >> boolalpha >> load;
            getline(inputFile, dest);

        /*for (int x = business; x < 10; ++x)
            {
                if (KIND_ARRAY[x] == k)
                {
                    type = static_cast<Kind>(x);
                    break;
                }
                else
                {
                    type = other;
                }
            }*/
            cout << dest;

            if(check != num)
            {
                /*cout << "\n" << carnum << " \n";*/
                check = num;
                if(obj == "Car")
                {
                    Car *carobj;
                    buildCar(carobj, mark, num, type, load, dest, string1, k);
                }
                else if(obj == "FreightCar")
                {
                    FreightCar *fcarobj;
                    buildFreightCar(fcarobj, mark, num, type, load, dest, string1, k);
                }
                else if(obj == "PassengerCar")
                {
                    PassengerCar *Pcarobj;
                    buildPassengerCar(Pcarobj, mark, num, type, load, dest, string1, k);
                }
            }
            else
            {
                string1.output();
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

void buildCar(Car *&ptr,  string &mark,  int &num,  Kind &type,  bool &load,  string &dest, StringOfCars &string1, string &k)
{
    ptr = new Car;
    ptr -> setUp(mark, num, type, load, dest, k);
    string1.push(*ptr);

}

void buildFreightCar(FreightCar *&ptr,  string &mark,  int &num,  Kind &type,  bool &load,  string &dest, StringOfCars &string1, string &k)
{
    int i=0;
    ptr = new FreightCar;
    ptr -> setUp(mark, num, type, load, dest, k);
    i++;
    cout << i;
    string1.push(*ptr);


}

void buildPassengerCar(PassengerCar *&ptr,  string &mark,  int &num,  Kind &type,  bool &load,  string &dest, StringOfCars &string1, string &k)
{
    ptr = new PassengerCar;
    ptr -> setUp(mark, num, type, load, dest, k);
    string1.push(*ptr);


}

