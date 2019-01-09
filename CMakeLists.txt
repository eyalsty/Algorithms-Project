cmake_minimum_required(VERSION 3.12)
project(SecondPart)

set(CMAKE_CXX_STANDARD 14)

add_executable(SecondPart main.cpp Server.h MySerialServer.h ClientHandler.h MyTestClientHandler.h Solver.h CacheManager.h MySerialServer.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h)