#pragma once

#include "IKart.h"

class KartBase:
	public IKart
{
	public:
		// Interface methods
		int getID() override;
		void setID( int ) override;
		
		void addTime( int ) override;
};
