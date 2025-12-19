/*
* Menu Option functions
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "PrintDisplay.h"
using namespace std;

/*
* I used class objects to store every item listed in the input file
*/
class Item 
{
public:
	void SetName(string itemName);                
	void UpdateCount();    
	string GetName();
	int GetCount();
	void Print();
	void Print2();

private:
	string name;
	int count = 1;
};

//Name mutator
void Item::SetName(string itemName)
{
	name = itemName;
}

//Count mutator/updater
void Item::UpdateCount()
{
	count = count + 1;
}

//Name accessor
string Item::GetName()
{
	return name;
}

//Count accessor
int Item::GetCount()
{
	return count;
}

//Print() is for the Option 2 output.
void Item::Print()
{
	cout << left << setw(14) << name << ":   " << count << endl;
}

//Print2() is for the Option 3 output.
void Item::Print2()
{
	cout << left << setw(14) << name << ":   " << string(count, '*') << endl;
}



/*
* Option 1, takes a string input then scans through the whole file and check for matches.
* If a match is found, int count is increased by 1.
* Displays the name and count.
*/
void Menu1()
{
	string input;
	ifstream inFS;
	int count = 0;
	string temp;

	cout << endl;
	cout << "Option 1" << endl;
	cout << "Enter the name of item to search. (Ex: Potatoes)" << endl;
	cout << "Input: ";
	cin >> input;
	cout << endl;

	cout << "Opening file";
	inFS.open("CS210 Project Three Input File.txt");
	if (!inFS.is_open())
	{
		cout << "Could not open CS210 Project Three Input File.txt." << endl;
		cout << "Please call support!" << endl;
		return;
	}

	cout << endl << "Searching for " << input << ".   In Progress" << endl;
	
	while (getline(inFS, temp))
	{
		if (input == temp)
		{
			count += 1;
		}
	}

	cout << "Searching for " << input << ".   Completed" << endl;
	cout << endl;

	cout << input << ": " << count << endl << endl;
	PrintBreak(); 

	if (!inFS.eof())
	{
		cout << "Input failure before reaching end of file." << endl;
	}

	cout << "Closing file." << endl << endl;
	inFS.close();

	cout << endl;

}

/*
* Option 2, creates a vector itemList
* Takes the string on every line using inFS >> temp.
* temp is used to create a currentItem object.
* currentItem object is checked if it's in vector. If not, push_back is executed to insert it in vector list.
*/
void Menu2()
{
	vector<Item> itemList(0);
	ifstream inFS;
	string temp;
	Item currentItem;

	cout << endl;
	cout << "Option 2" << endl;
	cout << endl;

	cout << "Opening file";
	inFS.open("CS210 Project Three Input File.txt");
	if (!inFS.is_open())
	{
		cout << "CS210 Project Three Input File.txt." << endl;
		cout << "Please call support!" << endl;
		return;
	}

	cout << endl << "Reading data...   In Progress" << endl;

	while (getline(inFS, temp))
	{
		bool isInList = false;

		currentItem.SetName(temp);

		for (int i = 0; i < itemList.size(); i++)
		{
			if (currentItem.GetName() == itemList[i].GetName())
			{
				itemList[i].UpdateCount();
				isInList = true;
				break;
			}
		}

		if (!isInList)
		{
			itemList.push_back(currentItem);
			
		}
			
	}
	cout << "Reading data...   Completed" << endl << endl;
	
	for (int i = 0; i < itemList.size(); i++)
	{
		itemList[i].Print();
	}

	cout << endl;
	PrintBreak();

	if (!inFS.eof())
	{
		cout << "Input failure before reaching end of file." << endl;
	}

	cout << "Closing file." << endl << endl;
	inFS.close();

	cout << endl;

}

/*
* Same concept as Menu2, only difference is the output.
*/
void Menu3()
{
	vector<Item> itemList(0);
	ifstream inFS;
	string temp;
	Item currentItem;

	cout << endl;
	cout << "Option 2" << endl;
	cout << endl;

	cout << "Opening file";
	inFS.open("CS210 Project Three Input File.txt");
	if (!inFS.is_open())
	{
		cout << "CS210 Project Three Input File.txt." << endl;
		cout << "Please call support!" << endl;
		return;
	}

	cout << endl << "Reading data...   In Progress" << endl;

	while (getline(inFS, temp))
	{
		bool isInList = false;

		currentItem.SetName(temp);

		for (int i = 0; i < itemList.size(); i++)
		{
			if (currentItem.GetName() == itemList[i].GetName())
			{
				itemList[i].UpdateCount();
				isInList = true;
				break;
			}
		}

		if (!isInList)
		{
			itemList.push_back(currentItem);

		}

	}

	cout << "Reading data...   Completed" << endl << endl;

	for (int i = 0; i < itemList.size(); i++)
	{
		itemList[i].Print2();
	}

	cout << endl;
	PrintBreak();

	if (!inFS.eof())
	{
		cout << "Input failure before reaching end of file." << endl;
	}

	cout << "Closing file." << endl << endl;
	inFS.close();

	cout << endl;

}

/*
* Same concept as Menu2, just output the result to frequency.dat file
*/
void Backup()
{
	vector<Item> itemList(0);
	ifstream inFS;
	string temp;
	Item currentItem;

	inFS.open("CS210 Project Three Input File.txt");
	if (!inFS.is_open())
	{
		cout << "CS210 Project Three Input File.txt." << endl;
		cout << "Please call support!" << endl;
		return;
	}

	while (getline(inFS, temp))
	{
		bool isInList = false;

		currentItem.SetName(temp);

		for (int i = 0; i < itemList.size(); i++)
		{
			if (currentItem.GetName() == itemList[i].GetName())
			{
				itemList[i].UpdateCount();
				isInList = true;
				break;
			}
		}

		if (!isInList)
		{
			itemList.push_back(currentItem);

		}

	}



	if (!inFS.eof())
	{
		cout << "Input failure before reaching end of file." << endl;
	}

	inFS.close();

	ofstream outFS;
	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open file frequency.dat" << endl;
	}

	for (int i = 0; i < itemList.size(); i++)
	{
		outFS << left << setw(14) << itemList[i].GetName() << ":   " << itemList[i].GetCount() << endl;
	}

	cout << endl;
}

