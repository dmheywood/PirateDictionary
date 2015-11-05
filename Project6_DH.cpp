// Project6_DH.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PirateDictionaryTerm.h"
#include "PirateDictionary.h"
#include <string>
#include <iostream>
using namespace std;

void printMenu();
void getNewTerms(string& englishTerm, string& pirateTerm);
string getPhrase();

int _tmain(int argc, _TCHAR* argv[])
{
	PirateDictionary foo("pirateTerms.txt");
	string englishTerm;
	string pirateTerm;	
	char menuOption;

	do
	{
		printMenu();
		cin >> menuOption;		
		if (menuOption == 'A' || menuOption == 'a')
		{			
			getNewTerms(englishTerm, pirateTerm);
			foo.addTerm(englishTerm, pirateTerm);
		} else if (menuOption == 'P' || menuOption == 'p')
		{
			cout << foo.toString();
		} else if  ( menuOption == 'T' || menuOption =='t')
		{
			string sentence = getPhrase();
			string translatedSentence = foo.translate(sentence);
			cout << translatedSentence + "\n\n";
		}

	} while (menuOption != 'Q' && menuOption != 'q');

	return 0;
}

// Prints the menu of choices to the console
void printMenu()
{	
	cout << "Welcome to the Pirate Translator!" << endl;
	cout << "*********************************" << endl;
	cout << "What would you like to do?" << endl;
	cout << "Type a letter:" << endl;
	cout << "'A' - Add to the dictionary" << endl;
	cout << "'P' - Print the dictionary" << endl;
	cout << "'T' = Translate a phrase" << endl;
	cout << "'Q' - Quit" << endl;	
}

//// Asks the user for a new English term and a new pirate term, and returns them
void getNewTerms(string& englishTerm, string& pirateTerm)
{
	cout << "What is the english word?" << endl;
	cin.ignore();
	getline(cin, englishTerm);
	cout << "\nWhat is the pirate word?" << endl;
	getline(cin, pirateTerm);	
}

// Asks the user for an English phrase to translate
string getPhrase()
{	
	string phrase;
	cout << "Please type the english phrase to translate: " << endl;
	cin.ignore();
	getline(cin, phrase);

	return phrase;
}

