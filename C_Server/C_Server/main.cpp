/* The port number is passed as an argument */
#include <iostream>
#include <stdio.h>

#include "Server.hpp"
#include "DBManager.hpp"

int main(int argc, char *argv[])
{
    Server server;
    
    while (1) {
        
        server.AcceptSock();
        server.Send("Opcion: ");
        server.Read();
        if (strcmp(server.buffer, "1") == 0) {
            std::cout << "Agregar" << std::endl;
            DBManager b;
            b.AgregarUsuario("A", "B", "C", "D", "E", "F");
        }
        else if (strcmp(server.buffer, "2") == 0) {
            std::cout << "Remove" << std::endl;
        }
        else if (strcmp(server.buffer, "3") == 0) {
            std::cout << "Info" << std::endl;
            DBManager b;
            b.UserInfo("A");
        }
        else{
            std::cout << "Not Valid" << std::endl;
        }
        server.Close();
    }
    return 0;
    
}
