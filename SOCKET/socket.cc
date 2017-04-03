#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#include "socket.h"

using namespace std;

namespace util {

int Server :: Serverstart() {
  int rc = 0;

  int s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    rc = -errno;
    cout << rc << ": Server soccket failed" << endl;
    return rc;
  }
  struct sockaddr_in saddr;
  memset (&saddr, 0, sizeof (saddr));

  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  saddr.sin_port = htons(5242);

  rc = bind(s, (struct sockaddr *) &saddr, sizeof(saddr));
  if (rc < 0) {
    rc = -errno;
    cout << "Error in binding" << endl;
    return rc;
  }

  if(listen(s, 5)==0)
    cout << "Listening..." << endl;
  else
    cout << "Error" << endl;

  int addrlen = sizeof (saddr); 
  int sfd_ = accept(s, (struct sockaddr*) &saddr,(socklen_t*) &addrlen);
  if (sfd_ < 0) {
    rc = -errno;
    cout << rc << ": error in accept" << endl;
    return rc;
  }

  char buffer[1024];
  bzero(buffer, 1024);
  int n = read(sfd_, buffer, 1024);
  if (n < 0) {
    rc = -errno;
    cout << rc << ": read() failed" << endl;
    return rc;
  }

  cout << "message: " << buffer; 

  n = write(sfd_, buffer, 1024);
  if (n < 0) {
    rc = -errno;
    cout << rc << ": write() failed" << endl;
    return rc;
  }
  
  close(s);
  return 0;
};  // end of serverstart

int Client :: Clientstart() {
  int rc = 0;
  sfd_ = socket(PF_INET, SOCK_STREAM, 0);
   if (sfd_ < 0) {
    rc = -errno;
    cout << rc << ": Client socket failed" << endl;
    return rc;
  }
  struct sockaddr_in saddr;
  memset (&saddr, 0, sizeof (saddr));

  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  saddr.sin_port = htons(5242);

/**
 * ---- Connect the socket to the server using the address struct ----
 **/
  int addr_size = sizeof (saddr);
  rc = connect(sfd_, (struct sockaddr *)&saddr, addr_size);
  if(rc < 0) {
     rc = -errno;
     cout << rc << ": Client connect failed" << endl;
     return rc;
  }
};

int Client :: Send (string message) {
  int rc = send(sfd_, message.c_str(), message.length(),0);
  if (rc < 0) {
    rc = -errno;
    cout << rc << ": error in write " << endl;
  }
}

  int Client::Recv(string message) {
  char buffer[1024];

  int rc = recv(sfd_, buffer, sizeof(buffer),0);
  if (rc < 0) {
   rc = -errno;
   cout << rc << ": error in read " << endl;
  }
  cout << "Message :" << buffer << endl;
}

}


