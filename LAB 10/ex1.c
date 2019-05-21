/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h> /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h> /* Semaphore */

/* prototype for thread routine */
void handler ( void *ptr );

/* global vars */
/* 
semaphores are declared global so they can be accessed in main() and in thread routine, here, the semaphore is used as a mutex. 
*/
sem_t mutex;
int counter; //shared variable

int main() {
	int i[2] = {0, 1};
	pthread_t thread_a, thread_b;
	counter = 0;
	sem_init(&mutex, 0, 1);
	/*Initialize mutex to 1 and 2nd param zero means mutex is local*/
	/*Note: you can check for successful initialization by evaluating the return value of semaphore and pthreads*/
	
	//Initializing and creating threads 
	pthread_create(&thread_a, 0, (void *) &handler, (void *) &i[0]);
	pthread_create(&thread_b, 0, (void *) &handler, (void *) &i[1]);
	pthread_join(thread_a,NULL);
	pthread_join(thread_b,NULL);
	sem_destroy(&mutex);
	return 0;
}

void handler (void *ptr) {
	int x = *((int*)ptr);

	printf("sem [INFO] Thread %d Waiting to enter in critical region. \n", x);
	sem_wait(&mutex); 
	//Critical Region Starts
	sleep(1);
            printf("sem [INFO] Thread %d Enters in Critical Region. \n", x);
		printf("sem [INFO] Thread %d Value of Counter is %d.\n",x,counter);
		printf("sem [INFO] Thread %d Increamenting The Value of counter\n",x);
		counter++;
		printf("sem [INFO] Thread %d New value of counter is: %d\n",x, counter);
		printf("sem [INFO] Thread %d Exiting Critical Region.\n", x);
	//Critical Region Ends
	sem_post(&mutex);
	pthread_exit(0);
}
