#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//dup2(),read(),write(),close()
#include <fcntl.h>
#include <sys/stat.h>//struct stat
#include <sys/wait.h>//wait()

#include <netinet/in.h>//struct in_addr,htonl(),ntohl(),struct sockaddr_in
#include <arpa/inet.h>//inet_aton(), inet_ntoa()

#include <netdb.h> //struct hostent,gethostbyname(),gethostbyaddr()

#include <sys/socket.h>//socket(), connect(),bind(),listen(),accept()
