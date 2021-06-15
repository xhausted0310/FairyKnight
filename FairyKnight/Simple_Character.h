#pragma once
#include <string>
#include <iostream>
#include<istream>
#include<ostream>
using std::string;
using std::istream; using std::ostream;
class Simple_Character
{
protected:
	char* name = new char[50];
	int age;
	char gender;
	string town;
	string GenderState();
public:
	Simple_Character();
	Simple_Character(char*, int, char, string);
	Simple_Character(const Simple_Character&);
	virtual void Attack();
	virtual void SetInformation();
	virtual void Run();
	virtual void Description();
	friend ostream& operator<< (ostream& os, const Simple_Character&);
	friend istream& operator>> (istream& is, Simple_Character&);
	virtual ~Simple_Character();
};