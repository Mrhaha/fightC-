#include "../CppProto/client.pb.h"
#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstring>
#include <iostream>

const int SERPORT = 8000;
const int MAXSIZE = 4096;


int main()
{
    login lo;
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in servaddr,clieaddr;
    memset(&servaddr,0,sizeof(servaddr));
    memset(&servaddr,0,sizeof(clieaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERPORT);

    bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    char msg[MAXSIZE];
    socklen_t len;
    int n = recvfrom(sockfd,msg,MAXSIZE,0,(struct sockaddr *)&clieaddr,&len);
    std::cout << "total:" << n << std::endl;
    lo.ParseFromArray(msg,sizeof(login));  
    std::cout <<"login id:" << lo.id() << std::endl;
    return 0;
}

