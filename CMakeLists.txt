cmake_minimum_required(VERSION 3.16)
project(queqe)

set(CMAKE_CXX_STANDARD 17)

add_executable(queqe main.cpp stack.h cmake-build-debug/nodes.h deque.h queqe.h)