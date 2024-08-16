# Samp plugin raw

Simple template to create plugins and gamemodes for samp using c/c++.

## What You Need to Know

 - `GTA SA` and `SA-MP` use a 32-bit architecture. The plugin also needs to be compiled for 32 bits.
 - `AMX*`: pointer to the game mode.
 - `invoke`: searches for and invokes the function using the name as a parameter. The AMX must contain the registered function passed. See the example server/gamemodes/main.pwn, which contains all the native SA-MP functions registered.

## Requirements for Linux

Install these via package manager:

 - `git`
 - `cmake`
 - `ninja`

## Build

 - Run build.sh.