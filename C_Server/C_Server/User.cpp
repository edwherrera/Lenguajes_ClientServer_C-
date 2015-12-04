//
//  User.cpp
//  C_Server
//
//  Created by Edwin Herrera on 03/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#include "User.hpp"

User::User(string uname, string name, string email, string fecha, string cedula, string img){
    Username = uname;
    Name = name;
    Email = email;
    Fecha = fecha;
    Cedula = cedula;
    Img = img;
}