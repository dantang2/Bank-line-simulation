//test driver

#include <iostream>
#include <cstring>
#include <string>
#include "Events.h"
#include "bankLine.h"
#include "Node.h"
#include "PriorityQueue.h"
#include <sstream>
#include <iomanip>

using namespace std;


void processArrival(Events event, PriorityQueue<Events> * priorityQ, Queue<Events> * bankLine, bool& tellerAvailable)
{
	priorityQ->dequeue();
	Events customer = event;
	int currentTime = event.getTime();
	
	
	if(bankLine->isEmpty()&&tellerAvailable)
	{

		cout<<"Processing an arrival event at time:  "<<currentTime<<endl;

		int departureTime = (currentTime+customer.getLength());
		Events newDepartureEvent = Events(departureTime);
		

		priorityQ->enqueue(newDepartureEvent);
		tellerAvailable = false;
		
	}

	else
	{
		customer.setStartWaitTime(currentTime);
		bankLine->enqueue(customer); 
		cout<<"Processing an arrival event at time:  "<<currentTime<<endl;
	}

	
}

void processDeparture(Events event, PriorityQueue<Events> * priorityQ, Queue<Events> * bankLine, bool& tellerAvailable, int& waitingTime)
{
	priorityQ->dequeue();
	Events customer = Events();
	int currentTime = event.getTime();
	waitingTime = 0;

	cout<<"Processing a departure event at time: "<<currentTime<<endl;

	if(!bankLine->isEmpty())
	{
		try
		{
			customer = bankLine->peek();
		}
		catch ( EmptyDataCollectionException&anException ) 
		{
			cout << "peeking() unsuccessful because " << anException.what() << endl;
		 	
		}

		waitingTime = currentTime - customer.getStartWaitTime();
		

		//Set-up new departure event
		
		int departureTime = (currentTime+customer.getLength());
		Events newDepartureEvent = Events(departureTime);
		priorityQ->enqueue(newDepartureEvent);
		tellerAvailable = false;

		
		bankLine->dequeue();

	}

	else
		tellerAvailable = true;

}




int main()
{
	cout<<endl<<"Simulation Begins"<<endl;

	PriorityQueue<Events> * PriorityQ = new PriorityQueue<Events>;
	Queue<Events> * bankLine = new Queue<Events>;

	Events newEvent = Events();


	string aLine = "";
	int arrival[100];
	int length[100];
	int departure[100];
	int counter=0;
	int i=0;
	int currentTime = 0;
	bool tellerAvailable = true;

	int processed = 0;

	int	waitingTime;	
	double TotalWaitingTime = 0;

	 while(getline(cin >> ws, aLine)) 
	 {   // while (there is data)
	 
	      stringstream ss(aLine);
	      ss >> arrival[i] >> length[i];  
	      departure[i] = arrival[i]+length[i];  
	      
	      i++;
	      counter++;
	      
	 }

	 for(int i = 0; i<=counter-1; i++)
	 {
	  	Events anEvent = Events(arrival[i], length[i]);
	 	PriorityQ->enqueue(anEvent);	
	 }


	 do
	 {
	 	try
	 	{
	 		newEvent = PriorityQ->peek();
	 	}
	 	catch ( EmptyDataCollectionException&anException ) 
		{
			cout << "peeking() unsuccessful because " << anException.what() << endl;
		 	
		}


	 	currentTime = newEvent.getTime();
	 	if(newEvent.getType()=="arrival")
	 	{
	 		processArrival(newEvent, PriorityQ, bankLine, tellerAvailable);
	 	}

	 	else if(newEvent.getType()=="departure")
	 	{
	 		
	 		processDeparture(newEvent, PriorityQ, bankLine, tellerAvailable, waitingTime);
	 		TotalWaitingTime = TotalWaitingTime + waitingTime;
	 		processed++;
	 	}

	 }while((!(PriorityQ->isEmpty())));

	

	 cout<<"Simulation Ends"<<endl;

	 cout<<endl<<"Final Statistics: "<<endl;
	 cout<<"\tTotal number of people processed: "<<processed<<endl;
	 cout<<"\tAverage amount of time spent waiting: "<<TotalWaitingTime/counter;
   cout<<endl;


}










	 


  
  









	 

