CC			= g++
CFLAGS		= -g -Wall
TARGET		= sim

#LFLAGS		= -L/usr/lib64
LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++
TRAVINC		= -I/usr/include/unittest++
default:	all

all:		clean queue.o mcmarty.o
	$(CC) $(CFLAGS) -o $(TARGET) queue.cpp mcmartysim.cpp 

queue.o:
	$(CC) $(CFLAGS) -c queue.cpp 

mcmarty.o:
	$(CC) $(CFLAGS) -c mcmartysim.cpp

clean:
	$(RM) $(TARGET) *.o
