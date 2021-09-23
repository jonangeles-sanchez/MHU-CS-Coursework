#include <iostream>
#include <cstdlib>
#include "UnitTest++.h"
//#include <UnitTest++/UnitTest++.h>
#include "queue.h"

using namespace std;

SUITE(QueueTest){
	class QueueSetup {
		public:
			Queue q1;
			Queue q2;

			void loadQueue(int num, Queue &q){

				//clear it out
				while(!q.empty()) q.serve();

				srand(time(NULL));
				int randNum;
				for(int i = 0; i < num; i++){
					randNum = rand() % 1000;

					Error_code result = q.append(randNum);
					if(result != success){
						cerr << "Error with append()" << endl;
						CHECK(result==success);
					}
				}

			}

	};


	TEST_FIXTURE(QueueSetup, TestConstructor){
		CHECK_EQUAL(true, q1.empty());
	}

	TEST_FIXTURE(QueueSetup, TestAppend){
		q1.append(42);
		CHECK_EQUAL(false, q1.empty());
		
	}

	TEST_FIXTURE(QueueSetup, TestAppendAndRetrieve){
		q1.append(42);
		int val;
		q1.retrieve(val);
		CHECK_EQUAL(42, val);
		
	}

	TEST_FIXTURE(QueueSetup, TestAppendRemove100){
		for(int i = 0; i < 100; i++){
			q1.append(i+1);
		}

		Queue_entry val = 1;
		Queue_entry temp;

		while(!q1.empty()){
			q1.retrieve(temp);
			q1.serve();

			CHECK_EQUAL(val++,temp);
		}
	}

	TEST_FIXTURE(QueueSetup, TestAppendAndServe){

		int val = 42;
		q1.append(val);

		CHECK_EQUAL(false, q1.empty());

		q1.serve();
		CHECK_EQUAL(true, q1.empty());

	}

	TEST_FIXTURE(QueueSetup, TestEmpty){
		q1.append(42);
		CHECK_EQUAL(false, q1.empty());
		q1.serve();
		CHECK_EQUAL(true, q1.empty());
	}

	TEST_FIXTURE(QueueSetup, TestUnderflowRetrieve){
		int val;
		Error_code result = q1.retrieve(val);
		CHECK_EQUAL(result, underflow);

		loadQueue(1, q1);

		result = q1.retrieve(val);
		CHECK_EQUAL(result, success);

	}

	TEST_FIXTURE(QueueSetup, TestUnderflowServe){
		
		
		Error_code result = q1.serve();
		CHECK_EQUAL(result, underflow);

		loadQueue(1, q1);

		result = q1.serve();
		CHECK_EQUAL(result, success);

		result = q1.serve();
		CHECK_EQUAL(result, underflow);

	}
}

int main(){
	return UnitTest::RunAllTests();
}
