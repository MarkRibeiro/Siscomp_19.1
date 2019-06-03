#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<string.h>
int main ()
{
	int shmID;
	char *p;

	shmID = shmget(8765, 30 * sizeof(char), S_IRUSR);

	p = (char *) shmat (shmID, 0, 0);

	printf("%s\n", p);
    shmdt(p);
    shmctl(shmID, IPC_RMID, 0);

    return 0;
}