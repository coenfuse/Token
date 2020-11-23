// Token.cpp : This file contains the 'main' function.

#include <iostream>
#include "Token/Token.h"
#include <set>

int main()
{
    std::set<std::string> A, S, O, L;
    Token test;
    
    // Generate Random strings. Can alter the value with as much values user likes.

    for (int i = 0; i < 10; i++) {
        A.insert(test.giveAccess());
        S.insert(test.giveSession());
        O.insert(test.giveOTP());
        L.insert(test.giveLog());
    }

    // Print Random Strings
    std::cout << "\n";
    for (auto each : A)
        std::cout << each << std::endl;
    std::cout << "\n";
    for (auto each : S)
        std::cout << each << std::endl;
    std::cout << "\n";
    for (auto each : O)
        std::cout << each << std::endl;
    std::cout << "\n";
    for (auto each : L)
        std::cout << each << std::endl;

    // Check if the Random Strings are present in the system. Should give output at 1 each.
    std::cout << "\n";
    for (auto each : A)
        std::cout << test.checkAccess(each) << std::endl;
    std::cout << "\n";
    for (auto each : S)
        std::cout << test.checkSession(each) << std::endl;
    std::cout << "\n";
    for (auto each : O)
        std::cout << test.checkOTP(each) << std::endl;
    std::cout << "\n";
    for (auto each : L)
        std::cout << test.checkLog(each) << std::endl;

    // Vacate each of the genrated strings from the object is is contained inside. Here: test. Void function.
    std::cout << "\n";
    for (auto each : A)
        test.vacate(each);
    std::cout << "\n";
    for (auto each : S)
        test.vacate(each);
    std::cout << "\n";
    for (auto each : O)
        test.vacate(each);
    std::cout << "\n";
    for (auto each : L)
        test.vacate(each);

    // Check if the Random Strings are present in the system after removal. Should give output at 0 each.
    std::cout << "\n";
    for (auto each : A)
        std::cout << test.checkAccess(each) << std::endl;
    std::cout << "\n";
    for (auto each : S)
        std::cout << test.checkSession(each) << std::endl;
    std::cout << "\n";
    for (auto each : O)
        std::cout << test.checkOTP(each) << std::endl;
    std::cout << "\n";
    for (auto each : L)
        std::cout << test.checkLog(each) << std::endl;
}