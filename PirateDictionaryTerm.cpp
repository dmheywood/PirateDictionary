#include "stdafx.h"
#include "PirateDictionaryTerm.h"
#include <iomanip>


PirateDictionaryTerm::PirateDictionaryTerm(void)
{
}

PirateDictionaryTerm::PirateDictionaryTerm(string englishTerm, string pirateTerm)
{
	m_englishTerm = englishTerm;
	m_pirateTerm = pirateTerm;
}


PirateDictionaryTerm::~PirateDictionaryTerm(void)
{
}

string PirateDictionaryTerm::getEnglishTerm(void)
{
	return m_englishTerm;
}

string PirateDictionaryTerm::getPirateTerm(void)
{
	return m_pirateTerm;
}

void PirateDictionaryTerm::setEnglishTerm(string englishTerm)
{
	m_englishTerm = englishTerm;
}

void PirateDictionaryTerm::setPirateTerm(string pirateTerm)
{
	m_pirateTerm = pirateTerm;
}

// returns true if current object's english text is shorter, false otherwise.
bool PirateDictionaryTerm::operator< (const PirateDictionaryTerm& rhs) const {
  if (rhs.m_englishTerm.length() > m_englishTerm.length()) {
    return true;
  }
  return false;
}

string PirateDictionaryTerm::toString(void)
{
	return "English Term: " + m_englishTerm + "\n" + "Pirate Term: " + m_pirateTerm + "\n\n";
}