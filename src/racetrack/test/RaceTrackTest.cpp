#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "RaceTrack.h"
#include "IReader.h"
#include "mocks/ReaderMock.h"

/** 
 * Always try to achieve a high test coverage
 * At minimum, create tests for public and interface methods
 * TODO create test for protected methods
 */

using ::testing::_;

TEST( RaceTrack, MockExample )
{
	// Arrange
	ReaderMock mock;
	auto* track = new RaceTrack( 4, &mock );

	// Act
	EXPECT_CALL( mock, accept(_) );
	track->start();

	// Assert
}

int main( int argc, char **argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
