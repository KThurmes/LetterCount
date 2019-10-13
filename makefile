#target: dependencies
#	rule to build
#must use tab for rules

CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
OBJS = main.o output_letters.o count_letters.o
SRCS = *.cpp
HEADERS = output_letters.hpp count_letters.hpp
#LDFLAGS = -lboost_date_time (any libraries you want to link)

lab1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o lab2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o lab2

valgrind:
	valgrind lab2