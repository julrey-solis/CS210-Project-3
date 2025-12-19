/*
* CS210 Project Three
* Julrey Solis
* 12/13/2025
*/


#include <iostream>
#include <string>

using namespace std;

#include "PrintDisplay.h"           //Include PrintDisplay.h header file to call on functions from the PrintDisplay.cpp file.
#include "Menu.h"                   //Includes Menu.h header file to call on functions for every menu option in Menu.cpp file.



int main()
{
    int x = 0;

    PrintGreetingsMessage();            //Greeting message only, nothing special.
    
    Backup();                           //This is the function create output file frequency.dat

    /*
    * Loop to keep executing the menu option until user enter 4 to quit program.
    */
    do
    {

        /*
        * Optional Challenge
        * Try throw catch statement for invalid input ( if int x less than 1 OR more than 4)
        */
        try
        {
            PrintMenuBox();                     //Menu Box only, nothing special.
            PrintMenu();                        //Function to print options.

            /*
            * Optional Challenge
            * This if statement and its content is to thrown runtime error if customer enters a string / character.
            * Got this from online search, not included in Zybooks material.
            */
            if (!(cin >> x)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input type. Please enter a number.");
            }


            if ((x < 1) || (x > 4))
            {
                throw runtime_error("Invalid input.");
            }


            if (x == 1)
            {
                Menu1();
            }

            else if (x == 2)
            {
                Menu2();
            }

            else if (x == 3)
            {
                Menu3();
            }

        }
        catch (runtime_error& excpt)
        {
            cout << excpt.what() << endl;
            cout << "Please try again" << endl << endl;
            PrintBreak();
        }
    } while (x != 4);

    
    cout << endl;
    cout << "Thank you for using Corner Grocer App!!!" << endl;       // Ending note.
    PrintBreak();  

    return 0;
}

