#include "ReaderBase.h"

void ReaderBase::setFilename( std::string const& filename )
{
	mFilename = filename;
}

void ReaderBase::accept( ReaderVisitor* visitor ) 
{

}
