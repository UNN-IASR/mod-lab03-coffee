add_executable(mod-lab03-coffee.test
    tests.cpp
)

target_link_libraries(mod-lab03-coffee.test
    mod-lab03-coffee
    gtest
    gtest_main
    pthread
)

target_include_directories(mod-lab03-coffee.test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

add_test(NAME mod-lab03-coffee.test COMMAND mod-lab03-coffee.test)
