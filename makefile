CPP=g++
CPPFLAGS=-Wall

ANSI=-ansi
ISOSTD=

SRCMODULES=Date.cpp
OBJMODULES=$(SRCMODULES:.cpp=.o)
HPPMODULES=$(SRCMODULES:.cpp=.hpp)

%.o: %.cpp %.hpp
	$(CPP) $(CPPFLAGS) $(ANSI) -g $< -c -o $@ $(ISOSTD)

main: main.cpp $(OBJMODULES)
	$(CPP) $(CPPFLAGS) $(ANSI) -g $^ -o $@ $(ISOSTD)