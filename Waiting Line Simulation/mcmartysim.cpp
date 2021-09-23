/* 
 * Jonathan Angeles-Sanchez
 * Sep 18, 2020
 * Simulates the flow of customers through a line at McMarty's.
 * Makes use of queues.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "queue.h"

using namespace std;

   
int main () {

    //Line of customers - each value in this queue
    //represents the time (minute) a customer arrived
    //at McMarty's and got in line.
    Queue custQ;      

        int simLength,        
        timeArrived,      
        waitTime,          
        maxWait     = 0,  
        numArrivals = 0;
	int temp;
        double totalWait = 0;
        double totalServed = 0;
        
    srand(time(NULL)); //initialize random number generator

    cout << "Enter the length of time to run the McMarty's simulator : ";
    cin >> simLength;
    //Had trouble w/randomizing append & calculating 
    for (int minute = 0; minute < simLength; minute++) {
		int k = rand() % 3 + 0; 
		if (!custQ.empty()) {
			custQ.serve();
			totalServed++;
			waitTime = totalWait - timeArrived;
			temp = waitTime;
			if (temp > maxWait) {
				temp = waitTime;
			}
			if (k == 1) {
				timeArrived = totalWait;
				custQ.append(timeArrived);
				numArrivals++;
				}
			if (k == 2) {
				timeArrived = totalWait;
				custQ.append(timeArrived);
				numArrivals++;
				}
			//Didn't know what to add for k=3||0.
			if (k == 3 || 0) {
			}
			totalWait++;	
		}
		else {
			if (k == 1) {
				timeArrived = totalWait;
				custQ.append(timeArrived);
				numArrivals++;
			}
			if (k == 2) {
				timeArrived = totalWait;
				custQ.append(timeArrived);
				custQ.append(timeArrived);
				numArrivals++;
			}
			if (k == 3 || 0) {	
			}
			totalWait++;
		}
	}

    
    cout << endl;
    cout << "Customers served : " << totalServed << endl;

    if (totalServed > 0) 
        cout << "Average wait     : " << setprecision(2) 
            << double(totalWait)/totalServed << endl;
    else 
        cout << "Average wait     : 0" << endl;

    cout << "Longest wait     : " << waitTime << endl;
    return 0;
}
