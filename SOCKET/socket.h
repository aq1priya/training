#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

using namespace std;

namespace util {

class Socket {
  public:
    Socket(string ipAddr, int port) { ipAddr_ = ipAddr; port_ = port; }

  protected:
    int sfd_;
    int port_;
    string ipAddr_;
};

class Server : public Socket {
  public:
    Server(string ipAddr, int port): Socket (ipAddr, port) { }
    int Serverstart();
};

class Client : public Socket {
  public: 
    Client(string ipAddr, int port): Socket (ipAddr, port) { }
    int Clientstart();
    int Send(string message);
    int Recv(string message);
};

} //end of namespace util
