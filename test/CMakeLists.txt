set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.5.1)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
#option(test "Build all test." OFF) # Makes boolean 'test' available.
project(money_insight_test)

find_package(Boost COMPONENTS system filesystem REQUIRED)


set(CMAKE_CXX_FLAGS "-g -Wall")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../cmake")
MESSAGE(STATUS " CMAKE MODULE PATH: ${CMAKE_MODULE_PATH}")

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
add_executable(${PROJECT_NAME} RunAllTests.cpp ${SRC_FILES} TestTransactionBook.cpp TestTransaction.cpp TestDatabase.cpp)
#else()
# Create the executable
#add_executable(${PROJECT_NAME}
#        main.cpp
#        api/Transaction.cpp
#        api/Transaction.h api/TransactionBook.cpp api/TransactionBook.h whattotest.cpp)

find_package (SQLite3 REQUIRED)
if (SQLITE3_FOUND)
    include_directories(${SQLITE3_INCLUDE_DIRS})
    target_link_libraries (${PROJECT_NAME} ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)

target_link_libraries(${PROJECT_NAME}
        ${GTEST_LIBRARIES}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        pthread)

#endif()

