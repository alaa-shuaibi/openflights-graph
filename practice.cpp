#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void foo() {
  printf("Hello, World!");
}

/**
 * Takes a filename and reads in all the text from the file
 * Newline characters are also just characters in ASCII
 * 
 * This can also be adjusted to return a vector instead of a string
 * Refer to the AMA slides to know how to do this.
 * 
 * @param filename The name of the file that will fill the string
 */
std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}