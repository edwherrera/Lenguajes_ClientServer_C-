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
    
    // clear address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    
    portno = 1060;
    
    /* setup the host_addr structure for use in bind call */
    // server byte order
    serv_addr.sin_family = AF_INET;
    
    // automatically be filled with current host's IP address
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    // convert short integer value for port must be converted into network byte order
    serv_addr.sin_port = htons(portno);
    
    // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
    // bind() passes file descriptor, the address structure,
    // and the length of the address structure
    // This bind() call will bind  the socket to the current IP address on port, portno
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    
    // This listen() call tells the socket to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection.
    // Here, we set the maximum size for the backlog queue to 5.
    listen(sockfd,5);
    
    // The accept() call actually accepts an incoming connection
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