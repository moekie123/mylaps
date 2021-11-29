#pragma once

#include "ReaderVisitor.h"
#include <string>

/**
 * @Brief Reader Interface Class
 *
 * The reader represents the datasource from where the kart laptimes will be
 * retrieved from
 *
 * The Reader has an visitor patter implemented such that it can be 'easy'
 * swapped by other type of data sources Like XML,JSON or even an live stream
 * version
 */
class IReader {
public:
  virtual ~IReader() {}

  /**
   * Set the datasource filename
   *
   * TODO For CSV, JSON and XML this makes senses but for future data stream an
   * <Host/Port> constructor is makes more sense
   * @param filename The name of the file
   */
  virtual void setFilename(const std::string &filename) = 0;

  /**
   * The visitable method for the race to start reading the file
   * @param visitor The source that requests new kart laptimes
   */
  virtual void accept(ReaderVisitor *visitor) = 0;

protected:
  std::string mFilename;
};
