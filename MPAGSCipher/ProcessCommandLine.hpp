#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"


struct ProgramSettings {
	bool helpRequested;	///< Identifies if help needs to be displayed
	bool versionRequested;	///< Idintifies if version was requested
	std::string inputFile;	///< Takes name of input file
	std::string outputFile; ///< Takes name of output file
	std::string cipher_key; ///< Takes the key for the cipher
	CipherMode cipherMode;	///< Decides whether to encrypt or decrypt
};

bool processCommandLine(const std::vector<std::string>& args, ProgramSettings& settings);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
