cmake_minimum_required(VERSION 3.10.2)
project(mod-lab03-coffee)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")

set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

set(SOURCES
    src/Automata.cpp
    src/main.cpp
)

set(HEADERS
    include/Automata.h
)

add_library(mod-lab03-coffee src/Automata.cpp)

target_include_directories(mod-lab03-coffee
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(mod-lab03-coffee.info src/main.cpp)

target_link_libraries(mod-lab03-coffee.info
    mod-lab03-coffee
)

# add_subdirectory(test) - удалите эту строку, если нет отдельного CMakeLists.txt в test

install(TARGETS mod-lab03-coffee
    ARCHIVE DESTINATION ${lib_dest}
    LIBRARY DESTINATION ${lib_dest}
)

install(TARGETS mod-lab03-coffee.info
    RUNTIME DESTINATION ${tool_dest}
)

install(DIRECTORY include/
    DESTINATION ${include_dest}
)
