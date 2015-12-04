//
//  DBManager.hpp
//  C_Server
//
//  Created by Edwin Herrera on 03/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#ifndef DBManager_hpp
#define DBManager_hpp

#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

class DBManager{

private:
    const char* db_name;
    sqlite3 *db;
    void CrearTabla();
    static int Callback(void *NotUsed, int argc, char **argv, char **azColName);
    
public:
    DBManager();
    ~DBManager();
    
    static bool Found;
        
    void AgregarUsuario(std::string, std::string, std::string, std::string, std::string, std::string);
    void RemoverUsuario(std::string);
    std::string UserInfo(std::string);
    bool UserExists(std::string, std::string);
};

#endif /* DBManager_hpp */
