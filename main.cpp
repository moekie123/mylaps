#include <iostream>

#include "Factory.h"
#include "IKart.h"
#include "IReader.h"

#include "RaceTrack.h"

int main( int argc, char* argv[] )
{
	std::string filename;

	std::cout << "Booting MyLaps Assignment\n";

	// Store (csv) filename
	if ( argc > 1 )
		filename = argv[1]; 
	else
		throw std::runtime_error("csv filename missing");

	std::cout << filename << '\n';

	// ##############################################
	// Sandbox for some proof-of-concept code

	/**
	// Kart Example	
	auto kartFactory = new Factory<IKart>();
	auto kart = kartFactory->create("MyLaps");
	kart->setID(1);
	delete kartFactory;
	delete kart;
	*/

	/** Reader Example	
	auto readerFactory = new Factory<IReader>();
	auto reader = readerFactory->create("csv");

	reader->setFilename( filename );
	reader->read();

	delete readerFactory;
	delete reader;
	*/
	// ##############################################

	const int laps = 4;

	auto readerFactory = new Factory<IReader>();
	auto reader = readerFactory->create("csv");
	reader->setFilename( filename );

	RaceTrack* track = new RaceTrack( laps, reader );
	track->start();

	auto [kartId, start, end, laptime] = track->getWinner();
	
	std::cout << "Winner kart " << kartId << " start:" << start << " end:" << end << " laptime:" << laptime << '\n';
	std::cout << "Terminating MyLaps Assignment\n";
	return 0;
}
