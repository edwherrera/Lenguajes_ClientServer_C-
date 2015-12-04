//
//  DBManager.cpp
//  C_Server
//
//  Created by Edwin Herrera on 03/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#include "DBManager.hpp"

DBManager::DBManager(){
    
    db_name = "Users.db";
    _selectResult = "";
}

DBManager::~DBManager(){
    
    
}

void DBManager::AgregarUsuario(std::string uname, std::string name, std::string email, std::string fecha, std::string cedula, std::string img){
    int rc = sqlite3_open(db_name, &db);
    char *zErrMsg = 0;

    if(!rc){
        CrearTabla();
        std::string sql = "INSERT INTO USERS(username, name, email, fnac, cedula, imgUrl) values('" + uname + "','"+name+"','"+email+"','"+fecha+"','"+cedula+"','"+img+"');";
        sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);
    }
    
    sqlite3_close(db);
    
}

void DBManager::CrearTabla(){
    char *zErrMsg = 0;

    std::string sql = "CREATE TABLE IF NOT EXISTS Users(username varchar(100), name varchar(100), email varchar(100), fnac varchar(20), cedula varchar(20),imgUrl varchar(100))";
    sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

}

void DBManager::RemoverUsuario(std::string username){
    int rc = sqlite3_open(db_name, &db);
    char *zErrMsg = 0;
    
    if(!rc){
        CrearTabla();
        std::string sql = "DELETE FROM users WHERE username = '"+username+"';";
        sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);
    }
    
    sqlite3_close(db);
}

void DBManager::UserInfo(std::string username){
    int rc = sqlite3_open(db_name, &db);
    char *zErrMsg = 0;
    
    if(!rc){
        CrearTabla();
        std::string sql = "SELECT * FROM USERS;";
        sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);
    }
    
    sqlite3_close(db);

}

int DBManager::Callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}