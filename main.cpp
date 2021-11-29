#include <iostream>

#include "Factory.h"
#include "IKart.h"
#include "IReader.h"

#include "RaceTrack.h"

int main(int argc, char *argv[]) {

  std::string filename;

#ifdef DEBUG
  std::cout << "Booting MyLaps Assignment\n";
#endif

  // Store (csv) filename
  if (argc > 1)
    filename = argv[1];
  else
    throw std::runtime_error("csv filename missing");

  std::cout << "Datasource: " << filename << '\n';

  const int laps = 4;

  auto readerFactory = new Factory<IReader>();
  auto reader = readerFactory->create("csv");
  reader->setFilename(filename);

  RaceTrack *track = new RaceTrack(laps, reader);
  track->start();

  auto [kartId, start, end, laptime] = track->getWinner();

  // TODO start en end should be converted to human readble timestamp
  std::cout << "Winner kart " << kartId << "\n\t start timestamp:" << start
            << "\n\t end timestamp:" << end << "\n\t laptime:" << laptime
            << " seconds\n";

#ifdef DEBUG
  std::cout << "Terminating MyLaps Assignment\n";
#endif

  return 0;
}
