/*
Title: LinkedBag.cpp
Name: Nuzhat Khan
Description: Implementation of functions in LinkedBag.h
Date: 3/3/20
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.h 
    Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
   Node<ItemType>* headPtr; // Pointer to first node
   int itemCount;           // Current count of bag items
   
   // Returns either a pointer to the node containing a given entry
   // or the null pointer if the entry is not in the bag.
   Node<ItemType>* getPointerTo(const ItemType& target) const;
   
public:
   LinkedBag(); //default constructor
   LinkedBag(ItemType entries[], int entryCount);
   LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
   virtual ~LinkedBag();                       // Destructor should be virtual
   bool isEmpty() const; //set to 0
   int getCurrentSize() const; //size of an empty bag
   bool add(const ItemType& newEntry); //take in entry and adds to node at end of chain
   std::vector<ItemType> toVector() const; //traverse chain and return vector 
   bool remove(const ItemType& anEntry); //take in entry and remove it
   void clear(); //use for destructor
   int getFrequencyOf(const ItemType& anEntry) const; //find occurence of single item in bag
   bool contains(const ItemType& anEntry) const; //if item is in the bag
   void deleteSecondNode(); //deletes second node of chain
   int getCurrentSize(); //finds size of chain iteratively
   int recursive_wrapper(Node<ItemType>* headPtr); //wrapper function that finds siz recursively
   int getCurrentSizeRecursive(); //returns output of wrapper function
   ItemType removeRandom(); //randomly selects position in chain and removes node in that position
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif