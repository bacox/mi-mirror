set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.5.1)
project(money_insight)


#-lboost_system


# Create the executable
add_executable(${PROJECT_NAME}
        main.cpp
        api/Transaction.cpp
        api/Transaction.h)