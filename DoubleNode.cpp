/*
Title: DoubleNode.cpp
Name: Nuzhat Khan
Description: Implementation of functions in DoubleNode.hpp
Date: 4/7/20
*/

#include "DoubleNode.hpp"

template<class ItemType>
DoubleNode<ItemType>::DoubleNode():next(nullptr), previous(nullptr) {}
//Default Constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem):item(anItem), next(nullptr), previous(nullptr) {} //Constructor
 
//sets item to item passed by parameter
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;               
} //end setitem

//returns item at a node
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item;                 
} //end getitem

//sets next node of a node
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* next_node_ptr)
{
    next = next_node_ptr;        
} //end setnext                               

//returns next node of a node
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next;                 
} //end getnext

//sets previous node of a node
template<class ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType>* prev_node_ptr)
{
    previous = prev_node_ptr;   
} //end setprevious

//returns previous node of a node
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrevious() const
{
    return previous;            
} //end getprevious