#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>


std::vector<int> getNums(std::string str) {
    std::vector<int> tokens;
    std::istringstream iss(str); // Use stringstream to tokenize the string
    std::string token;

    while (std::getline<char>(iss, token, ', ')) { // Tokenize by comma
        try {
            if (token.find("0x") == 0 || token.find("0X") == 0) {
                tokens.push_back(std::stoi(token, nullptr, 16));
            } else {
                tokens.push_back(std::stoi(token));
            }
        } catch (const std::invalid_argument&) {
            std::cerr << "Invalid argument: " << token << std::endl;
        } catch (const std::out_of_range&) {
            std::cerr << "Out of range: " << token << std::endl;
        }
    }

    return tokens;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1; // Exit with an error code indicating incorrect usage
    }

    std::string code = argv[1];

    std::vector<int> hi = getNums(code);

    for (auto hello : hi) {
        char ascii_letter = static_cast<char>(hello);
        std::cout << ascii_letter;
    }

    return 0;
}