#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>

int icecreamremaining;
sem_t counting_money;
sem_t num_icecreams;

int customer_comes(int num){
	int wait_time = 2;
	printf("\n%d\n",icecreamremaining);
	while(icecreamremaining > 0){
		printf("Customer Arrives at IceCream Shop.\n");
		printf("Second Customer Counts Money.\n");
		sleep(wait_time);
		sem_wait(&counting_money);
		printf("Customer gets served one ice cream.");
		//sem_wait(&icecreamremaining);
		icecreamremaining--;
		sem_post(&num_icecreams);
		sem_post(&counting_money);

		printf("Customer Leaves.");
	}
	

	return num;
}


int main(){
	int cust[3] = {0,1,2};
	pthread_t cust_threads[3];
	int num;
	printf("Enter Number of Available Ice creams : ");
	scanf("%d",&num);

	sem_init(&icecreamremaining,0,num);
	sem_init(&num_icecreams,0,1);
	sem_init(&counting_money,0,1);
	for(int i = 0; i < 3; i++){
		pthread_create(&cust_threads[i],NULL,&customer_comes,(void*)cust[i]);
		pthread_join(cust_threads[i],NULL);
	}

	

	return 0;
}
