CC			= g++
CFLAGS		= -g -Wall
TARGET		= queue

#LFLAGS		= -L/usr/lib64
LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++
TRAVINC		= -I/usr/include/unittest++
TEST		= test
default:	all

travis:		clean downloadbasictest queue.o
	$(CC) $(CFLAGS) $(TRAVINC) ${INCLUDES} -o $(TEST) queue.cpp unittest_qbasic.cpp $(LIBS)

basictest:		clean downloadbasictest queue.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) queue.cpp unittest_qbasic.cpp $(LIBS)

test:		clean downloadtest queue.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) queue.cpp unittest_q.cpp $(LIBS)
	
all:		clean queue.o
	$(CC) $(CFLAGS) -o $(TARGET) queue.cpp simpletest.cpp 

downloadbasictest:
	wget -q -N http://huckleberry.mhu.edu/cs220/unittest_qbasic.cpp

downloadtest:
	wget -q -N http://huckleberry.mhu.edu/cs220/unittest_q.cpp

queue.o:
	$(CC) $(CFLAGS) -c queue.cpp 

clean:
	$(RM) $(TEST) $(TARGET) *.o
