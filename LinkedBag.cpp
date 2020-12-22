/*
Title: LinkedBag.cpp
Name: Nuzhat Khan
Description: Implementation of functions in LinkedBag.h
Date: 3/3/20
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <cstdlib> //rand

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType> LinkedBag<ItemType> :: LinkedBag(ItemType entries[], int entryCount): headPtr(nullptr), itemCount(0)
{
   for (int nuz = 0; nuz < entryCount; nuz++)

   {
      add(entries[nuz]);
   } //initalize all elements in an array and add to it
} //end parameterized constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

//Add to end of chain by moving a pointer from the headptr node to the nullptr node and inserting the entry at the end
template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{

   Node<ItemType>* newNodePtr = new Node<ItemType>(); //create a new pointer to a node
   
   newNodePtr->setItem(newEntry); //new node holds parameter

   Node <ItemType>* temporary = headPtr; //make a temp pointer and set it to the headptr position

   if (temporary != nullptr) //if temporary is not at the end then

   {
      while (temporary->getNext() != nullptr)

      {
         temporary = temporary->getNext();
      } //traverse through the chain until the end is reached

      itemCount = itemCount + 1; //new ptr is now the last node and the chain increases in size by one
      temporary->setNext(newNodePtr); //once the end is reached, the entry needs to be wedged in between the last node and the nullptr
      //so set the next node to the new ptr which holds entry
      newNodePtr->setNext(nullptr); //nullptr needs to shift so the node after new ptr is now nullptr
      
   }

   else if (temporary == nullptr) //if the chain contains no nodes

   {
      itemCount = itemCount + 1; //increase size of chain by one
      headPtr = newNodePtr; //headptr will point new ptr bc it will be in both the first and last position
   }  

   return true; //return value sincec f(x) is a boolean
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

//NOT GIVEN
//remove second node and delete it, then reconnect the broken chain where second node used to be
template<class ItemType> void LinkedBag<ItemType> :: deleteSecondNode()
{
   if (itemCount > 1) //can only be done if the number of nodes is more than 1

   {
      Node<ItemType>* newNodePtr = headPtr->getNext(); //pointer points to the node next to the one headptr points to
      headPtr->setNext(newNodePtr->getNext()); //headptr is next to the node after the second posiition
      //basicallt shift everything up
      itemCount = itemCount - 1; //decrease size since second node is removed

      delete newNodePtr; 
      newNodePtr = nullptr; //delete dangling ptr
   }
}

//get size of chain iteratively
template<class ItemType> int LinkedBag<ItemType> :: getCurrentSize()
{
   Node<ItemType>* temporary = headPtr; //set temporary ptr to headptr's position
   int track = 0; //tracks number of nodes

   do //can be either do while or while, chose former to spice things up

   {
      temporary = temporary->getNext(); //traverse
      track = track + 1; //increment
   } while (temporary != nullptr); //do these until the end is reached
  
   return track; //return size
}

//wrapper f(x) that takes in parameter and finds size recursively
template<class ItemType> int LinkedBag<ItemType> :: recursive_wrapper(Node<ItemType>* headPtr)
{
   if (headPtr == nullptr)

   {
      return 0;
   } //base case: headPtr points to nullptr and end of chain is reached

   else if (headPtr != nullptr)

   {
      return recursive_wrapper(headPtr->getNext()) + 1;
   } //if not then keep calling f(x) and move thru the nodes
}

//returns the output of recursive wrapper function
template<class ItemType> int LinkedBag<ItemType> :: getCurrentSizeRecursive()
{
   return recursive_wrapper(headPtr); //return result of wrapper f(x)
} 

//get random position and remove it based on three cases: if it is the first node, last node, or node in the middle
template<class ItemType> ItemType LinkedBag<ItemType> :: removeRandom()
{
   int where = rand() % itemCount; //call rand to select position, though it isnt truly random bc it depends on the program itself
   //for actual randomness need to include more math stuff
   if (where == itemCount) //last position

   {
      Node<ItemType>* before_where = headPtr; //the position of ptr is set to headptr

      while (before_where->getNext()->getNext() != nullptr) //until the two positions after ptr are nullptr, in other words if node after current position is nullptr  

      {
         before_where = before_where->getNext(); //continue traversing
      }

      Node<ItemType>* ending = before_where->getNext(); //when before_where stops two positions before nullptr

      before_where->setNext(nullptr); //remove the last node and replace w nullptr
      itemCount = itemCount - 1; //decrease size

      ItemType keeper_first = ending->getItem(); //variable stores value of removed node
      return keeper_first; //return that value
      
   }

   else if (where == 0) //first position

   {
      ItemType keeper_last = headPtr->getItem(); //variable holds value in headptr node
      itemCount = itemCount - 1; //decrease size
      headPtr = headPtr->getNext(); //remove first node so that the node after headptr node becomes first node
   
      return keeper_last; //return that value
   }

   else //any other position
   {
      Node<ItemType>* before_where = headPtr; //ptr before current position to node at headptr
      Node<ItemType>* at_where = headPtr; //currnt position ptr to node at headptr
      //gonna do similar but diff things w them

      for (int nuz = 0; nuz < where; nuz = nuz + 1)

      {
         before_where = at_where; //previous ptr follows right behind current ptr
         at_where = at_where->getNext(); //current ptr traverses
      } //stop when position is reached

      ItemType keeper_middle = at_where->getItem(); //variable stores value in position node

      before_where->setNext(at_where->getNext()); //since position is removed, chain needs to be pulled back and reconnected so the node after previous ptr node is the node that was originally after current position ptr node
      at_where->setNext(nullptr); //at where reconnected to a nullptr

      delete at_where; //delete dangling ptr
      itemCount = itemCount - 1; //decrease size
      return keeper_middle; //return value
   }
}
      
