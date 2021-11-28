#include "KartBase.h"

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
