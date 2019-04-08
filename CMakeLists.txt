set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.5.1)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
#option(test "Build all test." OFF) # Makes boolean 'test' available.
project(money_insight)

set(CMAKE_CXX_FLAGS "-g -Wall")

# Locate GTest
#find_package(GTest REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/db)



################################
# Testing
################################
#MESSAGE(STATUS "${test}")
#if (test)
#    add_executable(${PROJECT_NAME} test.cpp)
#else()
    # Create the executable
    add_executable(${PROJECT_NAME}
            main.cpp
            api/Transaction.cpp
            api/Transaction.h api/TransactionBook.cpp api/TransactionBook.h api/Database.cpp api/Database.h)
#target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
add_subdirectory(lib/mongoose-cpp)
add_subdirectory(test)
include_directories(lib/mongoose-cpp)

FIND_LIBRARY(SQLITE3_LIBRARY NAMES sqlite3)
find_package (SQLite3 REQUIRED)
if (SQLITE3_FOUND)
    include_directories(${SQLITE3_INCLUDE_DIRS})
    target_link_libraries (${PROJECT_NAME} ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)

target_link_libraries(${PROJECT_NAME}
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY})
target_link_libraries(${PROJECT_NAME} mongoose)


#endif()

