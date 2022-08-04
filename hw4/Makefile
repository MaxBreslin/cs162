# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = main

all: $(TARGET)

$(TARGET): main.o list.o word.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o list.o word.o

main.o: main.cpp list.h
	$(CC) $(CFLAGS) -c main.cpp

list.o: list.h

word.o: word.h

clean:
	$(RM) $(TARGET)
	$(RM) *.o