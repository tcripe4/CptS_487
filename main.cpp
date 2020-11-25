//
//  main.cpp
//  487
//
//  Created by Travis Cripe on 3/2/20.
//  Copyright © 2020 Travis Cripe. All rights reserved.
//
#pragma once
#include "Zombie.cpp"
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include "zombies.h"
using namespace std;
vector<Zombie*> zombs;
int damage = 0;
int math = 0;

void leftover_health()
{
	zombs[0]->change(math);
}

int main(int argc, const char * argv[]) {
	int game = -1;
	int zomb = -1;


	while (game != 0)
	{
		cout << "\n0. Quit\n";
		cout << "1. Create zombies?\n";
		cout << "2. Demo game play?\n";
		cin >> game;
		if (game == 0)
		{
			exit(0);
		}
		else if (game == 1)
		{
			cout << "1. Regular\n2. Cone\n3. Bucket\n4. Door\n";
			cin >> zomb;
			zombs.push_back(Zombie::make_zombie(zomb));
			int size = zombs.size();
			for (int i = 0; i < size; i++)
			{
				cout << zombs[i]->getHealth();
				cout << '/';
				cout << zombs[i]->getType();
				cout << " ";
			}
		}
		else if (game == 2)
		{
			cout << "How much damage would you like to do?\n";
			cin >> damage;
			while (zombs.size() != 0)
			{
				cout << "Press Enter to attack!\n";
				cin.get();
				cin.get();
				zombs[0]->takeDamage(damage);
				for (int i = 0; i < zombs.size(); i++)
				{
					cout << zombs[i]->getHealth();
					cout << '/';
					cout << zombs[i]->getType();
					cout << " ";
				}
				cout << "\n";
				if (zombs[0]->check() == true && zombs[0]->getHealth() <= 50 && zombs[0]->getHealth() > 0)
				{
					math = zombs[0]->getHealth();
					zombs[0] = Zombie::make_zombie(1);
					leftover_health();
				}
				if (zombs[0]->getHealth() <= 0)
				{
					zombs[0]->die();
					zombs.erase(zombs.begin());
					cout << "A zombie has died!\n";
				}
				cout << "\n";
			}
			
		}
		
	}


	return 0;
}