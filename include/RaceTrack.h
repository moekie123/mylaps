#pragma once 

#include "IReader.h"
#include "ReaderVisitor.h"

class RaceTrack:
	public ReaderVisitor
{
	public:
		RaceTrack( int , IReader* );
		
		void start();

	private:
		const int mLaps;
		IReader* mReader;

		// Visitor Interface
		void addRecord( int, int ) override;
};
