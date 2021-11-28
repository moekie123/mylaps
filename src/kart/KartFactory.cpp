#include <stdexcept>
#include <string>

#include "IKart.h"
#include "KartBase.h"
#include "Factory.h"

template <>
IKart *Factory< IKart >::create( const std::string &type )
{
    IKart *kart = nullptr;

    if ( type.find( "MyLapsKart" ) != std::string::npos ) 
    {
    
    }

    if ( kart == nullptr )
        throw std::runtime_error( "failed to create kart" );

    return kart;
}
