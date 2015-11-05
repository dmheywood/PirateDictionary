#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "PirateDictionary.h"
#include <algorithm>


PirateDictionary::PirateDictionary(void)
{	
}

PirateDictionary::~PirateDictionary(void)
{
	writeDictionaryData();
}

PirateDictionary::PirateDictionary(string dictionary)
{
	m_pirateTerms = dictionary;
	readDictionaryData();
}

void PirateDictionary::readDictionaryData()
{
	cerr << "reading data" << endl;

	ifstream in; // an input stream
	in.open(m_pirateTerms);

	// check to see if the open failed
	if (in.fail()) {
		cout << "Couldn't open the file " << m_pirateTerms << " for reading." << endl;

	}else
	{
		while (!in.eof())
		{
			string englishTerm;
			string pirateTerm;
			getline(in, englishTerm, '#');

			getline(in, pirateTerm);
			addTerm(englishTerm, pirateTerm);
		}
	}
	in.close();
}

void PirateDictionary::writeDictionaryData()
{
	cerr << "writing data" << endl;

	ofstream out;
	out.open(m_pirateTerms);

	if (out.fail())
	{
		cout << "Couldn't open file "  << m_pirateTerms << " for writing. " << endl;
	} else
	{
		string englishTerm = m_pirateVector[0].getEnglishTerm();
		string pirateTerm = m_pirateVector[0].getPirateTerm();

		out << englishTerm << "#" << pirateTerm;
		
		for (int i = 1; i < m_pirateVector.size(); i++)
		{
			englishTerm = m_pirateVector[i].getEnglishTerm();
			pirateTerm = m_pirateVector[i].getPirateTerm();
			out << "\n" << englishTerm << "#" << pirateTerm;
		}
	}
}

// writes the term to the vector
void PirateDictionary::addTerm(string englishTerm, string pirateTerm)
{
	PirateDictionaryTerm foo(englishTerm, pirateTerm);
	m_pirateVector.push_back(foo);
}

// Sorts the PirateDictionaryTerm vector so that the term with the longest
// English phrase is the first and the shortest English phrase is last
void PirateDictionary::sortDictionary()
{
	sort(m_pirateVector.begin(), m_pirateVector.end());
	reverse(m_pirateVector.begin(), m_pirateVector.end());
}

// Sorts the dictionary, and then substitutes English phrases for pirate phrases
// found in the dictionary
string PirateDictionary::translate(const string& sentence)
{
	sortDictionary();
	string s1(sentence);
	for (int i = 0; i < m_pirateVector.size(); i++)
	{		
		string findStr = m_pirateVector[i].getEnglishTerm();
		string replaceStr = m_pirateVector[i].getPirateTerm();

		std::size_t foundIndex = s1.rfind(findStr, s1.size()-1); // start at the end of the string
		while (foundIndex != std::string::npos) // loop until the match is no longer found
		{
			s1.replace(foundIndex, findStr.length(), replaceStr); // replace the matched string with the replacement string
			foundIndex = s1.rfind(findStr, foundIndex-1); // look for a match earlier in the string
		}		
	}
	return s1;
}


string PirateDictionary::toString(void)
{
	string termString = "";
	for (int i = 0; i < m_pirateVector.size(); i++)
	{
		termString += m_pirateVector[i].toString();
	}
	return termString;
}