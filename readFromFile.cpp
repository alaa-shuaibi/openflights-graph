#include "readFromFile.h"
#include <vector>
#include <string>
/** 
 * Reads a file into a string
 * @param filename The file to read from 
 * @return a string containing filename's contents
 */
std::string readFromFile::file_to_string(const std::string & filename) {
	std::ifstream text(filename);

	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

/** 
 * Reads a file into a vector
 * @param filename The file to read from
 * @return a vector containing filename's contents
 */
std::vector<std::string> readFromFile::file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
}