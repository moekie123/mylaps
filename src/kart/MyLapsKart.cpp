#include <iostream>

#include "MyLapsKart.h"

void MyLapsKart::addLaptime( int laptime )
{
#ifdef DEBUG
	std::cout << "kart " << mId << ": Add laptime " << laptime << '\n';
#endif
	mRecords.push_back( laptime );

	if( mRecords.size() <= 1 ) return;

	int start, end;
	start = mRecords.rbegin()[1];
	end = mRecords.back();

	mLaptimes.push_back( end - start );
}
