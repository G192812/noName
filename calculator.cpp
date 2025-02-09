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




int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}

int main() {
	int a, b;
	char op;
	std::cout << "Enter the first number: ";
	std::cin >> a;
	std::cout << "Enter the operator: ";
	std::cin >> op;
	std::cout << "Enter the second number: ";
	std::cin >> b;
	if (op == '+') {
		std::cout << add(a, b) << std::endl;
	}
	else if (op == '-') {
		std::cout << subtract(a, b) << std::endl;
	}
	else if (op == '*') {
		std::cout << multiply(a, b) << std::endl;
	}
	else if (op == '/') {
		std::cout << divide(a, b) << std::endl;
	}
	else {
		std::cout << "Invalid operator" << std::endl;
	}
	return 0;
}
