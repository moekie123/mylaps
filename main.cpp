#include <iostream>

#include "Factory.h"
#include "IKart.h"

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
	
	auto kartFactory = new Factory<IKart>();
	auto kart = kartFactory->create("MyLaps");
	kart->setID(1);
	delete kartFactory;

	// ##############################################
	std::cout << "Terminating MyLaps Assignment\n";
	return 0;
}
