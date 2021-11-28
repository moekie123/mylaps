#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "CSVReader.h"

void CSVReader::accept( ReaderVisitor* visitor ) 
{
    	std::string buffer;
	std::vector<std::string> row;
	std::fstream fin;

	// Open csv file
	std::cout << "reader: open: " << mFilename << '\n';
	fin.open( mFilename , std::ios::in );

	// Fetch header
	std::getline( fin, buffer );
	std::cout << "reader: header: " <<  buffer << '\n';

	// Fetch records
	while( std::getline( fin, buffer ))
	{
		int kartId;
		int timestamp, hour, minut, sec= 0;

		if( visitor->isFinished() )
			return;

		std::cout << "reader: record: " <<  buffer << '\n';

		std::stringstream s( buffer );

		row.clear();
		while( getline( s, buffer, ',') )
			row.push_back( buffer );
		
		kartId = std::stoi( row[0] );

		sscanf( row[1].c_str(), "%d:%d:%d", &hour, &minut, &sec ); 
		timestamp = hour*3600 + minut*60 + sec;
		
		visitor->addRecord( kartId, timestamp );
	}
}
