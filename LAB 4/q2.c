#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
int cnt = 0;
pid_t pid;
pid = fork();

	for (int i = 1; i <= 5; i++){
		printf("\nCnt = %d",cnt);
		cnt+=1;
	}

if (pid < 0){
	printf("Unsuccessful Child Process Creation.");
	exit(1);
}
else if(pid == 0){
	printf("\nPID is %d",getpid());
	printf("\nParent id : %d",getppid());
	printf("\n Child goes to sleep");
	sleep(3);
	printf("\nChild Ends");
}
else {
	printf("\n Parent waits");
	wait(NULL);
	printf("\nParent Ends");
	printf("\n Invoking Gedit");
	execl("/usr/bin/gedit","gedit",(char*)0);
	perror("execl");
}

return 0;
}


