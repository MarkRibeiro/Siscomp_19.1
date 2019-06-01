#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
int main ()
{
	int i, j, k;
	int status;

	if(fork()!=0)
	{
		for(i=0;i<=9;i++)
		{
			printf("pid:%d pid pai:%d i:%d\n", getpid(), getppid(), i);
			sleep(1);
		}
		waitpid(-1, &status, 0);	
		printf("Porcesso pai vai finalizar\n");
	}

	else
	{
		if(fork()!=0)
		{
			printf("Filho foi criado\n");
			for(j=10;j<=19;j++)
			{
				printf("pid:%d pid pai:%d j:%d\n", getpid(), getppid(), j);
				sleep(2);
			}
			waitpid(-1, &status, 0);
			printf("Porcesso filho vai finalizar\n");
		}

		else
		{
			printf("Neto foi criado\n");
			for(k=20;k<=29;k++)
			{
				printf("pid:%d pid pai:%d k:%d\n", getpid(), getppid(), k);
				sleep(3);
			}
			printf("Porcesso neto vai finalizar\n");
		}
	}
}