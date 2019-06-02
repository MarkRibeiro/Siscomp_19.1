#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<string.h>
int main ()
{
	int shmID;
	char *p, *mensagem;

	shmID = shmget(8765, 30 * sizeof(char), S_IRUSR);

	p = (char *) shmat (shmID, 0, 0);

	strcpy(mensagem, p);
	printf("%s\n", mensagem);
}
/*
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
    int shmID;
    char *p;

    shmID = shmget (8765, 30*(sizeof (char)), S_IRUSR );

    p = (char *) shmat (shmID, 0, 0);
    
    strcpy(mensagem, p);
    printf("Mensagem alocada: %s\n", mensagem);
    
    shmdt (p);
    shmctl (shmID, IPC_RMID, 0);
    return 0;
}
*/