all: sApp

sApp: SimulationApp.o bankLine.h PriorityQueue.h Node.h Events.o EmptyDataCollectionException.o
	g++ -Wall -o sApp SimulationApp.o Events.o EmptyDataCollectionException.o 

Events.o: Events.cpp Events.h
	g++ -c Events.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f sApp *.o