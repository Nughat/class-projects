/*
Title: Animal.hpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Specification of abstract base class animal
*/

/* @file Animal.h */
#include <iostream>
#include <string>

using namespace std;

#ifndef _ANIMAL
#define _ANIMAL

class Animal {
	private: //data field

		string name_;
		bool domestic_;
		bool predator_;
			
	public: //methods and constructors

		Animal(); //default constructor animal();
		Animal(string name, bool domestic = false, bool predator = false); //parameterized constructor
		string getName() const;
		bool isDomestic() const;
		bool isPredator() const;
		void setName(string name);
		void setDomestic();
		void setPredator();

}; 

#endif //end animal
