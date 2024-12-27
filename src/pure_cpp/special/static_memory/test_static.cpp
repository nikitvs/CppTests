#include <gtest/gtest.h>

#include "static_counters_class.h"

TEST(StaticMemoryStaticLib, CppDefCounterCppDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "cpp_definition counter cpp_definition increment: " << StaticCountersClass::iCounterIncrement() << std::endl;
    std::cout << "cpp_definition counter cpp_definition getter: " << StaticCountersClass::getICounter() << std::endl;
    std::cout << "cpp_definition counter h_definition getter: " << StaticCountersClass::visibleGetICounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "В отличии от разделяемой библиотеки статическая библиотека не может обладать своим собственным экземпляром статической памяти." << std::endl;
    std::cout << "Код такой библиотеки становится частью итогового компонента программы (файла '.so' или 'exe')." << std::endl;
    std::cout << "По этой причине расположеие definition для статической памяти и методов взаимодействия с ней не имеет значения в случае одного компонента программы." << std::endl;
    std::cout << "Расположеие definition начинает иметь значение, когда статическая библиотека линкуется одновременно несколькими компонентами программы." << std::endl;
    std::cout << "В данном тесте присутствует только один компонент - исполняемый файл, поэтому работа производится только с одним экземпляром памяти." << std::endl;
    std::cout << "-" << std::endl;
}

TEST(StaticMemoryStaticLib, CppDefCounterHDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "cpp_definition counter h_definition increment: " << StaticCountersClass::vCounterIncrement() << std::endl;
    std::cout << "cpp_definition counter cpp_definition getter: " << StaticCountersClass::getVCounter() << std::endl;
    std::cout << "cpp_definition counter h_definition getter: " << StaticCountersClass::visibleGetVCounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "См. комментарий к тесту 'CppDefCounterCppDefIncrement'" << std::endl;
    std::cout << "-" << std::endl;
}

TEST(StaticMemoryStaticLib, HDefCounterCppDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "h_definition inlineCounter cpp_definition increment: " << StaticCountersClass::inlineICounterIncrement() << std::endl;
    std::cout << "h_definition inlineCounter cpp_definition getter: " << StaticCountersClass::getInlineICounter() << std::endl;
    std::cout << "h_definition inlineCounter h_definition getter: " << StaticCountersClass::visibleGetInlineICounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "См. комментарий к тесту 'CppDefCounterCppDefIncrement'" << std::endl;
    std::cout << "-" << std::endl;
}

TEST(StaticMemoryStaticLib, HDefCounterHDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "h_definition inlineCounter h_definition increment: " << StaticCountersClass::inlineVCounterIncrement() << std::endl;
    std::cout << "h_definition inlineCounter cpp_definition getter: " << StaticCountersClass::getInlineVCounter() << std::endl;
    std::cout << "h_definition inlineCounter h_definition getter: " << StaticCountersClass::visibleGetInlineVCounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "См. комментарий к тесту 'CppDefCounterCppDefIncrement'" << std::endl;
    std::cout << "-" << std::endl;
}
