/*
 * Node.h
 *
 * Class Definition: Node of a doubly linked list 
 *                   in which the data is of an Element Type
 *					 Implemented as template data collection.
 *
 * Last modified on: July 4th, 2017
 * Author: Dan Tang(301256468)
 */
 
#pragma once

template <class ElementType>
class Node
{
public:
	
	ElementType data;     // The data in the node
	Node* next;   // Pointer to next node
	Node* back; // Pointer to previous node
	
	//Default Constructor
	Node();

	Node(ElementType theData);

}; // end of Node.h header file

#include "Node.cpp"