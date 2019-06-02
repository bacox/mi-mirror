set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.5.1)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
#option(test "Build all test." OFF) # Makes boolean 'test' available.
project(money_insight)

set(CMAKE_CXX_FLAGS "-g -Wall")

# Locate GTest
#find_package(GTest REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

execute_process (
        COMMAND bash -c "rm -rf ${CMAKE_BINARY_DIR}/www"
        OUTPUT_VARIABLE outVar
)

file(COPY www DESTINATION .)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/db)


#FILE(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-src)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in ${CMAKE_BINARY_DIR}/googletest-download/CMakeLists.txt)
message(STATUS "cmake source: ${CMAKE_BINARY_DIR}")
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
#endif ()
#MESSAGE(STATUS " [1] GTEST_LIB: ${GTEST_INCLUDE_DIRS}")

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

#include_directories(${GTEST_INCLUDE_DIRS})


################################
# Testing
################################
#MESSAGE(STATUS "${test}")
#if (test)
#    add_executable(${PROJECT_NAME} test.cpp)
#else()
    # Create the executable

#target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
add_subdirectory(lib/mongoose-cpp)
include_directories(lib/mongoose-cpp)
add_subdirectory(test)

add_executable(${PROJECT_NAME}
        main.cpp
        src/models/Transaction.cpp
        src/models/Transaction.h
        src/models/TransactionBook.cpp
        src/models/TransactionBook.h
        src/api/Database.cpp
        src/api/Database.h
        src/api/DataImport.cpp
        src/api/DataImport.h
        src/api/ApiHandler.cpp
        src/api/ApiHandler.h)

FIND_LIBRARY(SQLITE3_LIBRARY NAMES sqlite3)
find_package (SQLite3 REQUIRED)
if (SQLITE3_FOUND)
    include_directories(${SQLITE3_INCLUDE_DIRS})
    target_link_libraries (${PROJECT_NAME} ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)

target_link_libraries(${PROJECT_NAME}
        gtest_main
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY})
target_link_libraries(${PROJECT_NAME} mongoose)


#endif()

