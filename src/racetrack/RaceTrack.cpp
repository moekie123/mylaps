#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

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

std::tuple<int,int,int,int> RaceTrack::getWinner()
{
	int wId, wStart, wEnd, wLaptime = INT_MAX;

	for ( auto const& [id, kart] : mKarts )
	{
		int lap = kart->getFastestLap();
		std::cout << "race: result: kart " << id << " fastest lap: " << lap << '\n';

		auto [start, end, laptime] = kart->getLapInfo( lap );
		std::cout << "race: result: kart " << id << " start: " << start << " end: " << end << " laptime: " << laptime << '\n';

		if( wLaptime > laptime ) 
		{
			wId = id;
			wStart = start;
			wEnd = end;
			wLaptime = laptime;
		}
	}

	return { wId, wStart, wEnd, wLaptime };
}

// Reader Visitor methods
void RaceTrack::addRecord( int kartId, int laptime )
{
	IKart* kart = nullptr;

	std::cout << "race: new record: kart[" << kartId << "] timestamp[" << laptime << "]\n";

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

bool RaceTrack::isFinished()
{
	for ( auto const& [id, kart] : mKarts)
	{
		if( kart->getTotalLaps() >= mLaps ) 
		{
			std::cout << "race: kart " << kart->getID() << " finished\n";
			return true;	
		}
	}

	return false;
}
