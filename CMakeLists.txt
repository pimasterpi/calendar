cmake_minimum_required(VERSION 3.26)
project(calendar C)

set(CMAKE_C_STANDARD 99)

add_executable(calendar main.c
        events.h
        date_time.h)
