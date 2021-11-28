#pragma once

#include <string>

template < class T > class Factory 
{
	public:
    		T *create( const std::string &type );
};
