CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic 
CXXFLAGS += -ggdb
LDFLAGS = -lboost_date_time

OBJS = LandScape.o Character.o DesertSpace.o WaterSpace.o MineSpace.o DungeonSpace.o main.o getInt.o Menu.o

SRCS = LandScape.cpp Character.cpp DesertSpace.cpp WaterSpace.cpp MineSpace.cpp DungeonSpace.cpp main.cpp getInt.cpp Menu.cpp 

HEADERS = Menu.hpp getInt.hpp LandScapeUtilities.hpp LandScape.hpp Character.hpp Space.hpp DesertSpace.hpp WaterSpace.hpp MineSpace.hpp DungeonSpace.hpp 

landscape: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o landscape 

${OBJS}: ${HEADERS} ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o landscape 
