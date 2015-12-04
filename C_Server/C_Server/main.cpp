/* The port number is passed as an argument */
#include <iostream>
#include <stdio.h>

#include "Server.hpp"
#include "DBManager.hpp"

void AgregarUsuario(Server server){
    std::string questions[] = {"Username ", "Name ", "Email ", "Fecha de Nacimiento ", "Cedula ", "Imagen "};
    std::string answers[] = {"","","","","",""};
    DBManager db_m;
    
    int count = 0;
    while (count < 6) {
        server.Send(questions[count].c_str());
        server.Read();
        answers[count] = server.buffer;
        if (count == 0 && db_m.UserExists("username", server.buffer)) {
            count--;
        }
        else if (count == 2 && db_m.UserExists("email", server.buffer)){
            count--;
        }
        else if (count == 4 && db_m.UserExists("cedula", server.buffer)){
            count--;
        }
        
        count++;
    }
    
    db_m.AgregarUsuario(answers[0], answers[1], answers[2], answers[3], answers[4], answers[5]);
}

void RemoverUsuario(Server server){
    server.Send("Username ");
    server.Read();
    
    DBManager db_m;
    db_m.RemoverUsuario(server.buffer);
}

void UserInfo(Server server){
    server.Send("Username ");
    server.Read();
    
    DBManager db_m;
    std::string res = db_m.UserInfo(server.buffer);
    server.Send(res.c_str());
    //std::cout << db_m.Found << std::endl;
}

int main(int argc, char *argv[])
{
    Server server;
    
    while (true) {
        server.AcceptSock();

        while (1) {
            
            server.Send("Opcion:\n1.Agregar\n2.Remover\n3.Informacion\n4.Correo\n5.Salir\n");
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
                std::cout << "User Info" << std::endl;
                UserInfo(server);
            }
            else if (strcmp(server.buffer, "4") == 0){
                std::cout << "Send Mail" << std::endl;
            }
            else if (strcmp(server.buffer, "5") == 0){
                std::cout << "Client Exit" << std::endl;
                server.Close();
                break;
            }
            else{
                std::cout << "Not Valid" << std::endl;
            }
        }
    }

    
    return 0;
    
}
