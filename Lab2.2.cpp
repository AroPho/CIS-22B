#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Car
{
    private:
        string reportingMark;
        int carNumber;
        string kind;
        bool loaded;
        string destination;
    public:
        void setUpCar(string mark, int num, string type, bool load, string dest)
        {
            reportingMark = mark;
            carNumber = num;
            kind = type;
            loaded = load;
            destination = dest;
        }

        ~Car()
        {

        };


};

void input(string &mark, int &num, string &type, bool &load, string &dest);
void output(string mark, int num, string type, bool load, string dest);

int main()
{
    string mark;
    int num;
    string type;
    bool load;
    string dest;

    input(mark, num, type, load, dest);
    output(mark, num, type, load, dest);

    Car* thecar = new Car();
    thecar -> setUpCar(mark, num, type, load, dest);
    delete[] thecar;
    thecar = NULL;
    return 0;

}

void input(string &mark, int &num, string &type, bool &load, string &dest)
{
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
}
void output(string mark, int num, string type, bool load, string dest)
{
    cout << "\n" << "*****Car Data*****" << "\n\n";
    cout << "Car Mark: " << mark << "\n";
    cout << "Car Number: " << num << "\n";
    cout << "Car Type: " << type << "\n";
    cout << "Car Load: " << boolalpha << load << "\n";
    cout << "Car Destination: " << dest << "\n";
}
