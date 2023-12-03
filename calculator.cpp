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
#include <iomanip>
#include <iostream>
#include <string>

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
        // Using built-in modulo function (fmod)
        answer = fmod(firstNumber, secondNumber);
    }
    // Returning the value of answer to my main() function.
    return answer;
}

int main() {
    // Declaring variables.
    std::string firstNumberStr;
    std::string secondNumberStr;
    float answer;
    char sign;

    // Getting user input for number1.
    std::cout << "Enter your first number as a decimal: ";
    std::cin >> firstNumberStr;

    // Getting user input for number2.
    std::cout << "Enter your second number as a decimal: ";
    std::cin >> secondNumberStr;

    // Getting user input for mathematical sign.
    std::cout << "Enter a mathematical sign (+, -, *, /, %): ";
    std::cin >> sign;

    // Using if statement to check
    // if the mathematical sign is valid.
    // If it is valid then their numbers
    // will be converted into decimals
    // and error check using a try-catch.
    if (sign == '+' || sign == '-' ||
        sign == '*' || sign == '/' || sign == '%') {
        // Using a try-catch to catch any errors.
        // Converting number1 and number2 into decimals.
        try {
            // Convert the numbers from strings to floats.
            float firstNumber = std::stof(firstNumberStr);
            float secondNumber = std::stof(secondNumberStr);

            // Calling calculator() function.
            answer = Calculate(sign, firstNumber, secondNumber);

            // Displaying the answer to the user with 2 decimal places.
            std::cout << std::fixed << std::setprecision(2)
                      << firstNumber << " " << sign << " "
                      << secondNumber << " = " << answer;
        // Catching any errors.
        } catch (std::invalid_argument) {
            std::cout << "Invalid number.";
        }
        // Using else statement to display an error
        // message when the mathematical sign is invalid.
    } else {
        std::cout << sign << " is an invalid mathematical sign.";
    }

    return 0;
}
