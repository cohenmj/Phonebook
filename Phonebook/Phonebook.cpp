// Assignment #2
// Michael Cohen

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXENTRIES = 10;
const int MAXFIELDS = 2;
const int MAXSIZE = 50;

void duplicateCheck(char book[MAXENTRIES][MAXFIELDS][MAXSIZE]);
void addEntry(char book[MAXENTRIES][MAXFIELDS][MAXSIZE]);
void displayEntries(char book[MAXENTRIES][MAXFIELDS][MAXSIZE]);


char phoneBook[MAXENTRIES][MAXFIELDS][MAXSIZE];
static int i = 0;

int main()
{
	char selection;
	
	do
	{
		cout << "-----------------------" << endl;
		cout << "What do you want to do?" << endl;
		cout << "-----------------------" << endl;
		cout << "[A]dd new entry - Enter A" << endl;
		cout << "[D]isplay - Enter D" << endl;
		cout << "[Q]uit - Enter Q" << endl;
		cin >> selection;
		
		

		if ((selection == 'A' || selection == 'a'))
		{
			if (i < 10)
			{
				addEntry(phoneBook);
				duplicateCheck(phoneBook);
			}

			else
			{
				cout << "Your Phonebook is full!" << endl;
			}


		}
		else if (selection == 'D' || selection == 'd')
		{
			cout << "=================================================" << endl;
			cout << "\tPhonebook Entries" << endl;
			displayEntries(phoneBook);
			cout << "=================================================" << endl;
		}
		else if (selection == 'Q' || selection == 'q')
		{
			break;												//Will exit the Do-While Loop and End the Program
		}
		else
		{
			cout << "Please Enter a Valid Entry!!!!!" << endl;
		}
		
	} while (true);

	return 0;

}

void duplicateCheck(char book[MAXENTRIES][MAXFIELDS][MAXSIZE]) //Function to Check Duplicates 
{							//Jake Happersett helped me create this check 
	for (int a = -1; a < i - 1; a++)
	{
		if ((strcmp(book[a][0], book[i - 1][0]) == 0) && (i - 1 != 0)) //Will compare current list (output will be 0 if true) and making sure the count variable does not equal 0
		{					

			cout << "Please Enter a Valid Entry Next Time! Hit Enter to Continue" << endl;
			i--;
			addEntry(book);
			break;
		}
	}
}
void addEntry(char book[MAXENTRIES][MAXFIELDS][MAXSIZE]) //Function to Add Phonebook Entry
{
	cin.clear();
	cin.ignore();	
	cout << "Entry " << i + 1 << endl;
	cout << "Please Enter A Name?" << endl;  
	cin.getline(book[i][0], 50);									
	cout << "Please Enter A Phone Number with that Name:" << endl;
	cin.getline(book[i][1], 50);
	i++;
}

void displayEntries(char book[MAXENTRIES][MAXFIELDS][MAXSIZE]) //Function to Display Entries (up to 10)
{
	for (int b = 0; b < i; b++)
	{
		cout << "Entry " << b + 1 << " Name: " << book[b][0] << "\tNumber: " << book[b][1] << endl;	
	}
}
