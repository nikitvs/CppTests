# Собрать СТАТИЧЕСКУЮ библиотку статических счетчиков
add_library("CountersStaticLib" STATIC  static_counters_class.cpp
                                        static_counters_class.h)

# Собрать РАЗДЕЛЯЕМУЮ библиотку статических счетчиков
add_library("CountersSharedLib" SHARED  static_counters_class.cpp
                                        static_counters_class.h)

# Создать исполняемый файл и подключить СТАТИЧЕСКУЮ библиотеку
add_executable("TestStatic" test_static.cpp)
target_link_libraries("TestStatic" PRIVATE "CountersStaticLib")

# Создать исполняемый файл и подключить РАЗДЕЛЯЕМУЮ библиотеку
add_executable("TestShared" test_shared.cpp)
target_link_libraries("TestShared" PRIVATE "CountersSharedLib")
