cmake_minimum_required(VERSION 2.8)

# The project name
project( DIP_HW02 )

# Find OpenCV Package and include it
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Set C++ 11
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Project sources
set ( PROJECT_SOURCES src/common.h )

# The main program
add_executable( DIP_HW02 src/main.cpp ${PROJECT_SOURCES})

# Add link libraries
target_link_libraries( DIP_HW02 ${OpenCV_LIBS} )

