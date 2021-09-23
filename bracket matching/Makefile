CC			= g++
CFLAGS		= -g -Wall

LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++

TARGET		= bracket
default:	all

all:		clean stack.o bracketMatching.o
	$(CC) $(CFLAGS) -o $(TARGET) stack.cpp bracketMatching.cpp 

bracketMatching.o: stack.o
	$(CC) $(CFLAGS) -c bracketMatching.cpp 

stack.o:
	$(CC) $(CFLAGS) -c stack.cpp 

clean:
	$(RM) $(TEST) $(TARGET) *.o
