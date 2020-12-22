/*
Title: DoublyLinkedList.hpp
Name: Nuzhat Khan
Description: Specification of functions in DoublyLinkedList.hpp
Date: 4/7/20
*/

#ifndef DOUBLY_LINKED
#define DOUBLY_LINKED

#include "DoubleNode.hpp"

template<class ItemType>
class DoublyLinkedList
{
    private:

        DoubleNode<ItemType>* headPtr; //first node ptr
        int itemCount; // current count of bag items

    public:
        
        DoublyLinkedList(); //default constructor
        DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag); //copy constuctor 
        ~DoublyLinkedList(); //destructor
        bool insert(const ItemType& item, const int& position); 
        bool remove(const int& position);
        int getSize() const; 
        DoubleNode<ItemType> *getHeadPtr() const; 
        DoubleNode<ItemType> *getAtPos(const int& pos) const;
        bool isEmpty() const;
        void clear(); 
        void display() const;
        void displayBackwards() const;
        DoublyLinkedList<ItemType>& interleave(const DoublyLinkedList<ItemType>& a_list); 
}; // end DoublyLinkedList

#include "DoublyLinkedList.cpp"
#endif