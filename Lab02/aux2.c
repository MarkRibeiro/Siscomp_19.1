#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main ()
{
	int shmID;
	int *v;
	int i, j, k;
	int status;

	shmID = shmget(8765, 30 * sizeof(int), S_IRUSR);

	v = shmat (shmID, 0, 0);

	if(fork()!=0)
	{
		for(i=0;i<10;i++)
		{
			if(v[i]==27)
			{
				printf("Achei no pai\n");
			}
		}
		waitpid(-1, &status, 0);
	}

	else
	{
		if(fork()!=0)
		{
			for(j=10;j<20;j++)
			{
				if(v[j]==27)
				{
					printf("Achei no filho\n");
				}
			}
			waitpid(-1, &status, 0);
		}

		else
		{
			for(k=20;k<29;k++)
			{
				if(v[k]==27)
				{
					printf("Achei no neto\n");
				}
			}
		}
	}

    shmdt(v);
    shmctl(shmID, IPC_RMID, 0);

    return 0;
}