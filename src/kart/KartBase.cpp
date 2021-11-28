#include "KartBase.h"

#include <iostream>
#include <algorithm>
#include <iterator>

void KartBase::setID( int id )
{
	mId = id;
}

int KartBase::getID()
{
	return mId;
}

void KartBase::addLaptime( int )
{

}

int KartBase::getTotalLaps()
{
	return mLaptimes.size();
}

int KartBase::getFastestLap()
{
	return std::distance( mLaptimes.begin(), std::min_element( mLaptimes.begin(), mLaptimes.end()));
}

std::tuple<int,int,int> KartBase::getLapInfo( int lapId )
{
	return { mRecords[lapId], mRecords[lapId+1], mLaptimes[lapId] };
}

