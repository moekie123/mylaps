#pragma once

#include<vector>

class IKart
{
	public:
		virtual ~IKart(){}

		// Kart Id getter and setter
		virtual int getID() = 0;
		virtual void setID( int ) = 0;

		virtual void addLaptime( int ) = 0;
		
		virtual int getTotalLaps() = 0;

	protected:
		int mId;
		std::vector<int> mLaptimes;
};
