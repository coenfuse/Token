// Token.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Token/Token.h"

int main()
{
    Token test;
    std::cout << test.giveAccess() << std::endl;
    std::cout << test.giveSession() << std::endl;
    std::cout << test.giveLog() << std::endl;
    std::cout << test.giveOTP() << std::endl;
    std::cout << sizeof(test) << std::endl;
}