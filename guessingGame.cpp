// Copyright (c) 2022 Michael Clermont All rights reserved
//
// Created by: Michael Clermont
// Created on: Feb 2022
// This program is a guessing game

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function is a guessing game
    std::string numberAsString;
    int numberFromUser;
    int randomNumber;
    int loopCounter = 0;

    // input
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    randomNumber = idist(rgen);

    // process & output
    while (true) {
        std::cout << "Enter a number between 0-9: ";
        std::cin >> numberAsString;
        try {
            numberFromUser = std::stoi(numberAsString);
            loopCounter = loopCounter + 1;
            if (numberFromUser == randomNumber) {
                std::cout << "\nYou guessed correctly in " << loopCounter <<
                " times!" << std::endl;
                break;
            } else if (randomNumber > numberFromUser) {
                std::cout << "\nNext time guess higher!" << std::endl;
            } else if (randomNumber < numberFromUser) {
                std::cout << "\nNext time guess lower!" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "That is not an integer, guess again" << std::endl;
        }
    }
    std::cout << "\nDone." << std::endl;
}
