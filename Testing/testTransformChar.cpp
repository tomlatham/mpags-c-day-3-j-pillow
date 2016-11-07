//! Unit Tests for MPAGSCipher transformChar interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"

#include <iostream>
#include <vector>

TEST_CASE("Characters are uppercased", "[alphanumeric]") {

	std::vector<char> alphabetUpper = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	std::vector<char> alphabetLower = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	const size_t nAlphabet = alphabetUpper.size();
	std::string upperCase {""};
	
	for( size_t i{0} ; i < nAlphabet ; i++){
		upperCase = alphabetUpper[i]; 
		REQUIRE( transformChar(alphabetLower[i]) == upperCase ); // Test if transformChar is working properly
	}
}

TEST_CASE("Digits are transliterated", "[punctuation]") {
	REQUIRE( transformChar('0') == "ZERO" );
	REQUIRE( transformChar('1') == "ONE" );
	REQUIRE( transformChar('2') == "TWO" );
	REQUIRE( transformChar('3') == "THREE" );
	REQUIRE( transformChar('4') == "FOUR" );
	REQUIRE( transformChar('5') == "FIVE" );
	REQUIRE( transformChar('6') == "SIX" );
	REQUIRE( transformChar('7') == "SEVEN" );
	REQUIRE( transformChar('8') == "EIGHT" );
	REQUIRE( transformChar('9') == "NINE" );
}

TEST_CASE("Special characters are removed", "[punctuation]") {
	REQUIRE( transformChar('!') == "" );
	REQUIRE( transformChar('$') == "" );
	REQUIRE( transformChar('%') == "" );
	REQUIRE( transformChar('^') == "" );
	REQUIRE( transformChar('&') == "" );
	REQUIRE( transformChar('*') == "" );
	REQUIRE( transformChar('(') == "" );
	REQUIRE( transformChar(')') == "" );
	REQUIRE( transformChar('_') == "" );
	REQUIRE( transformChar('-') == "" );
	REQUIRE( transformChar('=') == "" );
	REQUIRE( transformChar('+') == "" );
}