#pragma once

#include <map>

#include "IReader.h"
#include "ReaderVisitor.h"

#include "IKart.h"

/**
 * TODO Rename this class to something that is better representing its purpose
 *
 * @Brief RaceTrack is the main class that holds all karts and processes new
 * laptimes
 *
 * It holds a visitor for the reader.
 */
class RaceTrack : public ReaderVisitor {
public:
  /**
   * (Constructor) Create a new race
   * @param lapcount The amount of laps to be driven
   * @param datasource The datasource representing lap info
   */
  RaceTrack(int lapcount, IReader *datasource);

  /**
   * Command to start reading from the datasource and process new data
   */
  void start();

  /**
   * Race winner getter
   *
   * The winner is the kart who has driven the fastest lap
   *
   * TODO: With so much info consider just returning the IKart instead
   * @return KartInfo <KartId, start, end, laptime>
   */
  std::tuple<int, int, int, int> getWinner();

private:
  const int mLaps;
  IReader *mReader;

  std::map<int, IKart *> mKarts;

  // Visitor Interface
  void addRecord(int, int) override;
  bool isFinished() override;
};
