#include <gtest/gtest.h>

// Шаблонная функция, принимающая lvalue
template <class T>
void foo(const T& arg)
{
    std::cout << "foo lvalue: " << arg << std::endl;
    std::cout << "-" << std::endl;
}

// Шаблонная функция, принимающая rvalue
template <class T>
// Благодаря уточнению через const ломается контекст вывода типов
// (здесь это нужно, чтобы обрабатывать только xvalue и prvalue)
void foo(const T&& arg)
{
    std::cout << "foo rvalue: " << arg << std::endl;
    std::cout << "-" << std::endl;
}

// Прозрачная оболочка для одного аргумента
template <class T>
void transparent(T&& arg)
{
    foo(std::forward<T>(arg));
}

TEST(Templates, PerfectForwarding)
{
    std::cout << "-" << std::endl;

    {
        const std::string str = "lvalue string";
        transparent(str);
    }

    {
        const std::string str = "xvalue string";
        transparent(std::move(str));
    }

    transparent(std::string{"prvalue string"});

    // Строковая литерала по умолчанию имеет тип массив char и представляет собой lvalue expression
    transparent("implicit const char[N]");
}
