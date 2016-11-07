//! Unit Tests for MPAGSCipher transformChar interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

#include <iostream>
#include <vector>

/*
int main(int argc, char* argv[])
{
		// Convert the command-line arguments into a more easily usable form
		const std::vector<std::string> cmdLineArgs {argv, argv+argc};

		// Options that might be set by the command-line arguments
		ProgramSettings settings{false,false,"","","",CipherMode::encrypt};

		// Process command line arguments
		bool cmdLineStatus { processCommandLine(cmdLineArgs, settings) };
*/

TEST_CASE( "Command line is processed correctly", "[]" ) {
	std::vector<std::string> cmdLineArgs {"./mpags-cipher"};
	ProgramSettings settings {false, false,"","","",CipherMode::encrypt};
	
	SECTION( "Test help" ) {
		cmdLineArgs.push_back("-h");
		processCommandLine( cmdLineArgs, settings );
		REQUIRE ( settings.helpRequested == true );
	}
	
	SECTION( "Test version" ) {
		cmdLineArgs.push_back("--version");
		processCommandLine( cmdLineArgs, settings );
		REQUIRE ( settings.versionRequested == true );
	}
	
	SECTION( "Test input file pass" ) {
		cmdLineArgs.push_back("-i");
		cmdLineArgs.push_back("inputFile.txt");
		processCommandLine( cmdLineArgs, settings);
		REQUIRE( settings.inputFile == "inputFile.txt" );
	}
	
	SECTION( "Test input file fail" ) {
		cmdLineArgs.push_back("-i");
		REQUIRE( processCommandLine( cmdLineArgs, settings ) == false );
	}
	
	SECTION( "Test output file pass" ) {
		cmdLineArgs.push_back("-o");
		cmdLineArgs.push_back("outputFile.txt");
		processCommandLine( cmdLineArgs, settings);
		REQUIRE (settings.outputFile == "outputFile.txt" );
	}
	
	SECTION( "Test output file fail" ) {
		cmdLineArgs.push_back("-o");
		REQUIRE( processCommandLine( cmdLineArgs, settings ) == false );
	}
	
	SECTION( "Test encryption" ) {
		cmdLineArgs.push_back("--encrypt");
		processCommandLine( cmdLineArgs, settings);
		REQUIRE ( settings.encrypt == CipherMode::encrypt );
	}
	
	SECTION( "Test decryption" ) {
		cmdLineArgs.push_back("--decrypt");
		processCommandLine( cmdLineArgs, settings);
		REQUIRE ( settings.encrypt == CipherMode::decrypt );
	}
	
	SECTION( "Test key pass" ) {
		cmdLineArgs.push_back("-k");
		cmdLineArgs.push_back("5");
		processCommandLine( cmdLineArgs, settings);
		REQUIRE ( settings.cipher_key == cmdLineArgs[2] );
	}
	
	SECTION( "Test key fail" ) {
		cmdLineArgs.push_back("-k");
		REQUIRE (processCommandLine( cmdLineArgs, settings) == false );
	}
	
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	