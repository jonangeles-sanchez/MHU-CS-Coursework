CC			= g++
CFLAGS		= -g -Wall

LIBS		= -lUnitTest++
INCLUDES	= -I/usr/include/UnitTest++ -I/usr/local/include/UnitTest++

TARGET		= equeue
TEST		= qtest
TEST2		= eqtest
UTEST		= unittest_qbasic.cpp
UTEST2		= unittest_equeue.cpp
default:	all

gactions:	clean downloadtest queue.o equeue.o
	sudo apt install libunittest++-dev
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) queue.cpp ${UTEST} $(LIBS)
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST2) queue.cpp equeue.cpp ${UTEST2} $(LIBS)

test:		clean downloadtest queue.o equeue.o
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST) queue.cpp ${UTEST} $(LIBS)
	$(CC) $(CFLAGS) ${TRAVINC} $(INCLUDES) -o $(TEST2) queue.cpp equeue.cpp ${UTEST2} $(LIBS)
	
all:		clean queue.o equeue.o
	$(CC) $(CFLAGS) -o $(TARGET) queue.cpp equeue.cpp testeq.cpp 

downloadtest:
	wget -q -N http://huckleberry.mhu.edu/cs220/${UTEST}
	wget -q -N http://huckleberry.mhu.edu/cs220/${UTEST2}

queue.o:
	$(CC) $(CFLAGS) -c queue.cpp 

equeue.o:
	$(CC) $(CFLAGS) -c equeue.cpp 

clean:
	$(RM) $(TEST) $(TARGET) *.o
