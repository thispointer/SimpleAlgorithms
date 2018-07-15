
CXX = g++

INC = -I . -I ../src
LDLIBS =
LDFLAGS = 
CXXFLAGS = -std=c++14 -Wall -pthread

TARGET = MaxPairwiseProduct

SRCS = $(wildcard *.cpp)

$(TARGET): MaxPairwise
	$(CXX) $(CXXFLAGS) -pipe -Wall -o2 -lm MaxPairwise.cpp -o MaxPairwiseProduct $(INC)

