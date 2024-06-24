cmake_minimum_required(VERSION 3.28)
project(BonusOhneQt)

set(CMAKE_CXX_STANDARD 17)

add_executable(BonusOhneQt main.cpp
        Lehrer.h
        Lehrer.cpp
        Person.h
        Person.cpp
        Schulverwaltungssystem.h
        Schulverwaltungssystem.cpp
        SuS.h
        SuS.cpp)
