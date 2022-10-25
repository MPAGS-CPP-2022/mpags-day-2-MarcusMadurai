#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//our project headers
#include "RunCeaserCipher.hpp"
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
//function definition:


int main(int argc, char* argv[])
{
    // Convert the command-line arguments into a more easily usable form
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Options that might be set by the command-line arguments
    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    int key = 0;//MUST DEFINE THESE
    std::string crypt{""};   //true == encrypt, false == decrypt

    //ADDED NEW ARGS
    if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, key, crypt)){
        return 1;   //something has gone wrong with CLargs, halt program
    }

    // Handle help, if requested
    if (helpRequested) {
        // Line splitting for readability
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        // Help requires no further action, so return from main
        // with 0 used to indicate success
        return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
        std::cout << "0.1.0" << std::endl;
        return 0;
    }

    // Initialise variables
    char inputChar{'x'};
    std::string inputText;

    // Read in user input from stdin/file
    if (!inputFile.empty()) {
        std::ifstream in_file {inputFile};
        if (in_file.good()){    //if the file is readable
            while (in_file >> inputChar) {
            inputText += transformChar(inputChar);
            }
            in_file.close();
        }
        else{   //else revert to stdin
            while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
            }
        }
    }

    std::string cipherdtext{""};
    //run ciphering function to encrypt or decrypt text
    cipherdtext = runCeaserCipher(inputText, key, crypt);
    //print in cmdline just for sanity!
    std::cout << cipherdtext << std::endl;

    if (!outputFile.empty()) {
        std::ofstream out_file {outputFile};
        if (out_file.good()){   //if out file is okay to write to
            out_file << cipherdtext;  //pipe input text into there for now
            out_file.close();
        }
        else{
            std::cout << cipherdtext << std::endl;
        }
    }

    //std::cout << inputText << std::endl;

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
}

