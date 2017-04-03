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

int main() {
  Server S("127.0.0.1", 8080);
  S.Serverstart();
  return 0;
}
