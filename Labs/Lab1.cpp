#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void getSize(int&);
void getSpace(int , string *array1);
void inputData(int , string *array1);
void printData();
void destory();

int main()
{
    int num;
    string array1;
    getSize(num);
    getSpace(num, &array1);
    inputData(num, &array1);



}

void getSize(int &num)
{
    cout << "How many strings do you want?" << "\n";
    cin >> num;
}

void getSpace(int num, string *array1)
{
    array1 = new string[num];
}

void inputData(int num, string *array1)
{
    for( int x = 0; x < num; x++ )
    {
        cout << "Please enter String " << x + 1 << "\n";
        cin >> array1[x];
    }
}
