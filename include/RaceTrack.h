#pragma once 

#include "IReader.h"

class RaceTrack
{
	public:
		RaceTrack( int , IReader* );
		
		void start();

	private:
		const int mLaps;
		IReader* mReader;
};
