#pragma once 

#include <map>

#include "IReader.h"
#include "ReaderVisitor.h"

#include "IKart.h"

class RaceTrack:
	public ReaderVisitor
{
	public:
		RaceTrack( int , IReader* );
		
		void start();

		std::tuple<int,int,int,int> getWinner();

	private:
		const int mLaps;
		IReader* mReader;

		std::map< int, IKart*> mKarts;

		// Visitor Interface
		void addRecord( int, int ) override;
		bool isFinished() override;
};
