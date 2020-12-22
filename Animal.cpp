/*
Title: Animal.cpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Implementation of abstract base class animal
*/

#include <iostream>
#include <string>

#include "Animal.hpp"

using namespace std;

Animal::Animal() : name_(""), domestic_(false), predator_(false) {} //default constructor, initializer initializes all data fields in one go

Animal::Animal(string name, bool domestic, bool predator) {

	predator_ = predator; 
	domestic_ = domestic;
	name_ = name;
} //end parameterized constructor

//mutators change value of answer for each trait
void Animal::setName(string name) //give it a name
{
	name_ = name;
} //input name

void Animal::setDomestic() //no it is not domestic -> yes it is domestic
{
	domestic_ = true;
}

void Animal::setPredator() //no it is not a predator -> yes it is a predator
{
	predator_ = true;
}

//accesors returns true or false for each trait being asked about
string Animal::getName() const //what is it's name?
{
	return name_;
}

bool Animal::isDomestic() const //is it dosmestic?
{
	return domestic_;
}

bool Animal::isPredator() const //is it a predator?
{
	return predator_;
}




	
