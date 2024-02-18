cmake_minimum_required(VERSION 3.26)
project(spellChecking C)

set(CMAKE_C_STANDARD 11)

add_executable(LearningC main.c
        datastructures/linkedlist.c
        datastructures/linkedlist.h
        algorithms/stringdistance.c
        algorithms/stringdistance.h
        algorithms/spellcheck.c
        algorithms/spellcheck.h)
