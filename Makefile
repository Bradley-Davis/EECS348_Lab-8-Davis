# Compiler and flags
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Final executable name
TARGET   = main.exe

# Compile main.cpp and matrix.cpp in one step into the executable
all: $(TARGET)

$(TARGET): main.cpp matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) main.cpp matrix.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)