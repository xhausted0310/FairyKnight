#pragma once
#include "Hunter.h"
#include "Wizard.h"
#include <istream>
#include <ostream>
class Fairy_Knight :
	protected virtual Wizard, public virtual  Hunter
{
	int scale_of_poison;
	bool hasShield;
	int speed;
public:
	Fairy_Knight();
	Fairy_Knight(char*, int, char, string, int, int, int, string, string, int,
		bool, int, bool, int);
	Fairy_Knight(const Fairy_Knight&);
	void Description() override;
	void Use_magic() override;
	void SetInformation() override;
	void Combo_Attack() override;
	void Special_Attack() override;

	friend ostream& operator<< (ostream&, Fairy_Knight&);
	friend istream& operator>> (istream&, Fairy_Knight&);
	~Fairy_Knight();
};

