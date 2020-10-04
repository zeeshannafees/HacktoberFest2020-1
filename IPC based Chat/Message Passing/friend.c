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
	key_t key;
	message_buf  rbuf,sbuf;
	size_t buf_length;
	key = 5050;
	if ((msqid = msgget(key, 0666)) < 0) {
		perror("msgget");
		exit(1);
	}
	FILE *fp = fopen ("logfriend.txt","w");
	while(1){
		time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);

		if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
			perror("msgrcv");
			exit(1);
		}else{
			printf("\nArghya: %s", rbuf.mtext);
			fprintf (fp, "\nArghya: %s", rbuf.mtext);
		}
			
		sbuf.mtype = 2;
		printf("\nSend message: ");
		gets(&sbuf.mtext);
		if(strcmp(sbuf.mtext,"*")==0){
			strcpy(sbuf.mtext,"Other user is offline");
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
			printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext,buf_length);
			perror("msgsnd");
			exit(1);
		}else{
			printf("\nFriend: %s", sbuf.mtext);
			fprintf (fp, "\nFriend: %s", sbuf.mtext);
		}
	}
	exit(0);
}
