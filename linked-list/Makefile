CC			= g++
CFLAGS		= -g -Wall
TARGET		= linkedList

#LFLAGS		= -L/usr/lib64
LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++
TRAVINC		= -I/usr/include/unittest++
TEST		= test
default:	all

travis:		clean list.o
	$(CC) $(CFLAGS) $(TRAVINC) ${INCLUDES} -o $(TEST) linkedlist.cpp unittest_ll.cpp $(LIBS)

test:		clean downloadtest list.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) linkedlist.cpp unittest_ll.cpp $(LIBS)
	
all:		clean list.o
	$(CC) $(CFLAGS) -o $(TARGET) linkedlist.cpp simpletest.cpp 

downloadtest:
	wget -q -N http://huckleberry.mhu.edu/cs220/unittest_ll.cpp

list.o:
	$(CC) $(CFLAGS) -c linkedlist.cpp 

clean:
	$(RM) $(TEST) $(TARGET) *.o
