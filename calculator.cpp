//              _         _                                     _               
//       /\    | |       | |                                   (_)              
//      /  \   | | _ __  | |__    __ _  __   __ ___  _ __  ___  _   ___   _ __  
//     / /\ \  | || '_ \ | '_ \  / _` | \ \ / // _ \| '__|/ __|| | / _ \ | '_ \ 
//    / ____ \ | || |_) || | | || (_| |  \ V /|  __/| |   \__ \| || (_) || | | |
//   /_/    \_\|_|| .__/ |_| |_| \__,_|   \_/  \___||_|   |___/|_| \___/ |_| |_|
//                | |                                                           
//                |_|                                                           


//tecnique used in this code: separating the calculator into separate functions, arguments, parameters, and using the return value of the function to determine the mode of the calculator

//2 . 9 . 2025



#include <iostream>
#include <cmath>



int selectingCalcMode()
{
    int mode;
    std::cout << "mode lists : " << '\n';
    std::cout << "1. Addition" << '\n';
    std::cout << "2. Subtraction" << '\n';
    std::cout << "3. Multiplication" << '\n';
    std::cout << "4. Division" << '\n';
    std::cout << "5. Modulus" << '\n';
    std::cout << "Please enter the mode you want to use: ";
    std::cin >> mode;
    if (mode == 1) {
        return 1;
    }
    else if (mode == 2) {
        return 2;
    }
    else if (mode == 3) {
        return 3;
    }
    else if (mode == 4) {
        return 4;
    }
    else if (mode == 5) {
        return 5;
    }
    else {
        return 0;
    }
}

void additionTwoOperands(float a, float b) {
    std::cout << "The sum of " << a << " and " << b << " is " << a + b << std::endl;
}

void subtractionTwoOperands(float a, float b) {
    std::cout << "The subtraction of " << a << " and " << b << " is " << a - b << std::endl;
}

void multiplicationTwoOperands(float a, float b) {
    std::cout << "The multiplication of " << a << " and " << b << " is " << a * b << std::endl;
}

void divisionTwoOperands(float a, float b) {
    std::cout << "The division of " << a << " and " << b << " is " << a / b << std::endl;
}

void modulusTwoOperands(float a, float b) {
    std::cout << "The modulus of " << a << " and " << b << " is " << fmod(a, b) << std::endl;
}

int main()
{
    int selectedMode{ selectingCalcMode() };
    if (selectedMode == 1) {
        float a, b;
        std::cout << "Please enter the first number: ";
        std::cin >> a;
        std::cout << "Please enter the second number: ";
        std::cin >> b;
        additionTwoOperands(a, b);
    }
    else if (selectedMode == 2) {
        float a, b;
        std::cout << "Please enter the first number: ";
        std::cin >> a;
        std::cout << "Please enter the second number: ";
        std::cin >> b;
        subtractionTwoOperands(a, b);
    }
    else if (selectedMode == 3) {
        float a, b;
        std::cout << "Please enter the first number: ";
        std::cin >> a;
        std::cout << "Please enter the second number: ";
        std::cin >> b;
        multiplicationTwoOperands(a, b);
    }
    else if (selectedMode == 4) {
        float a, b;
        std::cout << "Please enter the first number: ";
        std::cin >> a;
        std::cout << "Please enter the second number: ";
        std::cin >> b;
        divisionTwoOperands(a, b);
    }
    else if (selectedMode == 5) {
        float a, b;
        std::cout << "Please enter the first number: ";
        std::cin >> a;
        std::cout << "Please enter the second number: ";
        std::cin >> b;
        modulusTwoOperands(a, b);
    }
}

