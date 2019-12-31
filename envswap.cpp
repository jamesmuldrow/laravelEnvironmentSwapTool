/**
*
* Filename: envswap.cpp
* Author: James A. Muldrow
* Date: 30 December 2019
*
* Purpose: This program will 
* be used to swap environment files 
* when using the laravel or lumen frameworks
*
**/
// Include files
#include <iostream>
#include <cstring>
#include <string>
#include <filesystem>
#include <locale>
// Namespace to use
using namespace std;

/**
 * Print helpful information
 * @return string
 **/
string printHelp(bool extended = false){
    string helpString = "";
    if (extended == false){
        helpString = "\nPurpose: This program will be used to swap environment files when using the laravel or lumen frameworks.\n" \
                        "\nUsage: envswap --h\n" \
                        "Usage: envswap -e [environment]\n" \
                        "\nExample: envswap -e local\n\n";
    } else {
        helpString = "\nPurpose: This program will be used to swap environment files when using the laravel or lumen frameworks.\n" \
                        "\nUsage: envswap --h\n" \
                        "Usage: envswap -e [environment]\n" \
                        "\nExample: envswap -e local\n\n" \
                        "\nThis program requires that you have a file named .env.[dev name] in the " \
                        "local directory\n" \
                        "[dev name] can be local, remote, staging, etc; " \
                        "This program will overwrite the .env file with data from the specified env file." \
                        "\nDo NOT write directly to the .env file. Write to .env.local, .env.remote, and" \
                        "\nthen run this app in order to switch dev environments.\n\n";
    }
    return helpString;
}
/**
 * Swap Environment file based on command line argument
 **/
int swapEnvFile(char * env){
    char prefix[] = "./.env"; 
    string fileName = string(prefix) + "." + env;
    if(filesystem::exists(fileName)){
        string input;
        cout << "\nYou are about to overwrite the .env file with data from: " << fileName;
        cout << "\nAre you sure you want to proceed (yes or no): ";
        cin >> input;
        if (input == string("yes") || input == "YES"){
            filesystem::copy_file(fileName, "./.env", filesystem::copy_options::overwrite_existing);
            cout << "\nEnvironment swap complete. You are now using the: \""<< 
            env << "\" environment variables. Goodbye.\n\n";
        } else if (input == string("no") || input == "NO") {
            cout << "\nOk, no changes were made. Goodbye!\n\n";
        } else {
            cout << "Invalid entry. Goodbye.";
        }
    }else{
        cout << fileName << " does not exist!\n";
        cout << printHelp() << endl;
    }
    return 0;
}

/**
 * Main entry point for the program
 * @return int
 **/
int main(int argc, char * argv[]){
    if (argc > 1){
        if (strcmp(argv[1], "--h") == 0){
            cout << printHelp(true) << "\n";
        } else if (strcmp(argv[1], "-e") == 0){
            if (argc > 2 && argc < 4){
                if (strlen(argv[2]) > 0){
                    swapEnvFile(argv[2]);
                } else {
                    cout << printHelp() << "\n";
                }
            } else {
                cout << printHelp() << "\n";
            }
        } else {
            cout << printHelp();
        }
    } else {
        cout << printHelp();
    }
    return 0;
}

