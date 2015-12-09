//
//  Server.cpp
//  C_Server
//
//  Created by Edwin Herrera on 03/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#include "Server.hpp"

Server::Server(){
    sockfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    
    portno = 1050;
    
    serv_addr.sin_family = AF_INET;
    
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    

    listen(sockfd,5);
    
    clilen = sizeof(cli_addr);
}

Server::~Server(){
    
}

void Server::AcceptSock(){
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");
}

void Server::Send(const char *msg){
    send(newsockfd, msg, strlen(msg), 0);
}

void Server::Read(){
    bzero(buffer, 256);
    read(newsockfd, buffer, 255);
    strtok(buffer, "\n");
}

void Server::Close(){
    close(newsockfd);
}

void Server::error(const char *msg)
{
    perror(msg);
    exit(1);
}