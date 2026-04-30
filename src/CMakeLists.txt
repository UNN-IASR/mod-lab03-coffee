set(SOURCES
    Automata.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../include/Automata.h
)

add_library(mod-lab03-coffee SHARED
    ${SOURCES}
)

target_include_directories(mod-lab03-coffee
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_executable(mod-lab03-coffee.info
    main.cpp
)

target_link_libraries(mod-lab03-coffee.info
    mod-lab03-coffee
)

target_include_directories(mod-lab03-coffee.info
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
