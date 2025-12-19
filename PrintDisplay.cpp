#include <iostream>
#include "PrintDisplay.h"
#include <conio.h>          // for press any key stroke
#include <iomanip>			// for setw and setfill
using namespace std;

void PrintGreetingsMessage()
{
    cout << endl;
    cout << string(28, '*') << endl;
    std::cout << "* Welcome to Corner Grocer *" << endl;
    cout << string(28, '*') << endl;
    cout << endl;

    return;
}


void PrintMenuBox()
{
    cout << endl;
    cout << string(8, '*') << endl;
    std::cout << "* Menu *" << endl;
    cout << string(8, '*') << endl;
    cout << endl;

}

void PrintMenu()
{
    cout << endl;
    cout << "Enter 1: Search word and count." << endl;
    cout << "Enter 2: Print the list of all words and their count." << endl;
    cout << "Enter 3: Print the list in the form of histogram." << endl;
    cout << endl;
    cout << "Enter 4: To exit." << endl;
    cout << endl << "Input: ";
}

void PrintBreak()
{
    cout << "Press any key to continue ...";
    _getch();
    cout << endl;
    return;
}