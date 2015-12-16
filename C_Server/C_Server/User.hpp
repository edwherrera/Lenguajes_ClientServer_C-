//
//  User.hpp
//  C_Server
//
//  Created by Edwin Herrera on 03/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

class User{
    
public:
    string Username;
    string Name;
    string Email;
    string Cedula;
    string Fecha;
    string Img;
    User(string, string, string, string, string, string);
    ~User();
};



#endif /* User_hpp */
