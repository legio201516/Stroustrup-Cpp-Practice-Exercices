CXX = g++
CXXFLAGS = -g -Wall -I C:/CppProjects/include 

SRC = ex15.cpp monnaieex15.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = ex15.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe