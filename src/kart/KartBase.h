#pragma once

#include <vector>
#include <tuple>

#include "IKart.h"

class KartBase:
	public IKart
{
	public:
		// Interface methods
		int getID() override;
		void setID( int ) override;
		
		void addLaptime( int ) override;
		
		int getTotalLaps() override;

		int getFastestLap() override;
		std::tuple<int,int,int> getLapInfo( int ) override;

	protected:
		std::vector<int> mRecords;
		std::vector<int> mLaptimes;
};
