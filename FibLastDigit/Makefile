
CXX = g++

INC = -I . -I ../src
LDLIBS =
LDFLAGS = 
CXXFLAGS = -std=c++14 -Wall -pthread  -pipe -Wall -o2 -lm

TARGET = FibLastDigit

SRCS = $(wildcard *.cpp)

$(TARGET): fibLastDigit.cpp
	$(CXX) $(CXXFLAGS) fibLastDigit.cpp -o FibLastDigit $(INC)

