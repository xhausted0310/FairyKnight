#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#include "Simple_Character.h"
using std::cout; using std::endl; using std::cin;
string Simple_Character::GenderState()
{
	if (this->gender == 'F') {
		return "her";
	}
	else if(this->gender == 'M')
	{
		return "his";
	}
}Simple_Character::Simple_Character() {
	strcpy_s(this->name,50, "-");
	this->age = 0;
	this->gender = '-';
	this->town = "-";
}Simple_Character::Simple_Character(char* name, int age, char gender, string town)
{
	strcpy_s(this->name,50, name);
	this->age = age;
	this->gender = gender;
	this->town = town;
}Simple_Character::Simple_Character(const Simple_Character& other)
{
	strcpy_s(this->name,50, other.name);
	this->age = other.age;
	this->gender = other.gender;
	this->town = other.town;
}
void Simple_Character::Attack() {
	cout << this->name << " attacks! However so weak." << endl;
}void Simple_Character::SetInformation()
{
	cin >> *this;
}
void Simple_Character::Run() {
	cout << this->name << " is running!" << endl;
}
void Simple_Character::Description() {
	cout << typeid(*this).name() << endl;
	cout << *this << endl;
}Simple_Character::~Simple_Character()
{
	if (this->name != nullptr) {
		delete[] this->name;
		cout << "Name was deleted!" << endl;
	}
	cout << "Simple Character: " << this << " was deleted!" << endl;
}
ostream& operator<<(ostream& os, const Simple_Character& character)
{
	os << "Name: " << character.name << endl;
	os << "Age: " << character.age << endl;
	os << "Gender: " << character.gender << endl;
	os << "Town: " << character.town << endl;
	return os;
}
istream& operator>>(istream& is, Simple_Character& character)
{
	cout << "Input name: ";
	is.getline(character.name, 50);
	cout << "Input age: ";
	is >> character.age;
	cout << "Input gender: ";
	is >> character.gender;
	is.ignore();
	cout << "Input town: ";
	getline(is, character.town);
	return is;
}