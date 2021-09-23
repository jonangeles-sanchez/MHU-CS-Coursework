/* bubble sort
   Please remove the word 'REMOVE' in file name. 
*/

#include "mjgTimer.h"

double getNow()
{
	struct timeval t;
	double time;

	gettimeofday(&t,NULL);
	time = 0.000001* (t.tv_usec) + t.tv_sec;
	return time;
}

double getElapsed(double *db)
{
	double now = getNow();
	double temp = now - *db;
	return temp;
}
