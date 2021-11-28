#include <iostream>

#include "RaceTrack.h"

#include "Factory.h"
#include "IReader.h"
#include "IKart.h"

// TODO Don't forget to delete in destructor
Factory<IKart>* kartFactory;

RaceTrack::RaceTrack( int laps, IReader* reader ):
	mLaps(laps), mReader(reader)
{
	kartFactory = new Factory<IKart>();
}

void RaceTrack::start()
{
	std::cout << "race: start\n";
	
	mKarts.clear();
	mReader->accept( this );

	std::cout << "race: complete\n";
}

// Reader Visitor methods
void RaceTrack::addRecord( int kartId, int laptime )
{
	IKart* kart = nullptr;

	std::cout << "race: new record: kart[" << kartId << "] timestamp[" << time << "]\n";

	auto it = mKarts.find( kartId );
  	if (it == mKarts.end() )
	{
		std::cout << "race: new kart detected with id " << kartId << '\n';
		kart = kartFactory->create("MyLapsKart");
		kart->setID( kartId );
		mKarts[ kartId ] = kart;
	}
	else
		kart = it->second;

	kart->addLaptime( laptime );
}
