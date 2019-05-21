#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
static int test = 0
void* table_print(int num){
	pthread_id_np_t tid;
	tid=pthread_getthreadid_np();
	printf("\nTable of %d ", num);
	int i = 0;
	for(i = 0; i < 1000; i++){
		printf("\nK17-3654 EThread id %d : %d * %d = %d ",tid,i + 1, num , (i+1) * num);
	}
}
int main()
{
	int status;
	pthread_t tid[4];
	int nums[4] = {5,6,7,8};
	int i = 0;
	for(i = 0; i < 4; i++){
		pthread_create(&tid[i],NULL,table_print,(void*)nums[i]);
	
	}
	for(i = 0; i < 4; i++){
		pthread_join(tid[i],NULL);
	}


	return 0;

}


