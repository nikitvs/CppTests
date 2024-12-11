cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(PureCppTests
        VERSION 0.0.1
        DESCRIPTION "Исследование возможностей чистого C++"
        LANGUAGES CXX)

# Настройки c++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Задать имя таргета
set(TARGET_NAME "PureCppTests")

add_executable("${TARGET_NAME}")

# Подключить модуль функций работы с исходниками
include(sources_functions)

# Назначить исходники таргету (кроме директории особой сборки)
assign_sources_to_target(TARGET "${TARGET_NAME}" EXCLUSIVE_REGEXP "special/*")

# Подключить папку с экземплярами, требующими особой сборки
add_subdirectory(special)
