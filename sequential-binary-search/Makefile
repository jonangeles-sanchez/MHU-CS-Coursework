CC			= g++
CFLAGS		= -g -Wall
TARGET		= search

#LFLAGS		= -L/usr/lib64
LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++
TRAVINC		= -I/usr/include/unittest++
TEST		= test
default:	all

travis:		clean downloadtest list.o utils.o
	$(CC) $(CFLAGS) $(TRAVINC) ${INCLUDES} -o $(TEST) \
		utils.o list.o unittest_bothsearch.cpp $(LIBS)

test:	clean downloadtest list.o utils.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) \
		utils.o list.o unittest_bothsearch.cpp $(LIBS)

all:		clean list.o utils.o
	$(CC) $(CFLAGS) -o $(TARGET) list.o utils.o searchProgram.cpp

downloadtest:
	wget -q -N http://huckleberry.mhu.edu/cs220/unittest_bothsearch.cpp

list.o:
	$(CC) $(CFLAGS) -o list.o -c doublylinked.cpp 

utils.o: 	
	$(CC) $(CFLAGS) -o utils.o -c searchUtils.cpp 

clean:
	$(RM) $(TEST) $(TARGET) *.o
