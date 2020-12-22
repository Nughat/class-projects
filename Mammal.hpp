/*
Title: Mammal.hpp
Name: Nuzhat Khan
Date: February 15, 2020
Code: Project 1

Specification of class mammal
*/

/* @file Mammal.h */
#include <iostream>
#include <string>
#include "Animal.hpp"

using namespace std;

#ifndef _MAMMAL
#define _MAMMAL
  
class Mammal : public Animal {
	private: // data field

		bool hair_;
		bool airborne_;
		bool aquatic_;
		bool toothed_;
		bool fins_;
		bool tail_;
		int legs_;
			
	public: //methods and constructors

		Mammal(); //default constructor mammal();
		Mammal(string name, bool domestic = false, bool predator = false); //parameterized constructor
		bool hasHair() const;
		bool isAirborne() const;
		bool isAquatic() const;
		bool isToothed() const;
		bool hasFins() const;
		bool hasTail() const;
		int legs() const;
		void setHair();
		void setAirborne();
		void setAquatic();
		void setToothed();
		void setFins();
		void setTail();
		void setLegs(int legs);

}; 

#endif //end mammal



