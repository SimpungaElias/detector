cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Simulation)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROEJCT_SOURCE_DIR}/*.hh)

add_executable(detector detector.cc ${sources} ${header})
target_link_libraries(detector ${Geant4_LIBRARIES})

add_custom_target(Simulation DEPENDS detector)

set(SOURCES
    MyDetectorConstruction.cc
    Physics.cc
    MyRunAction.cc
    MyEventAction.cc
    generator.cc  # Make sure generator.cc is included
    MyMainProgram.cc


)
