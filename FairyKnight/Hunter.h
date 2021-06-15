#pragma once
#include "Simple_Character.h"
#include <istream>
#include <ostream>
class Hunter :
	public virtual Simple_Character
{
protected:
	int age;
	int power;
	int defence;
	int endurance;
	string sword;
public:
	Hunter();
	Hunter(char*, int, char, string, int, int, int, string);
	Hunter(const Hunter&);
	void Attack() override;
	void Run() override;
	void Description() override;
	void SetInformation() override;
	virtual void Combo_Attack();
	virtual void Special_Attack();
	friend ostream& operator<< (ostream&, const Hunter&);
	friend istream& operator>> (istream&, Hunter&);
	void Collect(string thing);
	~Hunter() override;
};

