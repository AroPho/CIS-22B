/*
Aaron Nguyen
Summer 2018
Lab 1
Problem 1.2
Description of Problem:
Meant to demonstrate ability to manipulate strings in various ways.
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
void last_of(int&, string);


int main()
{
    int y; /* Int used later in program as a counter */

    /* Exercise 1 */

    string string1;
    cout << "Please input a string." << "\n" << "\n";
    getline(cin,string1); /* Takes users input */
    cout << "Exercise 1" << "\n" << string1 << "\n";

    cout << "\n"; /*This skips a line to make the terminal output look
                    better to me (Used multiple times in the following code*/

    /* Exercise 2 */

    string string2 = string1;
    string2 = string1 + " sleepy heads"; /* combines 2 strings into one string */
    cout << "Exercise 2" << "\n" << string2 << "\n";

    cout << "\n";

    /* Exercise 3 */

    string string3 = "bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow";

   /* For loop that compares a string to a character starting from the start of the string to locate first appearance of character in string*/
    for ( int x = 0; x < string3.length(); x++ )
    {
        if( string3[x] == 'h')
        {
            cout << "Exercise 3" << "\n" << "The first h is at column " << x << "\n";
            y = x;
            break;
        }
        else
        {
        }
    }

    cout << "\n";

    /* Exercise 4 */

    string string4;
    string4 = string3;
    string4[y] = 'j'; /* Changes a specific character in a specific location to j */
    cout << "Exercise 4" << "\n" << string4 << "\n";

    cout << "\n";

    /* Exercise 5 */

    string string5 = string3;
    cout << "Exercise 5" << "\n";
    last_of(y, string5);

    cout << "\n";

    /* Exercise 6 */

    string string6 = string3;
    string6.erase(y + 1);
    cout << string6;


}

/* function that is used in Exercise 5 to
get position of last y character in string*/

void last_of(int &y, string string5) /* Function that has a loop that compares a string to a character starting with the last character of the string */
{
    int x = string5.length();
    x--;
    for(x; x >= 0; x--)
    {
        if( string5[x] == 'y' )
        {
            cout << x << "\n";
            y = x;
            break;
        }
        else
        {
        }
    }
}
