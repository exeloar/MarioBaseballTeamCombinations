cmake_minimum_required(VERSION 3.17)
project(MarioBaseballTeamCombinations)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UniqueTeamCounter
        gamedata.cpp
        gamedata.h
        team.cpp
        team.h
        uniqueteam.cpp)

add_executable(TeamComboCounter
        gamedata.cpp
        gamedata.h
        team.cpp
        team.h
        teamcombo.cpp)