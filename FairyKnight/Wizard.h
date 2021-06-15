#pragma once
#include "Magic.h"
#include "Simple_Character.h"
#include <istream>
#include <ostream>
class Wizard :
	public virtual Magic, protected virtual Simple_Character
{
protected:
	int times_of_using_spell = 5;
	int critATK;
	int elementalATK;
public:
	Wizard();
	Wizard(char*, int, char, string, string, int, bool, int, int);
	Wizard(const Wizard&);
	void Description() override;
	void SetInformation() override;
	void Use_magic() override;
	void Special_Magic();
	void Recharge();
	friend ostream& operator<< (ostream&, Wizard&);
	friend istream& operator>> (istream&, Wizard&);
	~Wizard() override;

};

