#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
int main ()
{
	char *p;
	int shmID = shmget(8765, 30*sizeof(char), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

	p = shmat(shmID, 0, 0);
	p = "oiiii";

	shmdt(p);
	return 0;
}