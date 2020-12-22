/*
Title: Mammal.cpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Implementation of class mammal
*/

#include <string>
#include <iostream>
#include "Mammal.hpp"

using namespace std;

Mammal::Mammal() : Animal(), hair_(false), airborne_(false), aquatic_(false), toothed_(false), fins_(false), tail_(false), legs_(0) {}//default constructor

Mammal::Mammal(string name, bool domestic, bool predator) : Animal(name, domestic, predator) {

	hair_ = false;
	airborne_= false;
	aquatic_ = false;
	toothed_= false;
	fins_= false;
	tail_= false;
	legs_= 0;
} //end parameterized constructor

//mutators change value of answer for each trait
void Mammal::setHair() //no it does not have hair -> yes it does have hair
{
	hair_ = true;
}

void Mammal::setAirborne() //no it is not airborne -> yes it is airborne
{
	airborne_ = true;
}

void Mammal::setAquatic() //no it is not aquatic -> yes it is aquatic
{
	aquatic_ = true;
}

void Mammal::setToothed() //no it does not have teeth -> yes it does have teeth
{
	toothed_ = true;
}

void Mammal::setFins() //no it does not have fins -> yes it does have fins
{
	fins_ = true;
}

void Mammal::setTail() //no it does not have a tail -> yes it does have a tail
{
	tail_ = true;
}

void Mammal::setLegs(int legs) //it has 0 legs -> it has x legs
{
	legs_ = legs;
} //input number of legs

//accesors returns true or false for each trait being asked about
bool Mammal::isAirborne() const //is it airborne?
{
	return airborne_;
}

bool Mammal::isAquatic() const //is it aquatic?
{
	return aquatic_;
}

bool Mammal::isToothed() const //is it toothed?
{
	return toothed_;
}

bool Mammal::hasFins() const //does it have fins?
{
	return fins_;
}

bool Mammal::hasTail() const //does it have a tail?
{
	return tail_;
}

bool Mammal::hasHair() const //does it have hair?
{
	return hair_;
}

int Mammal::legs() const //how many legs does it have?
{
	return legs_;
}





