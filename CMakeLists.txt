cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(TheCrew3)

add_library(Auxiliaries STATIC qSort.cpp deleter.cpp)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 
add_library(Vehicles SHARED vehicle.cpp camel.cpp rapidCamel.cpp centaur.cpp bootsAWD.cpp eagle.cpp magicCarpet.cpp broom.cpp)

add_executable(Racing main.cpp)
target_link_libraries(Racing Vehicles Auxiliaries)