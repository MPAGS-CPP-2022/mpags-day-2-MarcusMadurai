#include <iostream>
#include <vector>
#include <string>

#include "RunCeaserCipher.hpp"


std::string runCeaserCipher(const std::string& inputText, const size_t key, const std::string crypt){

    std::string outputstr {""};
    std::vector<char> alphabet {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int element;
    int shiftedelement;
    std::string cipherdText{""};

    for(std::string::size_type i = 0; i < inputText.size(); ++i) {
        //finding the element number of each letter in inputText in the alphabet
        for(std::string::size_type j = 0; j < alphabet.size(); ++j) {
            //if there is an alphabet match
            if (inputText[i] == alphabet[j]) {
                element = j;    //find element of this in alphabet list
                if (crypt == "encrypt"){
                    shiftedelement = element + key; //if want to encrypt, then positive shift by key
                }
                else if (crypt == "decrypt"){
                    shiftedelement = element - key; //else negative shift by key
                }
                //perform wrap if neccessary for both directions of shift, even if the cipher shift is >25
                while (shiftedelement > 25){
                    shiftedelement -= 26;
                }
                while (shiftedelement < 0){
                    shiftedelement += 26;
                }
            cipherdText += alphabet[shiftedelement];
            }
        }
    }
    //test print
    //std::cout << cipherdText << std::endl;
    return cipherdText;

}
