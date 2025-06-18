CXX = g++
CXXFLAGS = -std=c++17 -I. -Ifirmware/due

SRCS = $(wildcard *.cpp) $(wildcard firmware/due/*.cpp) \
       firmware/due/mocks/Wire.cpp firmware/due/mocks/Serial.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: test_build clean

test_build: $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
