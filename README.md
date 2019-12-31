# LARAVEL ENVIRONMENT SWAP TOOL

### This tool was developed in order to simplify the process associated with swapping between environments in laravel.

### To use the envswap binary, simply clone the repo and drop envswap in the laravel root directory.

Help will output the following:
````bash
./envswap --h
````
````text
                          Environment Swap Tool 1.0
                                Developed by
                              James A. Muldrow
                             www.codespace.blog

Purpose: This program is used to swap environment files when using the laravel or lumen frameworks.

Usage: envswap --h
Usage: envswap -e [environment]

Example: envswap -e local


This program requires that you have a file named .env.[dev name] in the local directory
[dev name] can be local, remote, staging, etc; This program will overwrite the .env file with data from the specified env file.
Do NOT write directly to the .env file. Write to .env.local, .env.remote, and
then run this app in order to switch dev environments.

````

Enjoy, and feel free to make recommendations.