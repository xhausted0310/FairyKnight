#include "Magic.h"
#include <iostream>
using std::cout; using std::endl; using std::cin;

Magic::Magic()
{
	this->element = "-";
	this->power_of_spell = 0;
	this->isCursed = false;
}Magic::Magic(string element, int power_of_spell, bool isCursed)
{
	this->element = element;
	this->power_of_spell = power_of_spell;
	this->isCursed = isCursed;
}
Magic& Magic::operator=(const Magic& other)
{
	this->element = other.element;
	this->power_of_spell = other.power_of_spell;
	this->isCursed = other.isCursed;
	return *this;
}void Magic::SetInformationMagic()
{
	cout << "Input element: ";
	getline(cin, this->element);
	cout << "Input power of spell: ";
	cin >> this->power_of_spell;
	cout << "Input isCursed(1/0): ";
	cin >> this->isCursed;
	cin.ignore();
}void Magic::Description_of_magic()
{
	cout << "Element:" << this->element << endl;
	cout << "Power of spell: " << this->power_of_spell << endl;
}
void Magic::Use_magic()
{
	cout << "WOW! Magic" << endl;
}
Magic::~Magic()
{
	cout << "Magic: " << this << " was deleted!" << endl;
}ostream& operator<<(ostream& os, Magic& magic)
{
	magic.Description_of_magic();
	return os;
}
istream& operator>>(istream& is, Magic& magic)
{
	magic.SetInformationMagic();
	return is;
}