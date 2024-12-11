#include <iostream>

#include <gtest/gtest.h>

#include "static_counters_class.h"

TEST(StaticMemorySharedLib, CppDefCounterCppDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "cpp_definition counter cpp_definition increment: " << StaticCountersClass::iCounterIncrement() << std::endl;
    std::cout << "cpp_definition counter cpp_definition getter: " << StaticCountersClass::getICounter() << std::endl;
    std::cout << "cpp_definition counter h_definition getter: " << StaticCountersClass::visibleGetICounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "Благодаря cpp_definition реализации статического счетчика внутри '.so' библиотеки не имеет значения расположение реализации инкремента и геттеров." << std::endl
              << "Статическая память счетчика была выделена единожды внутри адресного пространства разделяемой библиотеки." << std::endl
              << "И любая операция модификации или чтения (cpp/h_definition) приводит к взаимодействию с этим единственным экземпляром статической памяти." << std::endl;
    std::cout << "-" << std::endl;
}

TEST(StaticMemorySharedLib, CppDefCounterHDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "cpp_definition counter h_definition increment: " << StaticCountersClass::vCounterIncrement() << std::endl;
    std::cout << "cpp_definition counter cpp_definition getter: " << StaticCountersClass::getVCounter() << std::endl;
    std::cout << "cpp_definition counter h_definition getter: " << StaticCountersClass::visibleGetVCounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "См. комментарий к тесту 'CppDefCounterCppDefIncrement'" << std::endl;
    std::cout << "-" << std::endl;
}

TEST(StaticMemorySharedLib, HDefCounterCppDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "h_definition inlineCounter cpp_definition increment: " << StaticCountersClass::inlineICounterIncrement() << std::endl;
    std::cout << "h_definition inlineCounter cpp_definition getter: " << StaticCountersClass::getInlineICounter() << std::endl;
    std::cout << "h_definition inlineCounter h_definition getter: " << StaticCountersClass::visibleGetInlineICounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "Из-за inline h_definition реализации статического счетчика, память под него выделяется в каждом компоненте программы ('.so' + 'exe')." << std::endl
              << "По этой причине имеет значения какого рода definition у взаимодействующего с данной памятью метода." << std::endl
              << "В данном случае cpp_definition инкремент и геттер взимодействуют с памятью внутри разделяемой библиотеки." << std::endl
              << "А h_definition геттер прочитал значение из нетронутой памяти внутри исполняемого файла." << std::endl;
    std::cout << "-" << std::endl;
}

TEST(StaticMemorySharedLib, HDefCounterHDefIncrement)
{
    std::cout << "-" << std::endl;
    std::cout << "h_definition inlineCounter h_definition increment: " << StaticCountersClass::inlineVCounterIncrement() << std::endl;
    std::cout << "h_definition inlineCounter cpp_definition getter: " << StaticCountersClass::getInlineVCounter() << std::endl;
    std::cout << "h_definition inlineCounter h_definition getter: " << StaticCountersClass::visibleGetInlineVCounter() << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "Из-за inline h_definition реализации статического счетчика, память под него выделяется в каждом компоненте программы ('.so' + 'exe')." << std::endl
              << "По этой причине имеет значения какого рода definition у взаимодействующего с данной памятью метода." << std::endl
              << "В данном случае h_definition инкремент и геттер взимодействуют с памятью внутри исполняемого файла." << std::endl
              << "А cpp_definition геттер прочитал значение из нетронутой памяти внутри разделяемой библиотеки." << std::endl;
    std::cout << "-" << std::endl;
}
