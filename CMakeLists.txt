cmake_minimum_required(VERSION 3.20)
project(HunterX LANGUAGES CXX)

add_executable(HunterX
    HunterX/Area.cpp
    HunterX/CharacterCreation.cpp
    HunterX/Controller.cpp
    HunterX/GameState.cpp
    HunterX/HunterX.cpp
    HunterX/LoadSave.cpp
    HunterX/Location.cpp
    HunterX/MainMenu.cpp
    HunterX/Map.cpp
    HunterX/Player.cpp
    HunterX/PlayGame.cpp
    HunterX/Roaming.cpp
    HunterX/TitleScreen.cpp
    HunterX/TypeWrite.cpp
    HunterX/WhaleIsland.cpp
        HunterX/ContentNode.h
        HunterX/ContentNode.cpp
        HunterX/ContentNodeTree.h
        HunterX/ContentNodeTree.cpp
)

target_compile_features(HunterX PRIVATE cxx_std_20)
set_target_properties(HunterX PROPERTIES CXX_EXTENSIONS OFF)

# Seed the build directory without overwriting saves on later builds.
if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/SavedData.txt")
    configure_file(HunterX/SavedData.txt SavedData.txt COPYONLY)
endif()
