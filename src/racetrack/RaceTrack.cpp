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
#ifdef DEBUG
	std::cout << "race: start\n";
#endif
	mKarts.clear();
	mReader->accept( this );

#ifdef DEBUG
	std::cout << "race: complete\n";
#endif
}

std::tuple<int,int,int,int> RaceTrack::getWinner()
{
	int wId, wStart, wEnd, wLaptime = INT_MAX;

	for ( auto const& [id, kart] : mKarts )
	{
		int lap = kart->getFastestLap();
		auto [start, end, laptime] = kart->getLapInfo( lap );

#ifdef DEBUG
		std::cout << "race: result: kart " << id << " start: " << start << " end: " << end << " laptime: " << laptime << '\n';
#endif
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

#ifdef DEBUG
	std::cout << "race: new record: kart[" << kartId << "] timestamp[" << laptime << "]\n";
#endif

	auto it = mKarts.find( kartId );
  	if (it == mKarts.end() )
	{
#ifdef DEBUG
		std::cout << "race: new kart detected with id " << kartId << '\n';
#endif
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
#ifdef DEBUG
			std::cout << "race: kart " << kart->getID() << " finished\n";
#endif
			return true;	
		}
	}

	return false;
}
