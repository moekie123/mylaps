#include <stdexcept>
#include <string>

#include "IKart.h"
#include "Factory.h"

#include "MyLapsKart.h"

template <>
IKart *Factory< IKart >::create( const std::string &type )
{
    IKart *kart = nullptr;

    if ( type.find( "MyLaps" ) != std::string::npos ) 
    {
	kart = new MyLapsKart();    
    }

    if ( kart == nullptr )
        throw std::runtime_error( "failed to create kart of type: " + type );

    return kart;
}
