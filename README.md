# Samp plugin raw

## What you need to know

 - GTA sa and samp use 32-bit architecture. The plugin also needs to be compiled for 32-bit.
 - `AMX*`: pointer to game mode.
 - `invoke`: searches for and invokes the function using the name as a parameter. The passed amx must contain the registered passed function. See the example `server/gamemodes/main.pwn`, which contains all registered native samp functions.

## Requirements for Linux

Install these via package manager:

 - `git`
 - `cmake`
 - `ninja`

## Build

 - Run build.sh.