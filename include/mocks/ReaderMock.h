#pragma once 

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "IReader.h"
#include "ReaderVisitor.h"

#include <string>

class ReaderMock : public IReader
{
  public:
	MOCK_METHOD( void, setFilename, ( const std::string &), ( override ));
	MOCK_METHOD( void, read, (), ( override ));
	MOCK_METHOD( void, accept, ( ReaderVisitor* ), ( override ));
};
