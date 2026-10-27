# HunterX

A Windows console game written in C++20.

## Build and run in CLion

1. Open the root `CMakeLists.txt` and choose **Open as Project**.
2. Use CLion's bundled **MinGW** toolchain and the **Debug** CMake profile.
3. Let CMake finish loading, then select the **HunterX** run configuration and click **Run**.

Use the `HunterX` CMake target rather than the single-file `HunterX.cpp - MinGW`
configuration: the game needs all its source files linked together.

The shared run configuration opens an external console for `_getch()` and arrow-key
input. Its working directory is `HunterX/`, where the existing `SavedData.txt` lives.
The game uses Windows APIs (`Windows.h`, `_getch()`, and `cls`), so this setup targets Windows.

The Visual Studio project files are also retained.
