#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* vol(char* str){
	printf("\n Volunteer handling %s",str);
}



int main(){

	int status;
	pthread_t tid[4];
	char* volunteers[4] = {"On-Day Registration","Announcments","Sponsers","Queries of participants"};
	int i = 0;
	for(int i = 0; i < 1000; i++){
		srand(time(NULL));
		int cs = 1 + rand()%4;		
		switch(cs){
			case 1:
				pthread_create(&tid[0],NULL,vol,(void*)volunteers[0]);
			case 2:
				pthread_create(&tid[1],NULL,vol,(void*)volunteers[1]);
			case 3:
				pthread_create(&tid[2],NULL,vol,(void*)volunteers[2]);
			case 4:
				pthread_create(&tid[3],NULL,vol,(void*)volunteers[3]);
		}

	}
		
	return 0;
}
