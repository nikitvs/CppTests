cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Определить проект
project(CppTests
        VERSION 0.0.1
        DESCRIPTION "Исследование возможностей и особенностей C++"
        LANGUAGES CXX)

# Подключить модули
add_subdirectory(modules/BuildToolkit)
add_subdirectory(modules/googletest)

# Глобально подключить таргет гугл тестов
link_libraries(gtest_main)

# Подключить исходники
add_subdirectory(src)
