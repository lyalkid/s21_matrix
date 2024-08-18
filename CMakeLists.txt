cmake_minimum_required(VERSION 3.26)
project(matrix C)

set(CMAKE_C_STANDARD 11)
# Добавить директории с заголовочными файлами
include_directories(/Users/sionapae/code/s21/C6_s21_matrix-1)
add_executable(matrix
        src/s21_matrix.c
        src/main.c
        src/helpers.c
)
# Линковка с библиотеками math и check
target_link_libraries(matrix m check)