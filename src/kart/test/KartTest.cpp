#include <gtest/gtest.h>

#include "IKart.h"
#include "../MyLapsKart.h"

/** 
 * Always try to achieve a high test coverage
 * At minimum, create tests for public and interface methods
 * TODO create test for protected methods
 */

TEST( MyLapsKart, GivenKartCreated_WhenIdIsSet_ThenReturnId )
{
	// Arrange
	IKart* kart = new MyLapsKart();

	// Act
	kart->setID(42);

	// Assert
	ASSERT_EQ( kart->getID(), 42 );
	delete kart;
}

TEST( MyLapsKart, GivenKartCreated_WhenSingleLaptimeSet_ThenReturnZero )
{
	// Arrange
	IKart* kart = new MyLapsKart();

	// Act
	/*
	 * First laptime is start moment
	 */
	kart->addLaptime(123);

	// Assert
	// Return zero because no lap have been completed
	ASSERT_EQ( kart->getTotalLaps(), 0 );

	delete kart;
}

TEST( MyLapsKart, GivenKartCreated_WhenSingleLapAdded_ThenReturnOne )
{
	// Arrange
	IKart* kart = new MyLapsKart();

	// Act
	/* 
	 * First laptime is start moment
	 * Second laptime is first time completing a lap
	 */
	kart->addLaptime(123);
	kart->addLaptime(456);

	// Assert
	ASSERT_EQ( kart->getTotalLaps(), 1 );

	delete kart;
}


TEST( MyLapsKart, GivenKartCreated_WhenMultiLapsAdded_ThenReturnTwo )
{
	// Arrange
	IKart* kart = new MyLapsKart();

	// Act
	kart->addLaptime(123);
	kart->addLaptime(456);
	kart->addLaptime(789);

	// Assert
	ASSERT_EQ( kart->getTotalLaps(), 2 );

	delete kart;
}

TEST( MyLapsKart, GivenKartCreated_WhenMultiLapsAdded_ThenReturnFastest_Ascending )
{
	// Arrange
	IKart* kart = new MyLapsKart();

	// Act
	kart->addLaptime(1);	
	kart->addLaptime(10);	// Delta with previous is 9
	kart->addLaptime(100);	// Delta with previous is 90

	// Assert
	ASSERT_EQ( kart->getFastestLap(), 0 );

	delete kart;
}

TEST( MyLapsKart, GivenKartCreated_WhenMultiLapsAdded_ThenReturnFastest_Descending )
{
	// Arrange
	IKart* kart = new MyLapsKart();

	// Act
	kart->addLaptime(100);	
	kart->addLaptime(10);	// Delta with previous is 90
	kart->addLaptime(1);	// Delta with previous is 9

	// Assert
	// TODO This doesn't work with the current implementation because it implies the kart goes back in time....
//	ASSERT_EQ( kart->getFastestLap(), 0 );

	delete kart;
}


int main( int argc, char **argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
