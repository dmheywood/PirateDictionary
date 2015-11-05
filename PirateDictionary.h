#pragma once
#include <vector>
#include <string>
#include "PirateDictionaryTerm.h"
#ifndef PIRATEDICTIONARY_H
#define PIRATEDICTIONARY_H
using namespace std;

class PirateDictionary
{
private:
	// Private default constructor
	PirateDictionary(void); // Will initialize the vector
	vector<PirateDictionaryTerm> m_pirateVector; // A vector of PirateDictionaryTerm objects	
	string m_pirateTerms; // A string containing the name of the data file

	void readDictionaryData(); // Private method that reads in the data from the file and populates the vector
	void writeDictionaryData(); // Private method that writes the dictionary to the data file

	void sortDictionary();

public:
	// Public constructor
	PirateDictionary(string); // Takes a string that is the data file. Calls readDictionaryData() to populate vector

	// Public destructor
	~PirateDictionary(void); // Calls writeDictionaryData() to write dictionary to file before dictionary is destroyed

	string translate(const string&); // string contains the english word to translate
	
	
	void addTerm(string, string); // Given a pirate word/phrase and an english word/phrase, add them to the dictionary

	string toString(void);
};
#endif
