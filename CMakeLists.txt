cmake_minimum_required(VERSION 3.14)
project(testQueue)
add_executable(test test.c EventQueue.c EventProcessor.c)