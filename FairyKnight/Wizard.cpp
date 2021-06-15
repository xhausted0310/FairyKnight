#include "Wizard.h"
#include <iostream>
#include <istream>
#include <ostream>
using std::cout; using std::endl; using std::cin;


Wizard::Wizard() :Simple_Character(), Magic()
{
	this->critATK = 0;
	this->elementalATK = 0;
}
Wizard::Wizard(char* name, int age, char gender, string town, string element, int power_of_spell, bool isCursed, int critATK, int elementalATK) : Simple_Character(name, age, gender, town), Magic(element, power_of_spell, isCursed)
{
	this->critATK = critATK;
	this->elementalATK = elementalATK;
}
Wizard::Wizard(const Wizard& other) : Simple_Character(other), Magic(other)
{
	this->critATK = other.critATK;
	this->elementalATK = other.elementalATK;
}void Wizard::Description()
{
	cout << typeid(*this).name() << endl;
	cout << *this << endl;
}
void Wizard::SetInformation()
{
	cin >> *this;
}void Wizard::Use_magic()
{
	if (this->times_of_using_spell > 0)
	{
		cout << this->name << " uses " << this->GenderState() << " magic " <<this->element << endl;
		this->times_of_using_spell--;
	}
	else
	{
		cout << this->name << " has not enough manna!" << endl;
	}
}void Wizard::Special_Magic()
{
	if (this->isCursed)
	{
		cout << this->name << " uses special magic, but get damage from it!"<< endl;
	}
	else {
		cout << this->name << " uses special magic!" << endl;
	}
}
void Wizard::Recharge()
{
	cout << this->name << " recharges " << this->GenderState() << " times of using spell!" << endl;
}
Wizard::~Wizard()
{
	cout << "Wizard " << this << " was deleted!" << endl;
}ostream& operator<<(ostream& os, Wizard& wizard)
{
	os << "Name: " << wizard.name << endl;
	os << "Age: " << wizard.age << endl;
	os << "Gender: " << wizard.gender << endl;
	os << "Town: " << wizard.town << endl; 
	wizard.Description_of_magic();
	os << "CRITatk: " << wizard.critATK << endl;
	os << "ElemATK: " << wizard.elementalATK << endl;
	return os;
}istream& operator>>(istream& is, Wizard& wizard)
{
	cout << "Name: " << endl;
	is >> wizard.name;
	cout << "Age: " << endl;
	is >> wizard.age;
	cout << "Gender: " << endl;
	is >> wizard.gender;
	cout << "Town: " << endl;
	is >> wizard.town;
	cout << "Magic: " << endl;
	wizard.SetInformationMagic();
	cout << "Input critATK: ";
	is >> wizard.critATK;
	cout << "Input elemATK: ";
	is >> wizard.elementalATK;
	is.ignore();
	return is;
}