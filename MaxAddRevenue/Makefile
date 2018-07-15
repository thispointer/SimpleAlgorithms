
CXX = g++

INC = -I . -I ../src
LDLIBS =
LDFLAGS = 
CXXFLAGS = -std=c++14 -Wall -pthread  -pipe -Wall -o2 -lm

TARGET = maxAddRevenue

SRCS = $(wildcard *.cpp)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $< -o $@ $(INC)
