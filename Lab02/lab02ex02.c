#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
int main ()
{
	char *p;
	int shmID = shmget(8765, 30*sizeof(char), IPC_CREAT | S_IRUSR | S_IWUSR);

	if(shmID==-1)
	{
		printf("Fudeu\n");
		return 1;
	}

	p = shmat(shmID, 0, 0);

	scanf("%[^\n]", p);

	shmdt(p);

	return 0;
}