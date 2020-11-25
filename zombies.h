#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;
class Zombie
{
public:
	static Zombie *make_zombie(int choice);
	virtual void takeDamage(int d) = 0;
	virtual int getHealth() = 0;
	virtual char getType() = 0;
	virtual void die() = 0;
	virtual bool check() = 0;
	virtual void change(int d) = 0;
	virtual ~Zombie() {};

};

class Reg_Zombie : public Zombie
{
public:
	int health = 50;

	void takeDamage(int d)
	{
		health -= d;
		cout << "The Regular Zombie has taken "; cout << d; cout << " damage!\n";
	}

	int getHealth()
	{
		return health;
	}

	char getType()
	{
		return 'R';
	}

	void die()
	{
		delete this;
	}

	bool check()
	{
		return false;
	}
	void change(int d)
	{
		this->health = d;
	}

};

class Cone : public Zombie
{

public:
	int health = 50;
	int acc = 25;
	void takeDamage(int d)
	{
		if (acc > 0)
		{
			acc -= d;
			cout << "The Cone Zombie has taken "; cout << d; cout << " to the accesory!\n";
		}
		else {
			health -= d;
			cout << "The Cone Zombie has taken "; cout << d; cout << " damage to health!\n";
		}
	}
	int getHealth()
	{
		return health + acc;
	}

	char getType()
	{
		return 'C';
	}

	void die()
	{
		delete this;
	}

	bool check()
	{
		return true;
	}

	void change(int d)
	{
		this->health = d;
	}
};

class Bucket : public Zombie
{
public:
	int health = 50;
	int acc = 100;
	void takeDamage(int d)
	{
		if (acc > 0)
		{
			acc -= d;
			cout << "The Bucket Zombie has taken "; cout << d; cout << " to the accesory!\n";
		}
		else {
			health -= d;
			cout << "The Bucket Zombie has taken "; cout << d; cout << " damage to health!\n";
		}
	}
	int getHealth()
	{
		return health + acc;
	}
	char getType()
	{
		return 'B';
	}

	void die()
	{
		delete this;
	}

	bool check()
	{
		return true;
	}

	void change(int d)
	{
		this->health = d;
	}
};

class Door : public Zombie
{
public:
	int health = 50;
	int acc = 25;
	void takeDamage(int d)
	{
		if (acc > 0)
		{
			acc -= d;
			cout << "The Door Zombie has taken "; cout << d; cout << " to the accesory!\n";
		}
		else {
			health -= d;
			cout << "The Door Zombie has taken "; cout << d; cout << " damage to health!\n";
		}
	}
	int getHealth()
	{
		return health + acc;
	}

	char getType()
	{
		return 'D';
	}

	void die()
	{
		delete this;
	}

	bool check()
	{
		return true;
	}

	void change(int d)
	{
		this->health = d;
	}
};