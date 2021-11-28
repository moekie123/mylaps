#pragma once

#include <vector>

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

	protected:
		std::vector<int> mRecords;
		std::vector<int> mLaptimes;
};
