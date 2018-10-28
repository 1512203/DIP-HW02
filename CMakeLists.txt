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
set ( SOURCE_DIR src )
set ( PIXEL_QUANTIZATORS_DIR src/pixel_quantizators )
set ( PROJECT_SOURCES 
    ${SOURCE_DIR}/common.h 
    ${SOURCE_DIR}/common.cpp 
    ${SOURCE_DIR}/BaseProcessor.h 
    ${SOURCE_DIR}/BaseProcessor.cpp 
    ${SOURCE_DIR}/HistogramEqualizator.h 
    ${SOURCE_DIR}/HistogramEqualizator.cpp 
    ${PIXEL_QUANTIZATORS_DIR}/PixelQuantizator.h 
    ${PIXEL_QUANTIZATORS_DIR}/PixelQuantizator.cpp 
    ${PIXEL_QUANTIZATORS_DIR}/BChannelQuantizator.h 
    ${PIXEL_QUANTIZATORS_DIR}/BChannelQuantizator.cpp 
    ${PIXEL_QUANTIZATORS_DIR}/GChannelQuantizator.h 
    ${PIXEL_QUANTIZATORS_DIR}/GChannelQuantizator.cpp 
    ${PIXEL_QUANTIZATORS_DIR}/RChannelQuantizator.h 
    ${PIXEL_QUANTIZATORS_DIR}/RChannelQuantizator.cpp 
    ${PIXEL_QUANTIZATORS_DIR}/GrayLevelQuantizator.h 
    ${PIXEL_QUANTIZATORS_DIR}/GrayLevelQuantizator.cpp 
    ${PIXEL_QUANTIZATORS_DIR}/HChannelQuantizator.h 
    ${PIXEL_QUANTIZATORS_DIR}/HChannelQuantizator.cpp 
)

# The main program
add_executable( DIP_HW02 ${SOURCE_DIR}/main.cpp ${PROJECT_SOURCES} )

# Add link libraries
target_link_libraries( DIP_HW02 ${OpenCV_LIBS} )

