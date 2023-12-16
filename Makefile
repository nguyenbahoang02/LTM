CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17
TARGET = server
SRC = server.cpp

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
	$(CXX) $(CXXFLAGS) -o client client.cpp
clean:
	rm -f $(TARGET)
