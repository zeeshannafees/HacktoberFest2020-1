#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MSGSZ 128

typedef struct msgbuf {
	long mtype;
	char mtext[MSGSZ];
} message_buf;

main()
{
	int msqid;
	int msgflg = IPC_CREAT | 0666;
	key_t key;
	message_buf sbuf,rbuf;
	size_t buf_length;
	key = 5050;
	if ((msqid = msgget(key, msgflg )) < 0) {
		perror("msgget");
		exit(1);
	}
	FILE *fp = fopen("logarghya.txt","w");
	while(1){
		time_t rawtime;
		struct tm *timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);

		sbuf.mtype = 1;
		printf("\nSend message: ");
		gets(&sbuf.mtext);
		if(strcmp(sbuf.mtext,"*")==0){
			strcpy(sbuf.mtext,"\nOther user is offline");
			buf_length = strlen(sbuf.mtext) + 1 ;
			if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
				printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
				perror("msgsnd");
				exit(1);
			}
			printf("\nExiting...");
			fprintf (fp, "\nExiting...");
			break;
		}
		strcat(sbuf.mtext,"    ");
		strcat(sbuf.mtext,asctime(timeinfo));
		buf_length = strlen(sbuf.mtext) + 1 ;
		if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
			printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext,asctime(timeinfo), buf_length);
			perror("msgsnd");
			exit(1);
		}else{
			printf("\nArghya: %s", sbuf.mtext);
			fprintf (fp, "\nArghya: %s", sbuf.mtext);
		}
		if (msgrcv(msqid, &rbuf, MSGSZ, 2, 0) < 0) {
			perror("msgrcv");
			exit(1);
		}else{
			printf("\nFriend:%s", rbuf.mtext);
			fprintf (fp, "\nFriend: %s", rbuf.mtext);
		}	
	}
	fclose(fp);	
	exit(0);
}
