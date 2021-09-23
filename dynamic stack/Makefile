CC			= g++
CFLAGS		= -g -Wall

LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++

TARGET		= mytest
TEST		= test
UTEST		= unittest_stackbasic.cpp
default:	all

gactions:	clean downloadtest stack.o 
	sudo apt install libunittest++-dev
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) stack.cpp ${UTEST} $(LIBS)

test:		clean downloadtest stack.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) stack.cpp ${UTEST} $(LIBS)
	
all:		clean stack.o
	$(CC) $(CFLAGS) -o $(TARGET) stack.cpp teststack.cpp 

downloadtest:
	wget -q -N http://huckleberry.mhu.edu/cs220/${UTEST}

stack.o:
	$(CC) $(CFLAGS) -c stack.cpp 

clean:
	$(RM) $(TEST) $(TARGET) *.o
