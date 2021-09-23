#include <iostream>
#include <cstdlib>
#include "UnitTest++.h"
#include "equeue.h"

using namespace std;

SUITE(Extended_queueTest){
	class Extended_queueSetup {
		public:
			Extended_queue q1;
			Extended_queue q2;
			const int MAX = 100;

			void loadExtended_queue(int num, Extended_queue &q){

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


	TEST_FIXTURE(Extended_queueSetup, TestConstructor){
		CHECK_EQUAL(true, q1.empty());
	}

	TEST_FIXTURE(Extended_queueSetup, TestAppend){
		q1.append(42);
		CHECK_EQUAL(false, q1.empty());
		
	}

	TEST_FIXTURE(Extended_queueSetup, TestAppendAndRetrieve){
		q1.append(42);
		int val;
		q1.retrieve(val);
		CHECK_EQUAL(42, val);
		
	}

	TEST_FIXTURE(Extended_queueSetup, TestAppendRemove100){
		for(int i = 0; i < MAX; i++){
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

	TEST_FIXTURE(Extended_queueSetup, TestAppendPlusServe){

		int val = 42;
		q1.append(val);

		CHECK_EQUAL(false, q1.empty());

		q1.serve();
		CHECK_EQUAL(true, q1.empty());

	}

	TEST_FIXTURE(Extended_queueSetup, TestEmpty){
		q1.append(42);
		CHECK_EQUAL(false, q1.empty());
		q1.serve();
		CHECK_EQUAL(true, q1.empty());
	}

	TEST_FIXTURE(Extended_queueSetup, TestFull){
		loadExtended_queue(MAX, q1);
		CHECK_EQUAL(true, q1.full());
		q1.serve();
		CHECK_EQUAL(false, q1.full());
	}

	TEST_FIXTURE(Extended_queueSetup, TestClear){
		loadExtended_queue(MAX, q1);
		CHECK_EQUAL(true, q1.full());
		q1.clear();
		CHECK_EQUAL(false, q1.full());
		CHECK_EQUAL(true, q1.empty());
	}

	TEST_FIXTURE(Extended_queueSetup, TestRetrieveAndServe){
		int val;
		q1.clear();
		q1.append(42);
		CHECK_EQUAL(false, q1.empty());
		CHECK_EQUAL(1, q1.size());
		q1.retrieveAndServe(val);
		CHECK_EQUAL(true, q1.empty());
		CHECK_EQUAL(val, 42);
	}

	TEST_FIXTURE(Extended_queueSetup, TestUnderflowRetrieve){
		int val;
		Error_code result = q1.retrieve(val);
		CHECK_EQUAL(result, underflow);

		loadExtended_queue(1, q1);

		result = q1.retrieve(val);
		CHECK_EQUAL(result, success);

	}

	TEST_FIXTURE(Extended_queueSetup, TestUnderflowServe){
		
		
		Error_code result = q1.serve();
		CHECK_EQUAL(result, underflow);

		loadExtended_queue(1, q1);

		result = q1.serve();
		CHECK_EQUAL(result, success);

		result = q1.serve();
		CHECK_EQUAL(result, underflow);

	}
}

int main(){
	return UnitTest::RunAllTests();
}
