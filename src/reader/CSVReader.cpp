#include "CSVReader.h"

void CSVReader::accept( ReaderVisitor* visitor ) 
{
	visitor->addRecord( 1, 1000 );
}
