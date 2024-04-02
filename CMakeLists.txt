cmake_minimum_required(VERSION 3.20)
project(code_fun VERSION 1.0.0 LANGUAGES CXX)
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g -ggdb")
#set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# set(lib_dir "lib")
# list(APPEND libs googletest)
# foreach(lib ${libs})
#     add_subdirectory(${lib_dir}/${lib})
# endforeach()

# 环境中已经安装的lib
#find_package(tcmalloc REQUIRED)

list(APPEND dirs binary_tree)
foreach(dir ${dirs})
    add_subdirectory(${dir})
endforeach()

add_subdirectory(third_party)

file(GLOB_RECURSE src_files "src/*.cc")
foreach(path ${src_files})
    get_filename_component(name ${path} NAME_WE)
    add_executable(${name} ${path})
    target_link_libraries(${name} gtest_main)
    
    target_include_directories(${name} PRIVATE
        base
    )

    foreach(dir ${dirs})
        target_link_libraries(${name} ${dir})
        target_link_libraries(${name} tcmalloc)
    endforeach()
    
endforeach()

#list(APPEND folders base binary_tree)
# foreach(folder ${folders})
#     add_subdirectory(${folder})
# endforeach(folder ${folders})
