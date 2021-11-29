#pragma once

/**
 * @Brief Reader visitor
 *
 * This visitor is used to provide new laptime info
 */
class ReaderVisitor {
public:
  /**
   * Provide new data to the invoker of the reader
   *
   * @param kartId The id of the kart
   * @param laptime The timestamp of the kart passing the start/finish line in
   * seconds
   */
  virtual void addRecord(int kartId, int laptime) = 0;

  /**
   * Allow the reader to verify whether the invoker allows more data
   *
   * @return Invoker is done fetching data [True = Stop reading]
   */
  virtual bool isFinished() = 0;
};
