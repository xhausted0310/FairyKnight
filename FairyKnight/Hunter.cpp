#include "Hunter.h"
#include <iostream>
using std::cout; using std::endl; using std::cin;
Hunter::Hunter() :Simple_Character()
{
	this->Simple_Character::age = 0;
	this->power = 0;
	this->defence = 0;
	this->endurance = 0;
	this->sword = "stick";
}Hunter::Hunter(char* name, int age, char gender, string town, int power, int defence, int endurance, string sword) :Simple_Character(name, Hunter::age, gender,town)
{
	this->Simple_Character::age = age;
	this->power = power;
	this->defence = defence;
	this->endurance = endurance;
	this->sword = sword;
}
Hunter::Hunter(const Hunter& other) :Simple_Character(other)
{
	this->power = other.power;
	this->defence = other.defence;
	this->endurance = other.endurance;
	this->sword = other.sword;
}void Hunter::Attack()
{
	cout << this->name << " attacks using " << GenderState() << " " << this -> sword << "!" << endl;
}
void Hunter::Run()
{
	cout << this->name << " is running! His endurance = " << this->endurance <<endl;
}void Hunter::Description()
{
	cout << typeid(*this).name() << endl;
	cout << *this << endl;
}
void Hunter::SetInformation()
{
	cin >> *this;
}
void Hunter::Combo_Attack()
{
	cout << this->name << " uses combo attack with " << GenderState() << " " <<this->sword << endl;
}
void Hunter::Special_Attack()
{
	cout << this->name << " uses special attack with " << GenderState() << " "<< this->sword << endl;
}
void Hunter::Collect(string thing)
{
	cout << this->name << " collects " << thing << endl;
}ostream& operator<<(ostream& os, const Hunter& hunter)
{
	os << (Simple_Character&)hunter;
	os << "Power: " << hunter.power << endl;
	os << "Defence: " << hunter.defence << endl;
	os << "Endurance: " << hunter.endurance << endl;
	os << "Sword: " << hunter.sword << endl;
	return os;
}
istream& operator>>(istream& is, Hunter& hunter)
{
	is >> (Simple_Character&)hunter;
	cout << "Input power: ";
	is >> hunter.power;
	cout << "Input defence: ";
	is >> hunter.defence;
	cout << "Input endurance: ";
	is >> hunter.endurance;
	is.ignore();
	cout << "Input sword: ";
	getline(is, hunter.sword);
	return is;
}Hunter::~Hunter()
{
	cout << "Hunter " << this << " was deleted!" << endl;
}
