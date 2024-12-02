cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Определить проект
project(CppTests
        VERSION 0.0.1
        DESCRIPTION "Исследование возможностей и особенностей C++"
        LANGUAGES CXX)

# Подключить модули
add_subdirectory(modules/BuildToolkit)
add_subdirectory(modules/googletest)

# Подключить исходники
add_subdirectory(src)
