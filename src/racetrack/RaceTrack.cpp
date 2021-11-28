#include <iostream>

#include "RaceTrack.h"
#include "IReader.h"

RaceTrack::RaceTrack( int laps, IReader* reader ):
	mLaps(laps), mReader(reader)
{
	
}

void RaceTrack::start()
{
	std::cout << "race: start\n";

	mReader->accept( this );

	std::cout << "race: complete\n";
}

// Visitor methods
void RaceTrack::addRecord( int kartId, int time )
{
	std::cout << "Add new record: kart[" << kartId << "] timestamp[" << time << "]\n";
}
