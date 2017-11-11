/*
*	bankLine.cpp
*	
* Class Description: Queue data collection ADT.
						- Link-based (DHDL) implemented
						- Will hold the queue for the bank line
* Class Invariant: Must be a template data collection ADT.
*
* Last modified on: July 4th, 2017
* Author: Dan Tang(301256468)
*
*/

#include <iostream>
#include <string>
#include "bankLine.h"


using namespace std;

// Default Constructor
template<class ElementType>
Queue<ElementType>::Queue()
{
   elementCount = 0;
   head = NULL;
   tail = NULL;
}

// Description: Returns the number of elements in the Queue.
// Time Efficiency: O(1)
template<class ElementType>
int Queue<ElementType>::getElementCount() const
{
   return elementCount;
}

// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const
{
   return elementCount == 0;
}

// Description: Adds newElement to the front of the data structure
//				which is also the back of the queue. Returns true
//				if successful, otherwise false.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement)
{
   Node<ElementType> *p = new Node<ElementType>; // temporary node for new node
   Node<ElementType> *q = new Node<ElementType>; // temporary node for previous node	
   
   bool queuedOK = false;
   p -> data = newElement;


  if(head==NULL)
  {
      p->back = NULL;
      head = p;
      tail = p; //Sets tail to the first object added to the queue
      elementCount++;
     
  }

  else
  {
      q = head;
      q -> back = p;
      p -> next = q;
      head = p;
      elementCount++;
  }

   return queuedOK;
}

// Description: Removes the element at the back of the data structure of this
//              also the front of this Queue and returns "true"
//              if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::dequeue()
{  

	bool dequeued = false;
   Node<ElementType> *nodeToDelete = new Node<ElementType>;
   nodeToDelete = tail;
   if(!isEmpty())
	  { 
	  	if(tail->back==NULL)
	  	   {
	  	      
	  	      delete nodeToDelete;
	  	      nodeToDelete=NULL;
	  	   }
	  
	  	   else
	  	   {
	  	      
	  	      tail = tail -> back;
	  
	  	      tail->next=NULL;
	  
	  	      
	  
	  	      nodeToDelete -> back = NULL;
	  	      delete nodeToDelete;
	  	      nodeToDelete = NULL;
	  	   }
	  		
	  		dequeued = true;
	  	   elementCount--;
	  	   return dequeued;
	  	}
	else
		return dequeued;

}

// Description: Returns (a copy of) the element located at the "front" of this Queue.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException)
{
   if(isEmpty())
      throw EmptyDataCollectionException("peek() called with empty queue");

   return tail->data;
}

// Description: Prints all elements stored in the Queue			
template<class ElementType>
void Queue<ElementType>::printQueue() const 
{
   cout<<"number of elements in bankLine: "<<elementCount<<endl;
   cout << "Printing the bankLine queue from front = " << 0 << " to back = "<< elementCount-1 << endl;

   Node<ElementType> *p = new Node<ElementType>;
   p = tail;
   int i = elementCount-1;

   do
   {
      cout<<p->data;
      p = p->back;
      i--;
   }while(i>=0);
} 

//End of bankLine implementation file
























































