#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <vector>
#include <string>
#include <cstddef>

class CaesarCipher {
	public:
	CaesarCipher(const size_t cipherKey);
	std::string applyCipher(const std::string& inputText, const bool encrypt) const;
	
	private:
	size_t key_;	///< Key for the cipher
	const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

#endif // MPAGSCIPHER_CAESARCIPHER_HPP 