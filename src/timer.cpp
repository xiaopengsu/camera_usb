#include<iostream>
#include <sys/time.h>
using namespace std;
int64_t getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv,NULL);
	return tv.tv_sec * 1000 + tv.tv_usec/1000;
}
int main()
{
	int64_t curTime;
	int64_t start = getCurrentTime();
	while(true)
	{
		curTime = getCurrentTime();
		long i=0;
		while(i<1000000) i++;
		cout << curTime - start <<endl;
	}
	return 0;
}
