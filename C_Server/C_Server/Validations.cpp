//
//  Validations.cpp
//  C_Server
//
//  Created by Edwin Herrera on 06/12/15.
//  Copyright © 2015 Doninelli. All rights reserved.
//

#include "Validations.hpp"

bool Validations::CheckEmail(std::string email){
    return regex_match(email,std::regex("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}"));
}

bool Validations::CheckDate(std::string date){
    return std::regex_match (date, std::regex("\\d{2}-\\d{2}-\\d{4}"));
}

bool Validations::CheckCedula(std::string cedula){
    return std::regex_match (cedula, std::regex("\\d{4}-\\d{4}-\\d{5}"));
}