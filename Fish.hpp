/*
Title: Fish.hpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Specification of class fish
*/

/* @file Fish.h */
#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

#ifndef _FISH
#define _FISH

class Fish : public Animal {

private: //data field

	bool venomous_; 
	
public: //methods and constructors

	Fish(); //default constructor fish();
	Fish(string name, bool domestic = false, bool predator = false); //parameterized constructor
	bool isVenomous() const;
	void setVenomous();
	
};
#endif //end fish
