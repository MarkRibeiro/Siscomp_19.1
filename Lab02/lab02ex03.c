#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main ()
{
	int shmID;
	int *v;
	int i;

	shmID = shmget(8765, 30*sizeof(int), IPC_CREAT | S_IRUSR | S_IWUSR);

	if(shmID==-1)
	{
		printf("Fudeu\n");
		return 1;
	}

	v = shmat(shmID, 0, 0);

	for(i=0;i<30;i++)
	{
		v[i] = i;
	}

	shmdt(v);

	return 0;

}