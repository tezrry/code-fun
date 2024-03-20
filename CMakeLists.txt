cmake_minimum_required(VERSION 3.12)
project(code_fun VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(lib_dir "lib/")
list(APPEND libs googletest)
foreach(lib ${libs})
    add_subdirectory(${lib_dir}${lib})
endforeach(folder ${folders})
#list(APPEND folders base binary_tree)
# foreach(folder ${folders})
#     add_subdirectory(${folder})
# endforeach(folder ${folders})
