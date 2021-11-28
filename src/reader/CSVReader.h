#pragma once

#include "ReaderBase.h"

class CSVReader:
	public ReaderBase
{
	public:
	
		// Vistable methods
		void accept( ReaderVisitor* visitor ) override;
};
