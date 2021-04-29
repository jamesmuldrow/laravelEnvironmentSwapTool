# LARAVEL ENVIRONMENT SWAP TOOL

### This tool was developed in order to simplify the process associated with swapping between environments in laravel.

### The current binary was compiled on a Mac. To compile from source to support your OS id the binary does not work use g++ or your favorite compiler as follows:
````
g++ envswap.cpp -o envswap
````

### To use the envswap binary, simply clone the repo and drop envswap in the laravel root directory.

Help will output the following:
````bash
./envswap --h
````
````text

                          Environment Swap Tool 1.0
                                Developed by
                              James A. Muldrow
                             www.jamesmuldrow.com

Purpose: This program is used to swap environment files when using the laravel or lumen frameworks.

Usage: envswap --h
Usage: envswap -e [environment]
Usage: envswap -e [environment] [optional flag: "--ignore_questions"]


Example: envswap -e local
Example: envswap -e local --ignore_questions


This program requires that you have a file named .env.[dev name] in the local directory
[dev name] can be local, remote, staging, etc; This program will overwrite the .env file with data from 
the specified env file. Do NOT write directly to the .env file. Write to .env.local, .env.remote, and
then run this program in order to switch dev environments.

````

Enjoy, and feel free to make recommendations.
