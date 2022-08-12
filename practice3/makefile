#CS 162 Homework Makefile
SOURCES		:= $(wildcard *.cpp)
OBJECTS		:= $(SOURCES:.cpp=.o)
MODULES		:= $(basename $(SOURCES))
EXE			:= main
CC			:= g++
CXX			:= g++
CPPFLAGS		= -g -Wall -Wextra -std=c++17
CXXFLAG		= -g -Wall -Wextra -std=c++17
.PHONY:		all

all:			$(OBJECTS)
	@printf "[building %s from %s]\n" "$(EXE)" "$(MODULES)"
	@$(CXX) -o main $(CPPFLAGS) $(OBJECTS)

%.o:			%.cpp
	@printf "[building %s]\n" "$@"
	@$(CXX) -c $(CPPFLAGS) $< -o $@

%.cpp:
	@printf "[touching %s]\n" "$@"
	@touch $@

clean:
	@-rm $(OBJECTS) main 2>/dev/null 1>/dev/null || true 
