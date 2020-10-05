#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <time.h>
#define SHMSZ 27

main()
{
    int shmid,i;
    key_t key;
    char *shm, *s;
    key = 4050;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
	*shm = '!';
	FILE *fp = fopen("logarghya2.txt","w");
	while(*shm!='*')
	{	time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);

		char a[100];
		printf("Send message: ");
		gets(a);
		strcat(a,"    ");
		strcat(a,asctime(timeinfo));
		if(a[0]!='*'){
			s = shm+1;
			for (i=0;i<strlen(a);i++)
				 *s++ = a[i];
			*s = NULL;
			*shm = '@';
			while(*shm!='#'&&*shm!='*')
				sleep(1);
			if(*shm!='*'){
				printf("Friend: ");
				//fprintf (fp, "Friend: ");
				for (s = shm+1; *s != NULL; s++)
				{
					putchar(*s);
					//fprintf (fp, *s);
				}
				putchar('\n');
				//fprintf (fp, '\n');
			}else
			printf("Other user is offline");
		}
		else
			*shm = '*';
	}
	shmid = shmdt(shm);
	fclose(fp);
    exit(0);
}
