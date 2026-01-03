CXX = g++
CXXFLAGS = -g -Wall -I C:/CppProjects/include 

SRC = ex13.cpp Ratio.cpp 
OBJ = $(SRC:.cpp=.o)

TARGET = ex13.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe