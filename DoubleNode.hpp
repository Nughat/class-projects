/*
Title: DoubleNode.hpp
Name: Nuzhat Khan
Description: Specification of functions in DoubleNode.hpp
Date: 4/7/20
*/

#ifndef DOUBLE_NODE
#define DOUBLE_NODE

template<class ItemType>
class DoubleNode
{
    private:

        ItemType        item; //data item
        DoubleNode<ItemType>* next; //next node ptr
        DoubleNode<ItemType>* previous; //previous node ptr

    public:

        DoubleNode(); //constructor
        DoubleNode(const ItemType& anItem); //default constructor       
        DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* next_node_ptr);  //copy constructor          
        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        void setNext(DoubleNode<ItemType>* next_node_ptr);
        DoubleNode<ItemType>* getNext() const;  
        void setPrevious(DoubleNode<ItemType>* prev_node_ptr);
        DoubleNode<ItemType>* getPrevious() const;
}; //end DoubleNode

#include "DoubleNode.cpp"
#endif