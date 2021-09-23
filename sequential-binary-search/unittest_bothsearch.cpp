#include <iostream>
#include <cstdlib>
#include "UnitTest++.h"
#include "searchUtils.h"

using namespace std;

SUITE(ListTest){
	class ListSetup {
		public:
			List<int> list1;
			List<int> list2;

			void loadList(int num, List<int> &list){

				list.clear();

				srand(time(NULL));
				int randNum = 0;
				for(int i = 0; i < num; i++){
					randNum = (rand() % 10) + randNum;

					if(list.full()) break;
					Error_code result = list.insert(list.size(), randNum);
					if(result != success){
						cerr << "Error with list.insert()" << endl;
						CHECK(result==success);
					}
				}

			}

	};

	TEST_FIXTURE(ListSetup, TestBinaryTrue){
		for(int i = 0; i < 30; i++)
			list1.insert(i, i);

		bool foundTerm = binarySearch(list1, rand() % 10);
		CHECK_EQUAL(true, foundTerm);


	}

	TEST_FIXTURE(ListSetup, TestBinarySearchFalse){

		for(int i = 0; i < 100; i++)
			list1.insert(i, i);

		bool foundTerm = binarySearch(list1, 2000);
		CHECK_EQUAL(false, foundTerm);

	}


	TEST_FIXTURE(ListSetup, TestSequentialTrue){
		for(int i = 0; i < 30; i++)
			list1.insert(0, i);

		bool foundTerm = sequentialSearch(list1, rand() % 10);
		CHECK_EQUAL(true, foundTerm);


	}

	TEST_FIXTURE(ListSetup, TestSequentialSearchFalse){

		for(int i = 0; i < 100; i++)
			list1.insert(0, i);

		bool foundTerm = sequentialSearch(list1, 2000);
		CHECK_EQUAL(false, foundTerm);

	}
}

int main(){
	return UnitTest::RunAllTests();
}
