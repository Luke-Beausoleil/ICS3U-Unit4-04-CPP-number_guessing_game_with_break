// Copyright (c) 2021 Luke Beausoleil All rights reserved
//
// Created by: Luke Beausoleil
// Created on: May 2021
// This program gets the user to guess a pseudo-random number

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function generates a pseudo-random number and gets the user to
    //      guess it

    // variables
    std::string guessAsString;
    int correctNumber;
    int guessAsInteger;

    // generate random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    correctNumber = idist(rgen);

    // process & output
    while (true) {
        std::cout << "Guess a number from 0 - 9: ";  // input
        std::cin >> guessAsString;  // input
        try {
            guessAsInteger = std::stoi(guessAsString);
            if (guessAsInteger == correctNumber) {
                break;
            } else if (guessAsInteger < correctNumber) {
                std::cout << "Too Low! Try Again" << std::endl;
            } else {
                std::cout << "Too High! Try Again" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << guessAsString << " is invalid. Try Again"
                  << std::endl;
        }
    }
    std::cout << "\nCorrect!" << std::endl;
    std::cout << "\nDone." << std::endl;
}
