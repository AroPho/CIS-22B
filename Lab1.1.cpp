/*
Aaron Nguyen
Summer 2018
Lab 1
Problem 1.1
Description of Problem:
Asks for number of strings and for strings and stores inputed strings in
a point array. Then it outputs Strings, and destroys point array.
*/

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
    destroy(array1);
}

/********************* getSize ********************

Asks users for number of incoming Strings.
size is then saved as an int through reference parameter in function
*/

void getSize(int &num)
{
    cout << "How many strings do you want?" << "\n";
    cin >> num;
    cin.ignore();
}

/*********** getSpace ************
gets an array in heap of the size
requested by the user
*/


void getSpace(int num, string *&array1)
{
    array1 = new string[num];
}

/*********** inputData ************
Allow users to input string values
and store them in the array
*/

void inputData(int num, string *array1)
{

    for( int x = 0; x < num; x++ )
    {
        string st1;
        cout << "Please enter String " << x + 1 << "\n";
        getline(cin,st1);
        array1[x] = st1;
    }
}

/*********** printData ************
Print out all the strings
One string per line
*/

void printData(int num, string *array1)
{
   for( int x = 0; x < num; x++ )
   {
       cout << "String " << x+1 << ": ";
       cout << array1[x] << "\n";
   }

}

/*********** Destroy ************
Return all the space to the heap
*/

void destroy(string *array1)
{
    delete [] array1;
}
