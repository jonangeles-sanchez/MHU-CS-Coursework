#include <iostream>
#include <cstdlib>
#include "UnitTest++.h"
#include "linkedlist.cpp"

using namespace std;

SUITE(ListTest){
	class ListSetup {
		public:
			List<int> list1;
			List<int> list2;

			void loadList(int num, List<int> &list){

				list.clear();

				srand(time(NULL));
				int randNum;
				for(int i = 0; i < num; i++){
					randNum = rand() % 1000;

					if(list.full()) break;
					Error_code result = list.insert(list.size(), randNum);
					if(result != success){
						cerr << "Error with list.insert()" << endl;
						CHECK(result==success);
					}
				}

			}

	};


	TEST_FIXTURE(ListSetup, TestConstructor){
		CHECK_EQUAL(0, list1.size());
	}

	TEST_FIXTURE(ListSetup, TestInsertAndRetrieve){
		list1.insert(0, 42);
		CHECK_EQUAL(1, list1.size());
		int val;
		list1.retrieve(0, val);
		CHECK_EQUAL(42, val);
		
	}
	TEST_FIXTURE(ListSetup, TestInsertAndRemove){
		loadList(50, list1);

		list1.insert(0, 100);
		list1.insert(50, 101);
		list1.insert(0, 102);

		int val;
		list1.remove(0, val);
		CHECK_EQUAL(102, val);

		list1.remove(50, val);
		CHECK_EQUAL(101, val);

		list1.remove(0, val);
		CHECK_EQUAL(100, val);

		
	}

	TEST_FIXTURE(ListSetup, TestRetrieve){
		//loadList(75, list1);

		list1.insert(0, 42);
		list1.insert(1, 43);
		list1.insert(2, 44);
		int val;
		list1.retrieve(1, val);
		CHECK_EQUAL(43, val);
		list1.retrieve(0, val);
		CHECK_EQUAL(42, val);
		list1.retrieve(2, val);
		CHECK_EQUAL(44, val);
	}


	TEST_FIXTURE(ListSetup, TestClear){
		loadList(75, list1);
		list1.clear();
		CHECK_EQUAL(0, list1.size());
	}

	TEST_FIXTURE(ListSetup, TestEmpty){
		list1.insert(0, 42);
		CHECK_EQUAL(false, list1.empty());
		list1.clear();
		CHECK_EQUAL(true, list1.empty());
	}

	TEST_FIXTURE(ListSetup, TestSize){
		CHECK_EQUAL(0, list1.size());
		loadList(75, list1);
		CHECK_EQUAL(75, list1.size());
	}

	TEST_FIXTURE(ListSetup, TestReplace){
		loadList(75, list1);
		list1.replace(30, 42);
		CHECK_EQUAL(75, list1.size());
		int val;
		list1.remove(30, val);
		CHECK_EQUAL(42, val);
		CHECK_EQUAL(74, list1.size());
	}

	TEST_FIXTURE(ListSetup, TestRangeError){
		loadList(10, list1);

		Error_code result = list1.insert(11, 42);
		CHECK_EQUAL(result, rangeError);

		result = list1.replace(12, 42);
		CHECK_EQUAL(result, rangeError);

		int val;
		result = list1.remove(12, val);
		CHECK_EQUAL(result, rangeError);
	}

	TEST_FIXTURE(ListSetup, TestCopyConstructor){
		loadList(100, list1);
		List<int> list2(list1);
		CHECK_EQUAL(list1.size(), list2.size());

		int val1, val2;
		while(!list1.empty()){
			list1.remove(0, val1);
			list2.remove(0, val2);
			CHECK_EQUAL(val1, val2);
		}
	}

	TEST_FIXTURE(ListSetup, TestAssignmentOp){
		loadList(100, list1);
		list2 = list1;
		CHECK_EQUAL(list1.size(), list2.size());

		int val1, val2;
		while(!list1.empty()){
			list1.remove(0, val1);
			list2.remove(0, val2);
			CHECK_EQUAL(val1, val2);
		}
	}

	TEST_FIXTURE(ListSetup, TestUnderflow){
		list1.clear();

		Error_code result = list1.replace(0, 42);
		CHECK_EQUAL(result, underflow);

		int val;
		result = list1.remove(0, val);
		CHECK_EQUAL(result, underflow);
	}

	TEST_FIXTURE(ListSetup, TestRangeErrorRemove){
		loadList(75, list1);
		int val;

		Error_code result = list1.remove(-1, val);
		CHECK_EQUAL(result, rangeError);

		result = list1.remove(75, val);
		CHECK_EQUAL(result, rangeError);
	}

	TEST_FIXTURE(ListSetup, TestRangeErrorReplace){
		loadList(75, list1);
		int val;

		Error_code result = list1.replace(-1, val);
		CHECK_EQUAL(result, rangeError);

		result = list1.replace(75, val);
		CHECK_EQUAL(result, rangeError);
	}

	TEST_FIXTURE(ListSetup, TestRangeErrorRetrieve){
		loadList(75, list1);
		int val;

		Error_code result = list1.retrieve(-1, val);
		CHECK_EQUAL(result, rangeError);

		result = list1.retrieve(75, val);
		CHECK_EQUAL(result, rangeError);
	}

	TEST_FIXTURE(ListSetup, TestRangeErrorInsert){
		loadList(75, list1);
		int val;

		Error_code result = list1.insert(-1, val);
		CHECK_EQUAL(result, rangeError);

		result = list1.insert(76, val);
		CHECK_EQUAL(result, rangeError);
	}



}

int main(){
	return UnitTest::RunAllTests();
}
