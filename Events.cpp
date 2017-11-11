/*	Events.cpp
*
* Class Description: Models a customers time at a bank.
* Class Invariant:
*
*
* Last Modified on: July 4th 2-17
* Author: Dan Tang(301256468)
*
*
*/

#include <iostream>
#include "Events.h"

using namespace std;

//Default Constructor
Events::Events()
{
	arrivalTime = 0;
	length = 0;
	type = "NULL";
	departureTime = 0;
	time = 0;
	startWaitTime = 0;
}

//Constructor for Arrival Events
Events::Events(int anArrivalTime, int aLength)
{
	arrivalTime = anArrivalTime;
	length = aLength;
	time = anArrivalTime;
	type = "arrival";
}

//Constructor for Departure Events
Events::Events(int aDepartureTime)
{
	departureTime = aDepartureTime;
	type = "departure";
	time = aDepartureTime;
}

//Getters & Setters

// Description: Returns customer's time of event.
int Events::getTime() const
{
	return time;
}

// Description: Returns customer's time of arrival.
int Events::getArrivalTime() const
{
	return arrivalTime;
}

// Description: Returns customer's transaction time.
int Events::getLength() const
{
	return length;
}

// Description: Returns customer's type of event (departure/arrival).
string Events::getType() const
{
	return type;
}

// Description: Returns customer's time of departure.
int Events::getDepartureTime() const
{
	return departureTime;
}

// Description: Returns time at which the customer begins to wait in line.
int Events::getStartWaitTime() const
{
	return startWaitTime;
}

// Description: Sets customer's time of event.
void Events::setTime(const int aTime)
{
	time = aTime;
}

// Description: Sets customer's time of arrival.
void Events::setArrivalTime(const int anArrivalTime)
{
	arrivalTime = anArrivalTime;
}

// Description: Sets customer's transaction time.
void Events::setLength(const int aLength)
{
	length = aLength;
}

// Description: Sets customer's type of event (departure/arrival).
void Events::setType(const string aType)
{
	type = aType;
}

// Description: Sets customer's time of departure.
void Events::setDepartureTime(const int aDepartureTime)
{
	departureTime = aDepartureTime;
}

// Description: Sets the time at which the customer begins to wait in line.
void Events::setStartWaitTime(const int aStartWaitTime)
{
	startWaitTime = aStartWaitTime;

}

// Description: Prints the content of this customer.
ostream & operator<<(ostream & os, const Events & event) 
{

	os << "Time: " << event.getTime() <<endl;
	     
	return os;
} // end of operator<<

// end of Events.cpp implementation file


