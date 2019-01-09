cmake_minimum_required(VERSION 3.13)
project(NN_class)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_library(NN_class SHARED
        activationFunctions.cpp
        activationFunctions.h
        neuron.cpp
        neuron.h
        NN.cpp
        NN.h
        NNerrors.h)