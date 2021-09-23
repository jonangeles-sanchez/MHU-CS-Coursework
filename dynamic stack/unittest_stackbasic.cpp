#include <iostream>
#include <cstdlib>
#include "UnitTest++.h"
#include "stack.h"

using namespace std;

SUITE(StackTest){
	class StackSetup {
		public:
			Stack s1;
			Stack s2;

			void loadStack(int num, Stack &s){

				//clear it out
				while(!s.empty()) s.pop();

				srand(time(NULL));
				int randNum;
				for(int i = 0; i < num; i++){
					randNum = rand() % 1000;

					Error_code result = s.push(randNum);
					if(result != success){
						cerr << "Error with push()" << endl;
						CHECK(result==success);
					}
				}

			}

	};


	TEST_FIXTURE(StackSetup, TestConstructor){
		CHECK_EQUAL(true, s1.empty());
	}

	TEST_FIXTURE(StackSetup, TestPush){
		s1.push(42);
		CHECK_EQUAL(false, s1.empty());
		
	}

	TEST_FIXTURE(StackSetup, TestPushAndTop){
		s1.push(42);
		int val;
		s1.top(val);
		CHECK_EQUAL(42, val);
		
	}

	TEST_FIXTURE(StackSetup, TestPushPop100){
		int i;
		for(i = 0; i < 100; i++){
			s1.push(i+1);
		}

		Stack_entry temp;

		while(!s1.empty()){
			s1.top(temp);
			s1.pop();

			CHECK_EQUAL(i--, temp);
		}
	}

	TEST_FIXTURE(StackSetup, TestPushAndPop){

		int val = 42;
		s1.push(val);

		CHECK_EQUAL(false, s1.empty());

		s1.pop();
		CHECK_EQUAL(true, s1.empty());

	}

	TEST_FIXTURE(StackSetup, TestEmpty){
		s1.push(42);
		CHECK_EQUAL(false, s1.empty());
		s1.pop();
		CHECK_EQUAL(true, s1.empty());
	}

	TEST_FIXTURE(StackSetup, TestUnderflowTop){
		int val;
		Error_code result = s1.top(val);
		CHECK_EQUAL(result, underflow);

		loadStack(1, s1);

		result = s1.top(val);
		CHECK_EQUAL(result, success);

	}

	TEST_FIXTURE(StackSetup, TestUnderflowPop){
		
		
		Error_code result = s1.pop();
		CHECK_EQUAL(result, underflow);

		loadStack(1, s1);

		result = s1.pop();
		CHECK_EQUAL(result, success);

		result = s1.pop();
		CHECK_EQUAL(result, underflow);

	}
}

int main(){
	return UnitTest::RunAllTests();
}
