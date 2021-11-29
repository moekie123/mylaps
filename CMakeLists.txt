cmake_minimum_required (VERSION 3.21.0 )

project( MyLaps
	DESCRIPTION "MyLaps Assignment"
	VERSION 0.1
	LANGUAGES CXX )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable
add_executable( ${PROJECT_NAME} "")

# Add source files
target_sources( ${PROJECT_NAME} PRIVATE	main.cpp )

# Set build flags
list( APPEND CXX_COMPILER_FLAGS "-Wall" "-Wextra")
message("C++ compiler flags: ${CXX_COMPILER_FLAGS}")
target_compile_options( ${PROJECT_NAME} PRIVATE ${CXX_COMPILER_FLAGS} )

# Set debug flag
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Setup testing
enable_testing()
include( cmake/googletest.cmake )

include_directories(include)
add_subdirectory(src)

target_link_libraries( ${PROJECT_NAME} racetrack-objs kart-objs reader-objs )
