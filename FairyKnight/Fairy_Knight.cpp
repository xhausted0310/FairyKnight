#include "Fairy_Knight.h"
#include <iostream>
#include <istream>
#include <ostream>
using std::cout; using std::endl; using std::cin;
Fairy_Knight::Fairy_Knight() :Simple_Character(), Hunter(), Magic()
{
	this->scale_of_poison = 0;
	this->hasShield = false;
	this->speed = 0;
}
Fairy_Knight::Fairy_Knight(char* name, int age, char gender, string town, int power, int defence, int endurance, string sword, string element, int power_of_spell, bool isCursed, int scale_of_poison, bool hasShield, int speed) :Simple_Character(name, age, gender, town), Hunter(name, age, gender, town, power, defence, endurance, sword), Magic(element, power_of_spell, isCursed)
{
	this->scale_of_poison = scale_of_poison;
	this->hasShield = hasShield;
	this->speed = speed;
}
Fairy_Knight::Fairy_Knight(const Fairy_Knight& other) :Simple_Character(other), Hunter(other), Magic(other)
{
	this->scale_of_poison = other.scale_of_poison;
	this->hasShield = other.hasShield;
	this->speed = other.speed;
}
void Fairy_Knight::Description()
{
	cout << typeid(*this).name() << endl;
	cout << *this << endl;
}
void Fairy_Knight::Use_magic()
{
	if (this->times_of_using_spell > 0) {
		cout << this->name << " uses " << this->GenderState() << " magic " <<this->element << " with " << this->GenderState() << " " << this->sword << endl;
		this->times_of_using_spell--;
	}
	else {
		cout << this->name << " has not enough manna!" << endl;
	}
}void Fairy_Knight::SetInformation()
{
	cin >> *this;
}void Fairy_Knight::Combo_Attack()
{
	cout << this->name << " uses combo attack " << this->GenderState() << " magic " << this->element << " with " << this->GenderState() << " " << this->sword << endl;
}void Fairy_Knight::Special_Attack()
{
	cout << this->name << " uses special attack " << this->GenderState() << " magic " << this->element << " with " << this->GenderState() << " " << this->sword << endl;
	this->Recharge();
}Fairy_Knight::~Fairy_Knight()
{
	cout << "Fairy knight " << this << " was deleted!" << endl;
}ostream& operator<<(ostream& os, Fairy_Knight& knight)
{
	os << "Name: " << knight.name << endl;
	os << "Age: " << knight.age << endl;
	os << "Gender: " << knight.gender << endl;
	os << "Town: " << knight.town << endl;
	os << "Power: " << knight.power << endl;
	os << "Defence: " << knight.defence << endl;
	os << "Endurance: " << knight.endurance << endl;
	os << "Sword: " << knight.sword << endl;
	knight.Description_of_magic();
	os << "Scale of poison: " << knight.scale_of_poison << endl;
	os << "Has Shield(1/0): " << knight.hasShield << endl;
	os << "Speed: " << knight.speed << endl;
	return os;
}istream& operator>>(istream& is, Fairy_Knight& knight)
{
	cout << "Name: " << endl;
	is >> knight.name;
	cout << "Age: " << endl;
	is >> knight.age;
	cout << "Gender: " << endl;
	is >> knight.gender;
	cout << "Town: " << endl;
	is >> knight.town;
	cout << "Power: " << endl;
	is>>knight.power;
	cout << "Defence: " << endl;
	is >> knight.defence;
	cout << "Endurance: " << endl;
	is >> knight.endurance;
	cout << "Sword: " << endl;
	is >> knight.sword;
	cout << "Magic: " << endl;
	knight.Description_of_magic();
	cout << "Input scale of poison: ";
	is >> knight.scale_of_poison;
	cout << "Input HasShield(1/0): ";
	is >> knight.hasShield;
	cout << "Input speed: ";
	is >> knight.speed;
	return is;
}