
CXX = g++

INC = -I . -I ../src
LDLIBS =
LDFLAGS = 
CXXFLAGS = -std=c++11 -Wall -pthread

TARGET = Sum

SRCS = $(wildcard *.cpp)

$(TARGET): APlusB.cpp
	$(CXX) $(CXXFLAGS) -Wall -c APlusB.cpp -o Sum $(INC)

