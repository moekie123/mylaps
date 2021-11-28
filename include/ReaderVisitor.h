#pragma once

class ReaderVisitor
{
	public:
		virtual void addRecord( int, int ) = 0;
		virtual bool isFinished() = 0;
};
