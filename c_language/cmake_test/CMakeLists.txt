cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Проверка компилятора и добавление флагов для GCC
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Using GCC compiler")
    add_compile_options(-Wall -Wextra -Wpedantic -O2)
endif()

# Добавляем макрос для условной компиляции
add_definitions(-DUSE_CUSTOM_MATH)

# Добавляем директории для заголовочных файлов
include_directories(include)

# Добавляем библиотеку
add_library(MathFunctions src/math_functions.cpp)

# Добавляем исполняемый файл
add_executable(MyApp src/main.cpp)

# Линкуем библиотеку с приложением
target_link_libraries(MyApp MathFunctions)