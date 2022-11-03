#CMake requirements
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

#output all command lines by defaule when Makefile is generated
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_EXTENSIONS OFF)   #not sure what this does

#set the C++ standard we've been using
set(CMAKE_CXX_STANDARD 14)

#decalre the build of mpags-cipher main program
add_executable(mpags-cipher mpags-cipher.cpp MPAGSCipher/TransformChar.cpp MPAGSCipher/ProcessCommandLine.cpp MPAGSCipher/RunCeaserCipher.cpp)

target_include_directories(mpags-cipher PRIVATE MPAGSCipher)#relative path to loc. of TransformChar.hpp

#set our compiler walls/flags to as before
set(CMAKE_CXX_FLAGS "")
#-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic

target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)

