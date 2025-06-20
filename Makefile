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

# Unit test targets

test_firmware: tests/firmware/test_ddsdriver \
 tests/firmware/test_eeprommanager \
 tests/firmware/test_commandparser \
 tests/firmware/test_menusystem

tests/firmware/test_ddsdriver: $(SRCS) tests/firmware/test_ddsdriver.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

tests/firmware/test_eeprommanager: $(SRCS) tests/firmware/test_eeprommanager.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

tests/firmware/test_commandparser: $(SRCS) tests/firmware/test_commandparser.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

tests/firmware/test_menusystem: $(SRCS) tests/firmware/test_menusystem.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

run_firmware_tests: test_firmware
	./tests/firmware/test_ddsdriver
	./tests/firmware/test_eeprommanager
	./tests/firmware/test_commandparser
	./tests/firmware/test_menusystem

.PHONY: test_cli

test_cli:
	pytest -q tests/cli

.PHONY: test_gui

test_gui:
	# Fallback to stubbed GUI tests if modules cannot be downloaded
	cd tests/gui && (go test ./... || go test -tags=fyne_stub ./...)

.PHONY: test_all

test_all: run_firmware_tests test_cli test_gui
