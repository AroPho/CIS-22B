#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void getSize(int&);
void getSpace(int , string*&);
void inputData(int , string*);
void printData(int num, string*);
void destroy(string*);

int main()
{
    int num;
    string *array1;
    getSize(num);
    getSpace(num, array1);
    inputData(num, array1);
    printData(num, array1);



}

void getSize(int &num)
{
    cout << "How many strings do you want?" << "\n";
    cin >> num;
}

void getSpace(int num, string *&array1)
{
    array1 = new string[num];
}

void inputData(int num, string *array1)
{

    for( int x = 0; x < num; x++ )
    {
        string st1;
        cout << "Please enter String " << x + 1 << "\n";
        getline(cin,st1);
        array1[x] = st1;
        //cout << st1[x] << "\n";
    }
}

void printData(int num, string *array1)
{
   for( int x = 0; x < num; x++ )
   {
       cout << array1[x] << "\n";
   }

}


