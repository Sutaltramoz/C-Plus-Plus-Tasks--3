#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputName;
    std::string outputName;

    std::cout << "Enter the name of the file you want to back up (e.g., log.txt): ";
    std::cin >> inputName;

    std::ifstream inputFile(inputName.c_str());

    if (!inputFile.is_open()) {
        std::cout << "Error: The file '" << inputName << "' was not found!\n";
        return 1;
    }

    std::cout << "Enter the name for your new backup file (e.g., backup.txt): ";
    std::cin >> outputName;

    std::ofstream outputFile(outputName.c_str());

    if (!outputFile.is_open()) {
        std::cout << "Error: Could not create the backup file '" << outputName << "'.\n";
        inputFile.close();
        return 1;
    }

    std::string line;
    std::cout << "\nReading '" << inputName << "' and copying contents...\n";

    while (std::getline(inputFile, line)) {
        outputFile << line << "\n";
    }

    std::cout << "Success: File backed up completely into '" << outputName << "'!\n";

    inputFile.close();
    outputFile.close();

    return 0;
}
