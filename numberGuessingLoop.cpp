// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 11, 2022
// This program allows a user to guess a number between
// 0 and 9 when the initial number is randomly generated until
// they get it right
#include <iostream>
#include <iomanip>
#include <random>


int main() {
  // Generate random number
  int randomNumber;

  std::random_device rseed;

  std::mt19937 rgen(rseed());  // mersenne_twister

  std::uniform_int_distribution<int> idist(0, 9);

  randomNumber = idist(rgen);

  // get input from user
  std::string userNum;
  int userNumInt;
  std::cout << "I have picked a number between 0 and 9!\n";
  std::cout << "Guess my number!.\n";
  std::cout << " \n";

  // Loop that asks user to enter guesses until they are right
  do {
      // Make sure user input is an integer
      std::cout << "Enter your guess: ";
      std::cin >> userNum;
      try {
          userNumInt = std::stoi(userNum);

            // Makes sure that user number is positive
          if (userNumInt >= 0) {
            // Evaluate acceptable integer
            if (userNumInt == randomNumber) {
                std::cout << "You guessed correctly!.\n";
                break;
            } else {
                std::cout << "Sorry that is incorrect. Try again!\n";
                std::cout << " \n";
            }
          } else {
              std::cout << userNumInt << " is not a positive number.\n";
          }
          } catch (std::invalid_argument) {
              // Prevent crash by displaying error message if user
              // input is not an integer
              std::cout << userNum << " is not a number\n";
          }
  } while (userNumInt != randomNumber);
}
