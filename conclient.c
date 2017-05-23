#include <stdlib.h>     // Standard Definitions Library
#include <stdio.h>      // For Standard I/O Operations like puts, gets
#include <sys/types.h>  // For Various Data types
#include <sys/socket.h> // For Various Socket Functions soc
#include <netinet/in.h> // For Various Sockaddr_in6 structures like struct in6_ad
#include <string.h>     // For various string operations
#include <arpa/inet.h>  // Definitions for Internet Operations 

//Constant Definitions
#define MAXLINE 4096    //Maximum text line length
#define SERV_PORT 3000  //Port number to communicate

int main(int argc, char **argv) 
{
 int sockfd;            // Socket Descriptor Function
 struct sockaddr_in servaddr; //IP Socket Address with 16 Bit Port Number 
 char sendline[MAXLINE], recvline[MAXLINE]; // Maximum String line for messages.
	
 //basic check of the arguments
 //additional checks can be inserted
 if (argc !=2) {
  perror("Usage: TCPClient <IP address of the server"); 
  exit(1);
 }
	
 //Create a socket for the client
 //If sockfd<0 there was an error in the creation of the socket
 if ((sockfd = socket (AF_INET, SOCK_STREAM, 0)) <0) {
  perror("Problem in creating the socket");
  exit(2);
 }
	
 //Creation of the socket
 memset(&servaddr, 0, sizeof(servaddr));
 servaddr.sin_family = AF_INET; //Ipv4 Address Protocol Address Family
 servaddr.sin_addr.s_addr= inet_addr(argv[1]); // IPv4 Server Address 
 servaddr.sin_port =  htons(SERV_PORT); //convert to big-endian order
	
 //Connection of the client to the socket 
 if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr))<0) { 
  perror("Problem in connecting to the server");
  exit(3);
 }
	
 while (fgets(sendline, MAXLINE, stdin) != NULL) { //Given Condition is Checked if not equal to Null
	
  send(sockfd, sendline, strlen(sendline), 0); // Send the Entered Message by the user
		
  if (recv(sockfd, recvline, MAXLINE,0) == 0){ // If Value is equal to Zero Then there is no connection.
   //error: server terminated prematurely
   perror("The server terminated prematurely"); 
   exit(4);
  }
  printf("%s", "String received from the server: "); //Prints the Recieved Message from the server 
  fputs(recvline, stdout); //Saves the Message entered by the user.
 }

 exit(0);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
