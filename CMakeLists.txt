cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 11)

project(Unstoppable-Knight_SG)

include_directories(/home/rafagars/SGDK/inc)
include_directories(res)
include_directories(inc)

add_executable(Unstoppable_Knight_GB
        res/resources.h
        inc/characters.h
        inc/functions.h
        inc/entity.h
        inc/scenes.h
        inc/ui.h
        src/characters.c
        src/functions.c
        src/entity.c
        src/scenes.c
        src/ui.c
        main.c)
