cmake_minimum_required(VERSION 3.5)
project(SecondPart)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(SecondPart main.cpp Server.h MySerialServer.h ClientHandler.h MyTestClientHandler.h Solver.h CacheManager.h MySerialServer.cpp StringReverser.h FileCacheManager.cpp FileCacheManager.h MyTestClientHandler.cpp State.h Searchable.h MazeMatrix.cpp MazeMatrix.h ISearcher.h SearchSolver.h BFS.h DFS.h BestFirstSearch.h Astar.h DFS.cpp Astar.cpp BFS.cpp Searcher.h Searcher.cpp BestFirstSearch.cpp MyClientHandler.cpp MyClientHandler.h Converter.cpp Converter.h MyParallelServer.cpp MyParallelServer.h)