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
using namespace util;
using namespace std;

int main() {
  Client C("127.0.0.1", 5242);
  C.Clientstart();
  string message = "Hello";
  C.Send(message);
  C.Recv(message);
}
