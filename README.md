# mylaps
MyLaps Assignment

# Assignment
MYLAPS Sports Timing offers the best-in-class sports timing systems to measure, publish and analyze race and practice results for all sports. In this assignment we ask you create a simple piece of software that demonstrates how you build resilient, testable code. It does not have to be a fully functioning, polished solution.
The solution should be build using C++. It may be a command line or GUI application, that’s up to you.
The application should calculate the result of a race based on lap times collected during a race.

## Requirements
* A race consists of up to five drivers racing around the track for a fixed number of laps (driving from the start/finish line to the start/finish line).
* The kart number and the time of day are measured by the timing system each time a driver passes the start/finish line of the racing track. The software should accept these lap times in the form of the attached karttimes.csv file.
* The race is finished when one of the drivers completes all laps.
* The winner of a race is the driver who has driven the fastest lap.
* The application should return the winner of the race, including the winning lap.

## Notes
* Your assignment will be evaluated on technical design, code quality, testability and commit hygiene.
* Make sure that your project is accessible on a git repository.
* Please do not spend more than 8 hours on this assessment.
* Add a note for the parts you did not have time for, but you think should have been
included.

## Todo
Due to limited time the following points where not completed
* Documentation
** Implemented doxygen generator
** Document (atleast) interface classes and public member variables
* Memory leaks prevention
** Use smart pointers std::unique<> in stead of raw pointer
* Clear print output polution
** Create logger object
** Maybe use external library like spdlog
** Use info/debug/trace log levels
* Added more test coverage
** Create mocks for all interface objects
** Create BDD test (cucumber?)
* Create hierachrical namespaces
* Debugging
** Set debug flag in CMake such that symbols are available in gdb
* Rename RaceTrack

## Other considerations
Some exceptions and scenario's that came up while writing the code.

### Requirements logic
Is it correct that kart who has driven the fastest lap is the winner ?
This potentially means that the first driver completing all laps won't be the winner..

In other words:
Why do the measurements stops after the first kart finishes all laps ?
The fastest lap can still be driver by other karts in the their last lap...

### Race Requirements
What happens when non of the karts finishes all laps ?

Similiar to the predefined lap count, why aren't the amount of karts a predefined?

###  CSV (Contract) Exceptions
* How strict is the format of the CSV ?
** Consider using the header to determine the order of the columns

* Are the measurements in the file always chronical ?
** At the moment a laptime is calculated as the delte between last and second last measurement point...

* What should happen if a record in the csv file is corrupt?
