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

	std::cout << "race: complete\n";
}
