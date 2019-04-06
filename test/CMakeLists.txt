set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.5.1)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
#option(test "Build all test." OFF) # Makes boolean 'test' available.
project(money_insight_test)

set(CMAKE_CXX_FLAGS "-g -Wall")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



################################
# Testing
################################
#MESSAGE(STATUS "${test}")
#if (test)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/../api/*)
MESSAGE(STATUS "Files: ${SRC_FILES}")
    add_executable(${PROJECT_NAME} RunAllTests.cpp ${SRC_FILES} TestTransactionBook.cpp TestTransaction.cpp)
#else()
# Create the executable
#add_executable(${PROJECT_NAME}
#        main.cpp
#        api/Transaction.cpp
#        api/Transaction.h api/TransactionBook.cpp api/TransactionBook.h whattotest.cpp)
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)

#endif()

