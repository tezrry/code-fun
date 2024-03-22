add_library(binary_tree SHARED treap.cpp)
target_include_directories(binary_tree PUBLIC
        ${CMAKE_SOURCE_DIR}/base
)
target_include_directories(binary_tree INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)