project(money_insight)


#-lboost_system


# Create the executable
add_executable(${PROJECT_NAME}
        main.cpp
        api/transaction.cpp
        api/transaction.h)