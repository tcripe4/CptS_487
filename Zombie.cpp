//
//  zombies.cpp
//  HW4_487
//
//  Created by Travis Cripe on 3/2/20.
//  Copyright © 2020 Travis Cripe. All rights reserved.
//
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "zombies.h"
using namespace std;

Zombie *Zombie::make_zombie(int choice)
{
	if (choice == 1)
	{
		return new Reg_Zombie;
	}
	else if (choice == 2)
	{
		return new Cone;
	}
	else if (choice == 3)
	{
		return new Bucket;
	}
	else if (choice == 4)
	{
		return new Door;
	}
	else return NULL;
}
