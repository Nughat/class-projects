/*
Title: DoublyLinkedList.cpp
Name: Nuzhat Khan
Description: Implementation of functions in DoublyLinkedList.hpp
Date: 4/7/20

Copy Constructor:

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

 ADT bag: Link-based implementation.
    @file DoubleNode.h 
    Listing 4-3 
*/

#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
#include <iostream>
#include <cstddef>
using namespace std;

template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList():headPtr(nullptr), itemCount(0) {} //end default constructor

template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag)
{
    itemCount = aBag.itemCount;
    DoubleNode<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain

    if (origChainPtr == nullptr)

    {
        headPtr = nullptr;  // Original bag is empty; so is copy
    }
   
    else

    {
        headPtr = new DoubleNode<ItemType>();
        headPtr->setPrevious(nullptr);
        headPtr->setItem(origChainPtr->getItem()); // Copy first node   
        DoubleNode<ItemType>* newChainPtr = headPtr; // Last-node pointer
        DoubleNode<ItemType>* Previous_newChainPtr = headPtr; 
        origChainPtr = origChainPtr->getNext(); // Advance pointer

        while (origChainPtr != nullptr)

        {
            ItemType nextItem = origChainPtr->getItem(); // Get next item from original chain
            DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(nextItem); // Create a new node containing the next item
            newChainPtr->setNext(newNodePtr); // Link new node to end of new chain
            newChainPtr->setPrevious(Previous_newChainPtr); 
            newChainPtr = newChainPtr->getNext(); // Advance pointer to new last node
            origChainPtr = origChainPtr->getNext();
            Previous_newChainPtr = Previous_newChainPtr->getNext();         
        } // end while

        newChainPtr->setNext(nullptr);  // Flag end of chain
    }
} //end copy constructor

//used in destructor to empty out list
template<class ItemType>
void DoublyLinkedList<ItemType>::clear() 
{
    DoubleNode<ItemType>* temptr = new DoubleNode<ItemType>();
    temptr = headPtr; //ptr to head, will traverse and delete

    DoubleNode<ItemType>* nextemptr = new DoubleNode<ItemType>();  //ptr will traverse and pull temptr along
   
    do 

    {
        nextemptr = temptr->getNext(); //traverse
        temptr->setPrevious(nullptr); 
        temptr->setNext(nullptr); //extract each node from list
        temptr = nextemptr; //traverse w nextemptr 
    } while (temptr != nullptr); //done until end of list is reached

    itemCount = 0; //no items in list
    temptr = nullptr; 
    nextemptr = nullptr;
    headPtr = nullptr; //set all ptrs to nullptr
}  //end clear

template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
}  // end destructor

//displays all items in list
template<class ItemType> 
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType>* traverse_ptr = new DoubleNode<ItemType>(); 
    traverse_ptr = headPtr; //ptr starting at position 1 to traverse chain

    while (traverse_ptr->getNext() != nullptr) //traverse until last node is reached

    {
        cout << traverse_ptr->getItem() << " "; //print out each node as you traverse, followed by a space
        traverse_ptr = traverse_ptr->getNext(); //last node is not printed
    }

    cout << traverse_ptr->getItem(); //print last node, not followed by a space
    cout << endl;
}  //end display

//displays all items in list backwards
template<class ItemType> void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType>* traverse_back_ptr = new DoubleNode<ItemType>();
    traverse_back_ptr = getAtPos(itemCount); //ptr to last node, will traverse backwards

    while (traverse_back_ptr->getPrevious() != nullptr) //traverse back until nullptr at end of headptr is reached

    {
        cout << traverse_back_ptr->getItem() << " "; //print out each node as you traverse, followed by a space
        traverse_back_ptr = traverse_back_ptr->getPrevious(); //first node is not printed
    }

    cout << traverse_back_ptr-> getItem(); //print first node, not followed by a space
    cout << endl;
} //end displaybackwards

//returns ptr to position in paramaeter
template<class ItemType> 
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const
{
    bool can_get_pos = (pos <= itemCount + 1) && (pos >= 1); //possible if pos is not greater than itemcount/less than 1

    int counter = 1; //position

    DoubleNode<ItemType>* temptr = new DoubleNode<ItemType>();
    temptr = headPtr; //start at first position

    if (can_get_pos) //if possible

    {
        while (counter != pos) //traverse while counter has not reached position

        {
            counter++; 
            temptr = temptr->getNext();
        }
    }

    return temptr; //return ptr that now points to position
} //end getatpos

//returns headptr
template<class ItemType> DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
    return headPtr;
} //end getheadptr

//returns size of chain
template<class ItemType> int DoublyLinkedList<ItemType>::getSize() const
{
    return itemCount; 
}  //end itemcount

//inserts an item stored in a node in a desired position; either at the beginning, middle, or end of list
//returns bool
template<class ItemType> 
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{

    DoubleNode<ItemType>* temptr = new DoubleNode<ItemType>();
    temptr->setItem(item); //node holds item

    if (position == 1) //if inserting at first position

    {
        if (headPtr == nullptr) //if list is empty, list will only be comprised of the node and nullptrs

        {
            temptr->setNext(nullptr);
            temptr->setPrevious(nullptr);
            headPtr = temptr; //node will be headptr bc it is the only one in the list
        }

        else //if inserting at first position and it is not empty, new node will be new headptr

        {
            headPtr->setPrevious(temptr); //headptr's previous node will be new node, which is now first node
            temptr->setPrevious(nullptr); //new node's previous is nullptr
            temptr->setNext(headPtr); //new node's next is headptr
            headPtr = temptr; //new node is the new headptr
        }

        itemCount++; //increment
    } 

    else if (position == (itemCount + 1)) //if position is last in list, +1 bc inserting it will increase the size of the list

    {
        DoubleNode<ItemType>* prevposptr = new DoubleNode<ItemType>(); 
        prevposptr = getAtPos(itemCount); //ptr to last node

        temptr->setPrevious(prevposptr); //new last node's previous will be previous last node
        temptr->setNext(nullptr); //new last node's next will be nullptr
        prevposptr->setNext(temptr); //last node's next node will be new node, which is now last node
        
        itemCount++; //increment
    }

    else //if position is in the middle anywhere

    {
        DoubleNode<ItemType>* prevposptr = new DoubleNode<ItemType>();
        prevposptr = getAtPos(position - 1); //ptr to node before position node

        DoubleNode<ItemType>* orgposptr = new DoubleNode<ItemType>();
        orgposptr = prevposptr->getNext(); //ptr to node originally in desired position
        
        temptr->setNext(orgposptr); //position node's next becomes node that was originally in desired position
        prevposptr->setNext(temptr); //ptr to node before position node's next is position node
        temptr->setPrevious(prevposptr); //position node's previous becomes node before desired position
        orgposptr->setPrevious(temptr); //position node's getnext 
        
        itemCount++; //increment 
    }

    return true; //return bc bool

} //end insert

//combines two lists so that each node of first list is followed by a node of second list that was originally in the same position as the node of the first list
//returns pointer to third list of combined lists
template <typename ItemType>
DoublyLinkedList<ItemType>& DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& list)
 {

    DoubleNode<ItemType>* interleave_first = new DoubleNode<ItemType>();
    interleave_first = headPtr; //start at headPtr of first list

    DoubleNode<ItemType>* interleave_second = new DoubleNode<ItemType>();
    interleave_second = list.getHeadPtr(); //start at headPtr of second list

    int counter = 1; //keep track of position
    DoublyLinkedList<ItemType>* interleave_ptr = new DoublyLinkedList(); //new interleaved list

    do 

    {
        if (interleave_first != nullptr) //if node is not the last nullptr

        {
            interleave_ptr->insert(interleave_first->getItem(), counter); //starting from the first position insert element of first list into interleave list
            interleave_first = interleave_first->getNext(); //traverse 
            counter++; //increase counter to move on to next position
        } //exit if
    
        if (interleave_second != nullptr) //if node is not the last nullptr

        {
            interleave_ptr->insert(interleave_second->getItem(), counter); //starting from where previous if statement left off, insert element of second list into interleave list; position will have increased from last if statement
            interleave_second = interleave_second->getNext(); //traverse
            counter++; //increase counter to move on to next position
        } //exit if

    } while (!(interleave_second == nullptr && interleave_first == nullptr)); //go back and repeat until end of list is reached for both

    return *interleave_ptr;  //return pointer to new list
} //end interleave

//checks if list is empty
//returns bool to indicate whether or not it is
template<class ItemType> bool DoublyLinkedList<ItemType>::isEmpty() const
{
    bool is_empty = false;

    if (headPtr == nullptr) //if list is empty

    {
        return is_empty = true; //return that it is empty yeet
    }

    else //if list is not empty

    {
        return is_empty; //return that it is not empty
    }  
} //end isempty

//removed node at a desired position; either at the beginning, middle, or end of list
//returns bool to indicate success
template<class ItemType> bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    bool can_remove = !isEmpty() && (position > 0 && position <= itemCount); //possible if node is not empty and position is valid

    if (can_remove) //if possible

    {
        if (position == 1) //if first position

        {
            DoubleNode<ItemType>* temptr = new DoubleNode<ItemType>(); 
            temptr = headPtr; //ptr to head

            headPtr = headPtr->getNext(); //make new headptr the one over

            temptr->setNext(nullptr); 
            temptr->setPrevious(nullptr); //set old headptr's previous and next to nullptr
            delete temptr; 
            temptr = nullptr; //deallocate ptr
        }

        else if (position == itemCount) //if last position

        {
            DoubleNode<ItemType>* itemCount_ptr = new DoubleNode<ItemType>();
            itemCount_ptr = getAtPos(itemCount); //ptr to last node

            DoubleNode<ItemType>* node_before_itemCount_ptr = new DoubleNode<ItemType>();
            node_before_itemCount_ptr = getAtPos(itemCount - 1); //ptr to node before last node

            node_before_itemCount_ptr->setNext(nullptr); //set next of this node to nullptr so it is the new last node

            itemCount_ptr->setNext(nullptr); 
            itemCount_ptr->setPrevious(nullptr); //set old last node's next and last to nullptr to extract it from list
            delete itemCount_ptr;
            itemCount_ptr = nullptr; //deallocate ptr
        }

        else //if position is in the middle anywhere

        {
            DoubleNode<ItemType>* pos_ptr = new DoubleNode<ItemType>();
            pos_ptr = getAtPos(position);  //get node to position

            DoubleNode<ItemType>* Previous_newChainPtr_pos_ptr = new DoubleNode<ItemType>();
            Previous_newChainPtr_pos_ptr = getAtPos(position + 1); //get node to position's next node, which will take the current place of position

            DoubleNode<ItemType>* before_pos_ptr = new DoubleNode<ItemType>();
            before_pos_ptr = getAtPos(position - 1); //get position's previous node, which will go down a position

            Previous_newChainPtr_pos_ptr->setPrevious(before_pos_ptr); //position's next node's new previous position will be node before position, replacing position node
            before_pos_ptr->setNext(Previous_newChainPtr_pos_ptr); //position's previous node's new next will be node after position node, replacing position
            pos_ptr->setNext(nullptr); //position is bypassed and set to null on both sides for extraction from list
            pos_ptr->setPrevious(nullptr);
            delete pos_ptr; //deallocate
            pos_ptr = nullptr; //deallocate ptr
        }

        itemCount--; //decrement
    }

    return can_remove; //return whether possible or not
} //end remove