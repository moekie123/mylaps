#include <iostream>

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

	std::cout << "Terminating MyLaps Assignment\n";
	return 0;
}
