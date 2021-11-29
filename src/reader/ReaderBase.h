#pragma once

#include "IReader.h"

class ReaderBase : public IReader {
public:
  // Interface methods
  void setFilename(const std::string &) override;

  // Vistable methods
  void accept(ReaderVisitor *visitor) override;
};
