#pragma once
#include <string>
#ifndef PIRATEDICTIONARYTERM_H
#define PIRATEDICTIONARYTERM_H
using namespace std;

class PirateDictionaryTerm
{
private:
	string m_englishTerm;
	string m_pirateTerm;
	PirateDictionaryTerm(void);

public:	
	PirateDictionaryTerm(string, string);
	~PirateDictionaryTerm(void);
	string getEnglishTerm(void);
	string getPirateTerm(void);
	void setEnglishTerm(string);
	void setPirateTerm(string);
	bool operator< (const PirateDictionaryTerm& rhs) const;
	string toString(void);
};
#endif

