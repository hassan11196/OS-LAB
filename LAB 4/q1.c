#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
pid_t pid;
pid = fork();
if (pid < 0){
	printf("Unsuccessful Child Process Creation.");
	exit(1);
}
else if(pid == 0){
	printf("\nPID is %d",getpid());
	printf("\nParent id : %d",getppid());
	printf("\n");
	for (int i = 1; i < 10; i=i+2){
		printf("\n%d",i);
	}
	printf("\nChild Ends");
}
else {
	wait(NULL);
	sleep(10);
	for (int i = 2; i <= 10; i+=2){
		printf("\n%d",i);
	}
	printf("\nParent Ends");
}

return 0;
}


