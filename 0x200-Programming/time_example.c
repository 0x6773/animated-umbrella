#include <stdio.h>
#include <time.h>
int main() 
{
	long seconds_since_epoch;
	struct tm current_time, *time_ptr;
	int hour, minute, second;

	seconds_since_epoch = time(0); 
	printf("time() - seconds since epoch: %ld\n", seconds_since_epoch);
	time_ptr = &current_time;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
	localtime_r(&seconds_since_epoch, time_ptr);
#pragma GCC diagnostic pop
	hour = current_time.tm_hour; 
	minute = time_ptr->tm_min;
	second = *((int *) time_ptr); 
	printf("Current time is: %02d:%02d:%02d\n", hour, minute, second);

	return 0;
}

