#pragma once

#include "ReaderVisitor.h"
#include <string>

class IReader {
public:
  virtual ~IReader() {}

  virtual void setFilename(const std::string &) = 0;

  virtual void read() = 0;

  virtual void accept(ReaderVisitor *visitor) = 0;

protected:
  std::string mFilename;
};
