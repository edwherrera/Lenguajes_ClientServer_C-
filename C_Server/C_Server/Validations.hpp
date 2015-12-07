//
//  Validations.hpp
//  C_Server
//
//  Created by Edwin Herrera on 06/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#ifndef Validations_hpp
#define Validations_hpp

#include <iostream>
#include <stdio.h>
#include <regex>

class Validations{
    
public:
    
    static bool CheckEmail(std::string);
    static bool CheckDate(std::string);
    static bool CheckCedula(std::string);
    
};

#endif /* Validations_hpp */
