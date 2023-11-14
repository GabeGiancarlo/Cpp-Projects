#include <iostream>
#include <string>

const char k_cAuthenticatorCodeCharacter1 = 'E';
const char k_cAuthenticatorCodeCharacter2 = 'C';
const char k_cAuthenticatorCodeCharacter3 = 'A';
const int k_iValidCodeChecksum = 5;

int main() {
    char messageCodeCharacter1, messageCodeCharacter2, messageCodeCharacter3;
    std::string messageCode, authenticatorCode;

    // Part I: Entering and Displaying the Codes

    std::cout << "Enter the first character of the message code: ";
    std::cin >> messageCodeCharacter1;
    std::cout << "Enter the second character of the message code: ";
    std::cin >> messageCodeCharacter2;
    std::cout << "Enter the third character of the message code: ";
    std::cin >> messageCodeCharacter3;

    messageCode = messageCodeCharacter1;
    messageCode += messageCodeCharacter2;
    messageCode += messageCodeCharacter3;

    authenticatorCode += k_cAuthenticatorCodeCharacter1;
    authenticatorCode += k_cAuthenticatorCodeCharacter2;
    authenticatorCode += k_cAuthenticatorCodeCharacter3;

    std::cout << "Message Code: " << messageCode << std::endl;
    std::cout << "Authenticator Code: " << authenticatorCode << std::endl;

    // Part II: Reporting the Authenticity of the Code Using Character by Character Comparison
    std::cout << "\nPart II: Reporting the Authenticity of the Code Using Character by Character Comparison" << std::endl;

    if (messageCodeCharacter1 == k_cAuthenticatorCodeCharacter1 &&
        messageCodeCharacter2 == k_cAuthenticatorCodeCharacter2 &&
        messageCodeCharacter3 == k_cAuthenticatorCodeCharacter3) {
        std::cout << "Message is authentic" << std::endl;
    } else {
        std::cout << "Message is invalid" << std::endl;
    }

    // Part III: Reporting the Authenticity of the Code Using String Comparison
    std::cout << "\nPart III: Reporting the Authenticity of the Code Using String Comparison" << std::endl;

    if (messageCode == authenticatorCode) {
        std::cout << "Concurrence: message is authentic" << std::endl;
    } else {
        std::cout << "Concurrence: message is invalid" << std::endl;
    }

    // Part IV: Characterizing the Received Message Code
    std::cout << "\nPart IV: Characterizing the Received Message Code" << std::endl;

    int checksum = (int(messageCodeCharacter1) + int(messageCodeCharacter2) + int(messageCodeCharacter3)) % 7;

    std::cout << "Checksum: " << checksum << std::endl;

    if (checksum == k_iValidCodeChecksum) {
        std::cout << "Checksum matches the valid code checksum" << std::endl;
    } else {
        std::cout << "Checksum does not match the valid code checksum" << std::endl;
    }

    std::cout << "ASCII Values: " << int(messageCodeCharacter1) << ", " << int(messageCodeCharacter2) << ", " << int(messageCodeCharacter3) << std::endl;

    if (messageCodeCharacter1 != k_cAuthenticatorCodeCharacter1) {
        std::cout << "Character 1 does not match Authenticator Code" << std::endl;
    }
    if (messageCodeCharacter2 != k_cAuthenticatorCodeCharacter2) {
        std::cout << "Character 2 does not match Authenticator Code" << std::endl;
    }
    if (messageCodeCharacter3 != k_cAuthenticatorCodeCharacter3) {
        std::cout << "Character 3 does not match Authenticator Code" << std::endl;
    }

    if (messageCode < authenticatorCode) {
        std::cout << "Message Code is lexicographically less than Authenticator Code" << std::endl;
    } else if (messageCode > authenticatorCode) {
        std::cout << "Message Code is lexicographically greater than Authenticator Code" << std::endl;
    }

    return 0;
}
