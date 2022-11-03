#ifndef MPAGSCIPHER_RUNCEASERCIPHER_HPP
#define MPAGSCIPHER_RUNCEASERCIPHER_HPP
//use C++ preprocessor to only compiles #includes if they haven't been done before

#include <string>

//can use header to define all our functions in one go instead of having to do it at the top of each file

//function definition of transform function
std::string runCeaserCipher(const std::string& inputText, const size_t key, const std::string encrypt);

#endif // MPAGSCIPHER_RUNCEASERCIPHER_HPP