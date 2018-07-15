
CXX = g++

INC = -I . -I ../src
LDLIBS =
LDFLAGS = 
CXXFLAGS = -std=c++14 -Wall -pthread  -pipe -Wall -o2 -lm

TARGET = GCD

SRCS = $(wildcard *.cpp)

$(TARGET): GCD.cpp
	$(CXX) $(CXXFLAGS) GCD.cpp -o GCD $(INC)

