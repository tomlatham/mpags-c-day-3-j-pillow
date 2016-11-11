#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <vector>
#include <string>
#include <cstddef>
#include "CipherMode.hpp"

/**
	* 
*/
class CaesarCipher {
	public:
	/**
		* Create a new caesar cipher instance with a key
		* 
		* \param cipherKey the value for the key of the cipher
	*/
	CaesarCipher(const size_t cipherKey);
	
	/**
		* Applies the cipher to a given text, either encrypting or decrypting
		*
		* \param inputText the text to be run through the cipher
		*
		* \param mode whether to encrypt or decrypt
		*
		* \return the encrypted/decrypted text
	*/
	std::string applyCipher(const std::string& inputText, const CipherMode mode) const;
	
	private:
	
	/// the key of the cipher
	size_t key_;
	/// alphabet vector for cipher to loop over
	const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP 
