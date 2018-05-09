/* ClockClient.c: simple interactive TCP/IP client for ClockServer
 * Author: Rainer Doemer, 2/16/15
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

/* #define DEBUG */	/* be verbose */

/*** global variables ****************************************************/

const char *Program	/* program name for descriptive diagnostics */
	= NULL;

/*** global functions ****************************************************/

void FatalError(		/* print error diagnostics and abort */
	const char *ErrorMsg)
{
    fputs(Program, stderr);
    fputs(": ", stderr);
    perror(ErrorMsg);
    fputs(Program, stderr);
    fputs(": Exiting!\n", stderr);
    exit(20);
} /* end of FatalError */

int main(int argc, char *argv[])
{
    int l, n;
    int SocketFD,	/* socket file descriptor */
	PortNo;		/* port number */
    struct sockaddr_in
	ServerAddress;	/* server address we connect with */
    struct hostent
	*Server;	/* server host */
    char SendBuf[256];	/* message buffer for sending a message */
    char RecvBuf[256];	/* message buffer for receiving a response */

    Program = argv[0];	/* publish program name (for diagnostics) */
#ifdef DEBUG
    printf("%s: Starting...\n", argv[0]);
#endif
    if (argc < 3)
    {   fprintf(stderr, "Usage: %s hostname port\n", Program);
	exit(10);
    }
    Server = gethostbyname(argv[1]);
    if (Server == NULL)
    {   fprintf(stderr, "%s: no such host named '%s'\n", Program, argv[1]);
        exit(10);
    }
    PortNo = atoi(argv[2]);
    if (PortNo <= 2000)
    {   fprintf(stderr, "%s: invalid port number %d, should be >2000\n",
		Program, PortNo);
        exit(10);
    }
    SocketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (SocketFD < 0)
    {   FatalError("socket creation failed");
    }
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_port = htons(PortNo);
    ServerAddress.sin_addr = *(struct in_addr*)Server->h_addr_list[0];
    printf("%s: Connecting to the server at port %d...\n", Program, PortNo);
    if (connect(SocketFD, (struct sockaddr*)&ServerAddress,
		sizeof(ServerAddress)) < 0)
    {   FatalError("connecting to server failed");
    }
    printf("%s: Enter a command to send to the clock server:\n"
		"         'TIME' to obtain the current time,\n"
		"         'SHUTDOWN' to terminate the server\n"
		"command: ", argv[0]);
    fgets(SendBuf, sizeof(SendBuf), stdin);
    l = strlen(SendBuf);
    if (SendBuf[l-1] == '\n')
    {   SendBuf[--l] = 0;
    }
    if (l)
    {   printf("%s: Sending message '%s'...\n", Program, SendBuf);
	n = write(SocketFD, SendBuf, l);
	if (n < 0)
	{   FatalError("writing to socket failed");
	}
#ifdef DEBUG
	printf("%s: Waiting for response...\n", Program);
#endif
	n = read(SocketFD, RecvBuf, sizeof(RecvBuf)-1);
	if (n < 0) 
	{   FatalError("reading from socket failed");
	}
	RecvBuf[n] = 0;
	printf("%s: Received response: %s\n", Program, RecvBuf);
    }
    printf("%s: Exiting...\n", Program);
    close(SocketFD);
    return 0;
}

/* EOF ClockClient.c */
