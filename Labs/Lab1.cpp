#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

void getSize(int&);
void getSpace(int&, string*);
void inputData();
void printData();
void destory();

int main()
{
    int num;
    string fuck;
    getSize(num);
    cout << num;
    getSpace(num, &fuck);



}

void getSize(int &num)
{
    cout << "How many strings do you want?" << "\n";
    cin >> num;
}

void getSpace(int num, string *fuck)
{

}
