/*
Title: Bird.hpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Specification of class bird
*/

/* @file Bird.h */
#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

#ifndef _BIRD
#define _BIRD

class Bird : public Animal {

private: //data field

	bool airborne_;
	bool aquatic_;
	
public: //methods and constructors

	Bird(); //default constructor bird();
	Bird(string name, bool domestic = false, bool predator = false); //parameterized constructor
	bool isAirborne() const;
	bool isAquatic() const;
	void setAirborne();
	void setAquatic();
};
#endif //end bird
