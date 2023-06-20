#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string hexValue;
    std::cout << "Enter a hexadecimal value: ";
    std::cin >> hexValue;

    // Conversion from hexadecimal to binary
    std::string binaryValue;
    for (int i = 0; i < hexValue.length(); i++) {
        char c = hexValue[i];
        switch (c) {
        case '0': binaryValue += "0000"; break;
        case '1': binaryValue += "0001"; break;
        case '2': binaryValue += "0010"; break;
        case '3': binaryValue += "0011"; break;
        case '4': binaryValue += "0100"; break;
        case '5': binaryValue += "0101"; break;
        case '6': binaryValue += "0110"; break;
        case '7': binaryValue += "0111"; break;
        case '8': binaryValue += "1000"; break;
        case '9': binaryValue += "1001"; break;
        case 'A': binaryValue += "1010"; break;
        case 'B': binaryValue += "1011"; break;
        case 'C': binaryValue += "1100"; break;
        case 'D': binaryValue += "1101"; break;
        case 'E': binaryValue += "1110"; break;
        case 'F': binaryValue += "1111"; break;
        default: std::cout << "Invalid hexadecimal value." << std::endl; return 1;
        }
    }

    // Writing binary data to an .exe file
    std::ofstream outputFile("output.exe", std::ios::binary);
    if (outputFile) {
        for (int i = 0; i < binaryValue.length(); i += 8) {
            std::string byte = binaryValue.substr(i, 8);
            char c = static_cast<char>(std::stoi(byte, nullptr, 2));
            outputFile.write(&c, 1);
        }
        outputFile.close();
        std::cout << "Conversion successful. The 'output.exe' file has been created." << std::endl;
    }
    else {
        std::cout << "Error creating the file." << std::endl;
        return 1;
    }

    return 0;
}
