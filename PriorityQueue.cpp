/*PriorityQueue.cpp
*
* Class Description: Manages customer's in the bank line, using a priority queue
* Class Invariant:
*
*
* Last Modified on: July 4th 2-17
* Author: Dan Tang(301256468)
*
*
*/

#include "PriorityQueue.h"
#include <iostream>
#include <string>



using namespace std;

template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
   front = 0;
   back = CAPACITY-1;
   elementCount = 0;
}

// Description: Returns the number of elements in the Priority Queue.
// Time Efficiency: O(1) 
template<class ElementType>
int PriorityQueue<ElementType>::getElementCount() const
{
   return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
   return elementCount == 0;
}

// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.    
// Time Efficiency: O(n)      
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement)
{
   bool queuedOK = false;
   Events temp = Events();
   Events temp2 = Events();
   bool sorted = false;
   int k = 0;
   

   if(elementCount < CAPACITY)
   {
      back = elementCount;
      elements[back] = newElement;
      elementCount++;
      queuedOK = true;
      
   }

   for(int i = 0; (i<=elementCount-2)&&(sorted==false); i++)
   {
      if(newElement.getTime()>=elements[i].getTime()&&newElement.getType()>=elements[i].getType())
      {
         temp2 = newElement;
         for(int j=i;j<=elementCount-1;j++)
         {
            temp = elements[j];
            elements[j] = temp2;
            temp2 = temp;
            
         }
         sorted = true;
      }
     

   }

   

   

   return queuedOK;
}

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1) 
template<class ElementType>
bool PriorityQueue<ElementType>::dequeue()
{
  if(!isEmpty())
   {   
      elementCount = elementCount - 1;
      return true;
   }
   else
      return false;
}

// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1) 
template<class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException)
{
   if(isEmpty())
      throw EmptyDataCollectionException("peek() called with empty queue");

   return elements[elementCount-1];
}

// Description: Prints all elements stored in the Queue  
template<class ElementType>
void PriorityQueue<ElementType>::printPriorityQueue() const 
{
   cout<<"number of elements in PQ: "<<elementCount<<endl;
   cout << "Printing the priority queue from front = " << front << " to back = "<< elementCount-1 << endl;

   for( int i = elementCount-1; i>=0; i--)
      cout<< elements[i] << endl;
} 
