CC			= g++
CFLAGS		= -g -Wall
TARGET		= bubbleSort

#LFLAGS		= -L/usr/lib64
LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++
TRAVINC		= -I/usr/include/unittest++
TEST		= test
default:	all

travis:		clean downloadtest list.o utils.o mjgTimer.o
	$(CC) $(CFLAGS) $(TRAVINC) ${INCLUDES} -o $(TEST) \
		utils.o list.o mjgTimer.o unittest_bsort.cpp $(LIBS)

test:		clean downloadtest list.o utils.o mjgTimer.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) \
		utils.o list.o mjgTimer.o unittest_bsort.cpp $(LIBS)

all:		clean list.o utils.o 
	$(CC) $(CFLAGS) -o $(TARGET) list.o utils.o  sortProgram.cpp

downloadtest:
	wget -q -N http://huckleberry.mhu.edu/cs220/unittest_bsort.cpp

list.o:
	$(CC) $(CFLAGS) -o list.o -c doublylinked.cpp 

utils.o: 	
	$(CC) $(CFLAGS) -o utils.o -c sortUtils.cpp 

mjgTimer.o:
	$(CC) $(CFLAGS) -o mjgTimer.o -c mjgTimer.cpp 


clean:
	$(RM) $(TEST) $(TARGET) *.o
