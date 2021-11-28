#include <stdexcept>
#include <string>

#include "IReader.h"
#include "Factory.h"

#include "CSVReader.h"

template <>
IReader *Factory< IReader >::create( const std::string &type )
{
    IReader *reader = nullptr;

    if ( type.find( "csv" ) != std::string::npos ) 
    {
	reader = new CSVReader();    
    }

    if ( reader == nullptr )
        throw std::runtime_error( "failed to create reader of type: " + type );

    return reader;
}
