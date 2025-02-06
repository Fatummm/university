cmake_minimum_required(VERSION 3.10)
project(Minesweeper)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем директории для заголовочных файлов
include_directories(include)

# Добавляем библиотеку
add_library(TerminalConfig src/terminal_config.cpp)
add_library(MinesweeperFuncs src/minesweeper_funcs.cpp)
add_library(BruteforceLogic src/bruteforce.cpp)

# Добавляем исполняемый файл
add_executable(App src/main.cpp)

# Линкуем библиотеку с приложением
target_link_libraries(App TerminalConfig)
target_link_libraries(App MinesweeperFuncs)
target_link_libraries(App BruteforceLogic)

# Проверка компилятора и добавление флагов для GCC
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using G++ compiler")
    add_compile_options(-Wall -Wextra -O2)
endif()