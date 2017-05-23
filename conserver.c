#include <stdlib.h>     // Standard Definitions Library 
#include <stdio.h>      // For Standard Input/Output Operations
#include <sys/types.h>  // For Various Data types
#include <sys/socket.h> // For Various Socket Functions socket()
#include <netinet/in.h> // For Various Sockaddr_in6 structures like struct in6_addr
#include <string.h>     // FOr various string operations
#include <unistd.h>     // For fork() Function 

//Constant Definitions
#define MAXLINE 4096   /* max text line length*/
#define SERV_PORT 3000 /* port number to communicate*/
#define LISTENQ 8      /* maximum number of client connections*/

int main (int argc, char **argv)
{
 int listenfd, connfd, n; // Socket Descriptor Function
 pid_t childpid;          // Child Process ID 
 socklen_t clilen;        
 char buf[MAXLINE];       // String Message Buffer 
 struct sockaddr_in cliaddr, servaddr;

 //Create a socket for the solet
 //If sockfd<0 there was an error in the creation of the socket
 if ((listenfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {
  perror("Problem in creating the socket");
  exit(2);
 }


 //preparation of the socket address
 servaddr.sin_family = AF_INET;// Returns IP Address Family
 servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // IP Address 
 servaddr.sin_port = htons(SERV_PORT);// Port Number
 
 //bind the socket 
 bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)); 

 //listen to the socket by creating a connection queue, then wait for clients
 listen (listenfd, LISTENQ);

 printf("%s\n","Server running...waiting for connections."); // Listen

 for ( ; ; ) {

  clilen = sizeof(cliaddr);

  //accept a connection
  connfd = accept (listenfd, (struct sockaddr *) &cliaddr, &clilen);

  printf("%s\n","Received request...");

  // fork() Which takes care of concurrent Client Connection

  if ( (childpid = fork ()) == 0 ) {//if it’s 0, it’s child process
    //Each child process handles Client Connection Request

    //If Client is connected 
    printf ("%s\n","Child created for dealing with client requests");

    //close listening socket
    close (listenfd);

    while ( (n = recv(connfd, buf, MAXLINE,0)) > 0)  { // until the condition satisfies 
     printf("%s","String received from and resent to the client:");
     puts(buf);//Saves the user's message or text
     send(connfd, buf, n, 0); // initiate transmission of a message from the specified socket to its peer.
    }

    if (n < 0) // If there is no message throw error.
      printf("%s\n", "Read error");
    exit(0);
  }
  
  //close socket of the server
  close(connfd);
 }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* For my reference 

Function arguments

send (int socket, const void *buffer, size_t length, int flags);
socket () - creates socket
htonl() - converts the unsigned integer hostlong from host byte order to network byte order
htnos - converts the unsigned short integer hostshort from host byte order to network byte order.

  /*