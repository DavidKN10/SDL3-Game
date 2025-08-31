# SDL3-Game
A game made in SDL3 C++

## Requirements
- Visual Studio
- CMake
- SDL3
- GCC compiler

## Build Instructions
Clone the repository and open the root folder in Visual Studio. Visual Studio should open a window called "CMake Integration". Click in "Enable and set source directory". You will then be prompted to open a `CMakeLists.txt` file. Open the one located in `SDL3-Game/CMakeLists.txt`.

In `CMakeUserPresets.json`, in `CMAKE_PREFIX_PATH`, set the path to the SDL root folder.
```json
{
  "version": 3,
  "configurePresets": [
    {
      "name": "x64-debug-user",
      "displayName": "x64 Debug (User)",
      "inherits": "x64-debug",
      "cacheVariables": {
        "CMAKE_PREFIX_PATH": "path to SDL root folder"
      }
    }
  ]
}
```

In Visual Studio, in the debug presets, set you preset to "x64 Debug (User)". The startup item should be the only one available which is "SDL3-Game.exe (src\SDL3-Game.exe)".

In the "Debug" option, choose "Debug and Lanuch Settings for SDL3-Game". File file named `launch.vs.json` should open.

Add the following to `launch.vs.json`:
```json
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "SDL3-Game\\CMakeLists.txt",
      "projectTarget": "SDL3-Game.exe (src\\SDL3-Game.exe)",
      "name": "SDL3-Game.exe (src\\SDL3-Game.exe)",
      "env": {
        "PATH": "(SDL3 dll file location);%PATH%"
      }
    }
  ]
}
```
In `PATH`, make sure to set the directory of the x64 version of the SDL3 dll files.

You should now be able to run the project without errors.