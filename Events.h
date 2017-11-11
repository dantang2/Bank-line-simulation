/*	Events.h
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

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Events
{
	private:
		int time;
		int arrivalTime;
		int length;
		int departureTime;
		int startWaitTime;
		string type;

	public: 
		//Default Constructor
		Events();

		//Constructor for Arrival Events
		Events(int anArrivalTime, int aLength);

		//Constructor for Departure Events
		Events(int aDepartureTime);

		//Getters & Setters

		// Description: Returns customer's time of event.
		int getTime() const;

		// Description: Returns customer's time of arrival.
		int getArrivalTime() const;

		// Description: Returns customer's transaction time.
		int getLength() const;

		// Description: Returns customer's type of event (departure/arrival).
		string getType() const;

		// Description: Returns customer's time of departure.
		int getDepartureTime() const;

		// Description: Returns time at which the customer begins to wait in line.
		int getStartWaitTime() const;
		
		// Description: Sets customer's time of event.
		void setTime(const int aTime);

		// Description: Sets customer's time of arrival.
		void setArrivalTime(const int anArrivalTime);

		// Description: Sets customer's transaction time.
		void setLength(const int aLength);

		// Description: Sets customer's type of event (departure/arrival).
		void setType(const string aType);

		// Description: Sets customer's time of departure.
		void setDepartureTime(const int aDepartureTime);

		// Description: Sets the time at which the customer begins to wait in line.
		void setStartWaitTime(const int aStartWaitTime);
		
		// Description: Prints the content of this customer.
		friend ostream & operator<<(ostream & os, const Events & event);





}; // end of Events header file
