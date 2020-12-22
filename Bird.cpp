/*
Title: Bird.cpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Implementation of class bird
*/

#include <string>
#include <iostream>
#include "Bird.hpp"

using namespace std;

Bird::Bird() : Animal() {} //default constructor

Bird::Bird(string name, bool domestic, bool predator) : Animal(name, domestic, predator) {
	
	airborne_= false;
	aquatic_ = false;
	
} //end parameterized constructor

//mutators change value of answer for each trait
void Bird::setAquatic() //no it is not aquatic -> yes it is aquatic
{
	aquatic_= true;
}

void Bird::setAirborne() //no it is not airborne -> yes it is airborne
{
	airborne_= true;
}

//accesors returns true or false for each trait being asked about
bool Bird::isAirborne() const //is it airborne?
{
	return airborne_;
}

bool Bird::isAquatic() const //is it aquatic?
{
	return aquatic_;
}


