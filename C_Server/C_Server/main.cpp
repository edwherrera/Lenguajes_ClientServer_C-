/* The port number is passed as an argument */
#include <iostream>
#include <stdio.h>

#include "Server.hpp"
#include "DBManager.hpp"

void AgregarUsuario(Server server){
    std::string questions[] = {"Username ", "Name ", "Email ", "Fecha de Nacimiento ", "Cedula ", "Imagen "};
    std::string answers[] = {"","","","","",""};
    
    int count = 0;
    while (count < 6) {
        server.Send(questions[count].c_str());
        server.Read();
        answers[count++] = server.buffer;
    }
    
    DBManager db_m;
    db_m.AgregarUsuario(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5]);
}

void RemoverUsuario(Server server){
    server.Send("Username ");
    server.Read();
    
    DBManager db_m;
    db_m.RemoverUsuario(server.buffer);
}

int main(int argc, char *argv[])
{
    Server server;
    
    while (1) {
        
        server.AcceptSock();
        server.Send("Opcion: ");
        server.Read();
        if (strcmp(server.buffer, "1") == 0) {
            std::cout << "Agregar" << std::endl;
            AgregarUsuario(server);
        }
        else if (strcmp(server.buffer, "2") == 0) {
            std::cout << "Remove" << std::endl;
            RemoverUsuario(server);
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
