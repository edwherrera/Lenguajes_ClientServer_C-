//
//  Server.hpp
//  C_Server
//
//  Created by Edwin Herrera on 03/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#ifndef Server_hpp
#define Server_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


class Server{
    
public:
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    Server();
    ~Server();
    
    void AcceptSock();
    void Send(const char*);
    void Read();
    void Close();
    
private:
    
    void error(const char*);
    
};

#endif /* Server_hpp */