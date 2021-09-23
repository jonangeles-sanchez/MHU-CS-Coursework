CC			= g++
CFLAGS		= -g -Wall
TARGET		= checker
default:	all

all:		clean stack.o palindromeChecker.o 
	$(CC) $(CFLAGS) -o $(TARGET) stack.o palindromeChecker.o

stack.o:
	$(CC) $(CFLAGS) -o stack.o -c stack.cpp 

palindromeChecker.o: 	
	$(CC) $(CFLAGS) -o palindromeChecker.o -c palindromeChecker.cpp 

clean:
	$(RM) $(TARGET) *.o
