#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 4
#define MSG "Hello from message"
void *message(long threadid) {
char *msg = "Hello from message";
printf("msgthreads [INFO] Message: %s \t Thread ID: %ld \n", msg, (long) threadid);
}
int main() {
pthread_t threads[NUM_THREADS];
int rc;
long t;
for(t=0;t<NUM_THREADS;t++) {
printf ("IN:main creadting thread %ld\n", t);
rc = pthread_create(&threads[t],0, message,(void *)t);
if(rc > 0){exit(1);}
}

pthread_join(threads[0],0);
pthread_join(threads[1],0);
pthread_join(threads[2],0);
pthread_join(threads[3],0);

return 0;
}
