# Samp plugin raw

Simple template to create plugins and gamemodes for samp using c.

## What You Need to Know

 - `GTA SA` and `SA-MP` use a 32-bit architecture. The plugin also needs to be compiled for 32 bits.
 - `AMX*`: pointer to the game mode.
 - `invoke`: searches for and invokes the function using the name as a parameter. The AMX must contain the registered function. See the example `server/gamemodes/main.pwn`, which contains all the native SA-MP functions registered.

## Requirements for Linux

Install these via package manager:

 - `git`
 - `make`
 - `clang`

## Build and test

Download and copy the server files into the `server` folder.
Compile file `server/gamemodes/main.pwn`. This file contains all the functions for invoke. It also contains an example of use.
Add plugin and script in server configuration file

 - `make build` build library
 - `make install` build and install library in the server.
 - `make run` build and install library and run server.
 - `make clean` clean output files