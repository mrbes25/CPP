/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:50:16 by bschmid           #+#    #+#             */
/*   Updated: 2025/07/03 14:50:18 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void showUsage(const std::string& programName) {
	std::cout << "Usage: " << programName << " <filename> <s1> <s2>" << std::endl;
	std::cout << "	filename: File to process" << std::endl;
	std::cout << "	s1: String to find and replace" << std::endl;
	std::cout << "	s2: Replacement string" << std::endl;
}

// Function to read entire file content
std::string readFile(const std::string& filename) {
	std::ifstream file(filename.c_str()); // .c_str for 98 compatibility

	if (!file.is_open()) {
		std::cerr << "Error: Cannot open file" << filename << std::endl;
		return "";
	}

	// Read entire file content
	std::string content;
	std::string line;

	// Read line by line and preserve newlines
	while (std::getline(file, line)) {
		content += line;
		if (!file.eof()) { // Don't add newline after last line
			content += '\n';
		}
	}

	file.close();
	return content;
}

// Function to replace all occurrences of s1 with s2
std::string replaceAll(std::string content, const std::string& s1, const std::string& s2) {
	if (s1.empty()) {
		std::cout << "Warning: Empty search string (s1)" << std::endl;
		return content;
	}

	size_t pos = 0;
	size_t replacements = 0;

	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
		replacements++;
	}

	std::cout << "Performed " << replacements << " replacements" << std::endl;
	return content;
}

// Function to write content to file
bool writeFile(const std::string& filename, const std::string& content) {
	std::ofstream file(filename.c_str());

	if (!file.is_open()) {
		std::cerr << "Error: Cannot create file " << filename << std::endl;
		return false;
	}

	file << content;
	file.close();

	std::cout << "Output written to " << filename << std::endl;
	return true;
}

int main(int ac, char **av){
	if (ac != 4) {
		std::cerr << "Errpr: Wrong number of arguments" << std::endl;
		showUsage(av[0]);
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::cout << "Processing file: " << filename << std::endl;
	std::cout << "Replacing '" << s1 << "' '" << s2 << "'" << std::endl;

	// Read fo;e
	std::string content = readFile(filename);
	if (content.empty()) {
		std::ifstream testFile(filename.c_str());
		if (!testFile.is_open()) {
			return 1;
		}
		testFile.close();
		std::cout << "File is empty or contain only whitesoace" << std::endl;
	}

	// Performe replacement
	std::string result = replaceAll(content, s1, s2);

	// Write result
	std::string outputFilename = filename + ".replace";
	if (!writeFile(outputFilename, result)) {
		return 1;
	}
	return 0;
}
