
CXX = g++

INC = -I . -I ../src
LDLIBS =
LDFLAGS = 
CXXFLAGS = -std=c++14 -Wall -pthread  -pipe -Wall -o2 -lm

TARGET = Fibonacci

SRCS = $(wildcard *.cpp)

$(TARGET): fibonacci.cpp
	$(CXX) $(CXXFLAGS) fibonacci.cpp -o Fibonacci $(INC)

