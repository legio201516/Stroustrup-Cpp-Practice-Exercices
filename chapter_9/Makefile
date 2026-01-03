CXX = g++
CXXFLAGS = -g -Wall -I C:/CppProjects/include 

SRC = ex11.cpp ex11chrono.cpp 
OBJ = $(SRC:.cpp=.o)

TARGET = ex11.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe
