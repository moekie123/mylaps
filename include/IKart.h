#pragma once

#include <tuple>
#include <vector>

/**
 * @Brief Kart Interface Class 
 * 
 * The kart represents an driver participating the Race
 */ 
class IKart {
public:
  virtual ~IKart() {}

  /**
   * Kart Id getter 
   * @return The id of the kart
   */
  virtual int getID() = 0;

  /**
   * Kart Id setter
   * @param id The id of the kart
   */
  virtual void setID( int id ) = 0;

  /**
   * Add a new laptime
   * @param laptime The time in seconds from start of race
   */
  virtual void addLaptime( int laptime ) = 0;

  /**
   * Lap count getter
   *
   * A lap is defined by a start and end time (see IKart::addLaptime() )
   * Therefore 1 lap requires two laptimes
   *
   * @return The amount of laps driving by the kart
   */
  virtual int getTotalLaps() = 0;

  /**
   * Fastest lap getter
   *
   * @return The fastest lap of the race by the Kart
   */
  virtual int getFastestLap() = 0;

  /**
   * Lap info getter
   * @param lapId The id of the lap to return
   * @return The lapinfo <start,end,laptime>
   *
   * TODO What should happen with invalid lapId's
   */
  virtual std::tuple<int, int, int> getLapInfo( int lapId ) = 0;

protected:
  int mId;
  std::vector<int> mLaptimes;
};
