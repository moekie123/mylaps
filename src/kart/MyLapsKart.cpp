#include <iostream>

#include "MyLapsKart.h"

void MyLapsKart::addLaptime( int laptime )
{
	std::cout << "kart " << mId << ": Add laptime " << laptime << '\n';
	mRecords.push_back( laptime );

	if( mRecords.size() <= 1 ) return;

	int start, end;
	start = mRecords.rbegin()[1];
	end = mRecords.back();

	std::cout << "kart " << mId << ": start " << start << " end " << end << '\n';
	mLaptimes.push_back( end - start );

	// TODO Consider other container type to reorder the laptimes
}
