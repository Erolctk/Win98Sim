# Windows 98 Simulator (Raylib)

A simple Windows 98–style desktop simulator written in C++ using **raylib**.

This project is built for learning purposes:
- Basic window management
- Mouse interaction
- Retro UI rendering
- Project structure with multiple source files

## Features
- Win98-style desktop background
- Clickable desktop icons
- Movable windows
- Taskbar with Start button
- System clock (bottom-right)

## Project Structure
src/ -> source files
include/ -> header files
assets/ -> icons and textures
lib/ -> external libraries (raylib)

## Build
This project uses **raylib**.

Example (Windows, MinGW):
g++ src/*.cpp -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -o win98_sim

## Status
Work in progress.  
Planned improvements:
- Window controls (close / maximize)
- Start menu
- Keyboard focus
- Better Win98 visual accuracy
