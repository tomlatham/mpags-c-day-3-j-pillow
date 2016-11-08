//! Unit Tests for MPAGSCipher transformChar interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

#include <iostream>
#include <vector>

const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const size_t nAlphabet = alphabet_.size();

TEST_CASE("Characters are encrypted successfully", "[alphanumeric]") {
	for ( size_t i{0} ; i < 2*nAlphabet ; i++ ) {  // Do twice alphabet size to test wrapping
		std::string testElem = "A";  // Test on fixed character as should be same for any arbitrary character and is simplest with A
		CaesarCipher cipher {i};  // Set cipher_key equal to i
		std::string cipheredTest {cipher.applyCipher(testElem,CipherMode::encrypt)};  // Apply the cipher to testElem
		if ( i < nAlphabet ) { 
			testElem = alphabet_[i]; // For shifts less than length of vector, shift makes A become value at index i
			REQUIRE ( cipheredTest == testElem );
		}
		else {
			testElem = alphabet_[i - nAlphabet]; // For shifts bigger than length of vector, shift makes A become value at index i minus length of vector
			REQUIRE ( cipheredTest == testElem );
		}
	}	
}

TEST_CASE("Characters are decrypted successfully", "[alphanumeric]") {
	for ( size_t i{0} ; i < 2*nAlphabet ; i++) {		
		std::string testElem = "Z";
		CaesarCipher cipher {i};
		std::string cipheredTest {cipher.applyCipher(testElem,CipherMode::decrypt)};
		if ( i < nAlphabet ) {
			testElem = alphabet_[nAlphabet-1-i];
			REQUIRE ( cipheredTest == testElem);
		}
		else {
			testElem = alphabet_[nAlphabet - (i % nAlphabet) - 1];
			REQUIRE ( cipheredTest == testElem );
		}
	}
}