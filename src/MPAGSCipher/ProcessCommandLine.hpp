#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
//use C++ preprocessor to only compiles #includes if they haven't been done before

#include <string>
#include <vector>

bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName, int& key, std::string& crypt);

#endif  //MPAGSCIPHER_PROCESSCOMMANDLINE_HPP