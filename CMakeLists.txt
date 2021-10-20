cmake_minimum_required(VERSION 3.21)
project(pmp_client_cli)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(pmp_client_cli
        include/data.h
        src/data.cpp
        src/main.cpp include/utils.h src/utils.cpp src/crypto.cpp include/crypto.h lib/AES.cpp lib/AES.h)
