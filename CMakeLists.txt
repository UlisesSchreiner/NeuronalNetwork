cmake_minimum_required(VERSION 2.6)
project(redneuronal)
add_definitions(-Wall -std=c++11)


#SET( SDK_PATH "~/devel/sdk" CACHE PATH "Path to SDK" )

#include_directories(${SDK_PATH}/include)

#link_directories(${SDK_PATH}/lib)

add_executable(redneuronal neuron.cpp main.cpp)

install(TARGETS redneuronal RUNTIME DESTINATION bin)
