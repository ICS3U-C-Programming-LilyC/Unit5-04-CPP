// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/1/2023
// This program allows for user to
// choose 2 numbers and a mathematical
// sign that will be used in the calculation.
// It will then add/subtract/divide/multiply/modulo
// of your 2 numbers.

#include <cmath>
#include <iostream>
#include<string>

// Function that checks what sign will
// be used in the calculation.
float Calculate(char sign, float firstNumber, float secondNumber) {
    // Declaring variable.
    float answer;

    // Using if, else if and else statements
    // to determine what calculation will be executed.
    if (sign == '+') {
        answer = firstNumber + secondNumber;
    } else if (sign == '-') {
        answer = firstNumber - secondNumber;
    } else if (sign == '*') {
        answer = firstNumber * secondNumber;
    } else if (sign == '/') {
        answer = firstNumber / secondNumber;
    } else if (sign == '%') {
        // Using built in modulo function (fmod)
        answer = fmod(firstNumber, secondNumber);
    }
    return answer;
}

int main() {
    // Declaring variables.
    std::string firstNumber;
    std::string secondNumber;
    float answer;
    char sign;

    // Getting user input for number1.
    std::cout << "Enter your first number as a decimal: ";
    std::cin >> firstNumber;

    // Getting user input for number2.
    std::cout << "Enter your second number as a decimal: ";
    std::cin >> secondNumber;

    // Getting user input for mathematical sign.
    std::cout << "Enter a mathematical sign (+, -, *, /, %): ";
    std::cin >> sign;

    // Using if statement to check
    // if mathematical sign is valid.
    // If it is valid then their numbers
    // will be converted into decimals
    // and error check using a try catch.
    if (sign == '+' || sign == '-' ||
    sign == '*' || sign == '/' || sign == '%') {
        // Using a try catch to catch any errors.
        // Converting number1 and number2 into decimals.
        try {
            // cast the numbers to a float
            float firstNumberAsFloat = std::stof(firstNumber);
            float secondNumberAsFloat = std::stof(secondNumber);

            // call the function
            answer = Calculate(sign, firstNumberAsFloat, secondNumberAsFloat);

            // Displaying the answer to the user.
            std::cout << firstNumberAsFloat << sign
            << secondNumberAsFloat << " = " << answer;
        // Catching any errors.
        } catch (std::invalid_argument) {
            std::cout << "Invalid number.";
        }
    // Using else statement to display an error
    // message when the mathematical sign is invalid.
    } else {
        std::cout << sign << " is an invalid mathematical sign.";
    }
}
