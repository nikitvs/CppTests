#include <iostream>

#include <gtest/gtest.h>

TEST(Templates, Decltype_1)
{
    // Переменная
    int a = 1;

    // Переменная типа decltype от имени переменной
    decltype(a) b = a;

    // Переменная типа decltype от выражения
    decltype((a)) c = a;

    std::cout << "-" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "-" << std::endl;
    std::cout << "Decltype от имени это тип, с которым было объявлено имя. Поэтому decltype(a) это int." << std::endl;
    std::cout << "Decltype от lvalue выражения это тип выражения + '&'. Поэтому decltype((a)) это int&." << std::endl;
    std::cout << "Поэтому в данном примере переменная c изменилась вместе с a. A b осталось как было." << std::endl;
    std::cout << "-" << std::endl;
}
