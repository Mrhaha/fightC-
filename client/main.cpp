#include "../CppProto/client.pb.h"
#include <cerrno>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

const int SERVPORT = 8000;
const int BUFFERSIZE = 4096;

int main()
{
    login s;
    s.set_id(233);
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sockfd < 0) {
        perror("socket");
    }
    struct sockaddr_in servaddr,clieaddr;
    memset(&servaddr,0,sizeof(servaddr));
    memset(&clieaddr,0,sizeof(clieaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("139.196.15.229");
    servaddr.sin_port = htons(SERVPORT);
    int addr_len = sizeof(struct sockaddr_in);
    int n = sendto(sockfd,s.SerializeAsString().c_str(),100,0,(struct sockaddr*)&servaddr,addr_len);
    if (n == -1) {
        std::cout << errno << "error:" << strerror(errno)<< std::endl;
    }
    std::cout << "send: " << n << "bytes" << std::endl;
    return 0;



}





