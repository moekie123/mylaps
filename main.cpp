#include <iostream>

#include "Factory.h"
#include "IKart.h"
#include "IReader.h"

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

	// Kart Example	
	auto kartFactory = new Factory<IKart>();
	auto kart = kartFactory->create("MyLaps");
	kart->setID(1);
	delete kartFactory;
	delete kart;

	// Reader Example	
	auto readerFactory = new Factory<IReader>();
	auto reader = readerFactory->create("csv");
	delete readerFactory;
	delete reader;

	// ##############################################
	std::cout << "Terminating MyLaps Assignment\n";
	return 0;
}
