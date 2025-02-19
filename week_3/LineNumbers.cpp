#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::string inputFileName, outputFileName;
    
    // Prompt user for input file name
    std::cout << "Enter the name of the input file: ";
    std::getline(std::cin, inputFileName);
    
    // Open input file
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }
    
    // Prompt user for output file name
    std::cout << "Enter the name of the output file: ";
    std::getline(std::cin, outputFileName);
    
    // Open output file
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error: Could not open output file." << std::endl;
        return 1;
    }
    
    std::string line;
    int lineNumber = 1;
    
    // Read each line from input file and write to output file with line number
    while (std::getline(inputFile, line)) {
        outputFile << std::setw(5) << lineNumber << ". " << line << std::endl;
        lineNumber++;
    }
    
    // Close files
    inputFile.close();
    outputFile.close();
    
    std::cout << "File processing complete. Output saved to " << outputFileName << std::endl;
    return 0;
}
