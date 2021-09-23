#include <iostream>
#include <cstdlib>
#include "UnitTest++.h"
#include "sortUtils.h"
#include "mjgTimer.h"

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
					randNum = rand() % 500;

					if(list.full()) break;
					Error_code result = list.insert(list.size(), randNum);
					if(result != success){
						cerr << "Error with list.insert()" << endl;
						CHECK(result==success);
					}
				}

			}

			bool isSorted(List<int> &list){
				int size = list.size();
				if(size <= 1) return true;

				int val1, val2;
				list.retrieve(0, val1);
				for(int i = 1; i < size; i++){
					list.retrieve(i, val2);

					if(val2 < val1){
						return false;
					}
					val1 = val2;
				}

				return true;
		
			}

	};


	TEST_FIXTURE(ListSetup, TestBubbleSort){
		list1.insert(0, 2);
		list1.insert(1, 1);

		bubbleSort(list1);

		CHECK_EQUAL(true, isSorted(list1));
	}

	TEST_FIXTURE(ListSetup, TestNearlySortedList){
		for(int i = 0; i < 50; i++){
			list1.insert(i, i);
		}

		list1.replace(0, 100);
		bubbleSort(list1);
		CHECK_EQUAL(true, isSorted(list1));
	}

	TEST_FIXTURE(ListSetup, TestListUnchanged){
		loadList(20, list1); 
		list2 = list1;

		bubbleSort(list1);

		CHECK_EQUAL(list2.size(), list1.size());
		if(list1.size() == list2.size()) {

			int temp, temp2;
			for(int i = 0; i < list1.size(); i++){
				list1.retrieve(i, temp);

				bool found = false;
				for(int j = 0; j < list2.size(); j++){
					list2.retrieve(j, temp2);
					if(temp == temp2){
						list2.remove(j, temp2);
						found = true;
						break;
					}
				}

				CHECK_EQUAL(true, found);
			}

			CHECK_EQUAL(0, list2.size());
		}

	}

	TEST_FIXTURE(ListSetup, TestReverseSorted){
		for(int i = 0; i < 50; i++){
			list1.insert(i, 50 - i);
		}

		bubbleSort(list1);
		CHECK_EQUAL(true, isSorted(list1));
	}

	TEST_FIXTURE(ListSetup, TestLargeSort){
		loadList(10000, list1);
		CHECK_EQUAL(false, isSorted(list1));

		//print a warning
		cout << "This could take between 5-15 seconds...hang in there" << endl;

		//see how long it takes
		double timer = getNow();
		bubbleSort(list1);
		timer = getElapsed(&timer);

		cout << "Large bubble sort took " << timer << " s" << endl;
		CHECK_EQUAL(true, isSorted(list1));
	}
}

int main(){
	return UnitTest::RunAllTests();
}
