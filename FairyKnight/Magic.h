#pragma once
#include <string>
#include <iostream>
#include<istream>
#include<ostream>
using std::string;
using std::istream; using std::ostream;
class Magic
{
protected:
	string element;
	int power_of_spell;
	bool isCursed;
public:
	Magic();
	Magic(string, int, bool);
	Magic& operator=(const Magic&);
	void SetInformationMagic();
	void Description_of_magic();
	friend ostream& operator<< (ostream&, const Magic&);
	friend istream& operator>> (istream&, Magic&);
	virtual void Use_magic();
	virtual ~Magic();
};