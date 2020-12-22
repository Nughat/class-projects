/*
Title: Fish.cpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Implementation of class fish
*/

#include <iostream>
#include <string>
#include "Fish.hpp"

using namespace std;

Fish::Fish() : Animal() {}	//default constructor

Fish::Fish(string name, bool domestic, bool predator) : Animal(name, domestic, predator) {

	venomous_ = false;
} //end parameterized constructor

//mutators change value of answer for each trait
void Fish::setVenomous() //no it is not venomous -> yes it is venomous
{
	venomous_ = true;						
}

//accesors returns true or false for each trait being asked about
bool Fish::isVenomous() const //is it venomous?
{
	return venomous_;
}
