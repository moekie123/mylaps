#pragma once

#include "KartBase.h"

class MyLapsKart : public KartBase {
public:
  MyLapsKart() {}

  void addLaptime(int) override;
};
