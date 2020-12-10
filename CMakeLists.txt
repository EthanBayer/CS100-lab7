CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(googletest/include)

ADD_EXECUTABLE( calculator
    calculator.cpp
)


ADD_EXECUTABLE( unit_test
    test/unit_test.cpp
)


TARGET_LINK_LIBRARIES(unit_test gtest)
TARGET_COMPILE_DEFINITIONS(unit_test PRIVATE gtest_disable_pthreads=ON)