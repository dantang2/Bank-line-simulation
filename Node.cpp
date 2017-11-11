/*
 * Node.cpp
 *
 * Class Definition: Node of a doubly linked list 
 *                   in which the data is of an Element Type
 *					 Implemented as template data collection.
 *
 * Last modified on: July 4th 2017
 * Author: Dan Tang(301256468)
 */

#include <cstdio>  // Needed for NULL
#include "Node.h"

//Default constructor
template <class ElementType>
Node<ElementType>::Node()
{
	next = NULL;
}

template <class ElementType>
Node<ElementType>::Node(ElementType theData)
{
	data = theData;
	next = NULL;
}

// end Node.cpp