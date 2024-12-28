#include <gtest/gtest.h>

// Метод печати свойств для типа данных
template <class T>
void showTypePars(const std::string& type)
{
    std::cout << "type: " << type << std::endl;
    std::cout << "is const: " << std::is_const_v<std::remove_pointer_t<std::remove_reference_t<T>>> << std::endl;
    std::cout << "is pointer: " << std::is_pointer_v<std::remove_reference_t<T>> << std::endl;
    std::cout << "is lvalue ref: " << std::is_lvalue_reference_v<T> << std::endl;
    std::cout << "is rvalue ref: " << std::is_rvalue_reference_v<T> << std::endl;
    std::cout << "-" << std::endl;
}

TEST(Templates, DecltypeFromName)
{
    std::cout << "-" << std::endl;
    std::cout << "Decltype от имени - это тип, с которым было объявлено имя" << std::endl;
    std::cout << "-" << std::endl;

    // Исходная переменная
    int a = 0;

    {
        showTypePars<decltype(a)>("decltype от 'a', где a : 'int a = 0;'");
    }

    // const
    {
        [[maybe_unused]] const int var = a;
        showTypePars<decltype(var)>("decltype от 'var', где var : 'const int var = a;'");
    }

    // &
    {
        [[maybe_unused]] int& var = a;
        showTypePars<decltype(var)>("decltype от 'var', где var : 'int& var = a;'");
    }

    // const &
    {
        [[maybe_unused]] const int& var = a;
        showTypePars<decltype(var)>("decltype от 'var', где var : 'const int& var = a;'");
    }

    // &&
    {
        [[maybe_unused]] int&& var = std::move(a);
        showTypePars<decltype(var)>("decltype от 'var', где var : 'int&& var = std::move(a);'");
    }

    // const &&
    {
        [[maybe_unused]] const int&& var = std::move(a);
        showTypePars<decltype(var)>("decltype от 'var', где var : 'const int&& var = std::move(a);'");
    }

    // *
    {
        [[maybe_unused]] int* var = &a;
        showTypePars<decltype(var)>("decltype от 'var', где var : 'int* var = &a;'");
    }

    // const *
    {
        [[maybe_unused]] const int* var = &a;
        showTypePars<decltype(var)>("decltype от 'var', где var : 'const int* var = &a;'");
    }
}

TEST(Templates, DecltypeFromExpression)
{
    std::cout << "-" << std::endl;
    std::cout << "Decltype от expression:" << std::endl;
    std::cout << " - decltype(lvalue) - это тип выражения + левая ссылка" << std::endl;
    std::cout << " - decltype(xvalue) - это тип выражения + прававя ссылка" << std::endl;
    std::cout << " - decltype(prvalue) - это тип выражения" << std::endl;
    std::cout << "-" << std::endl;

    // Исходная переменная
    int a = 0;

    std::cout << " === lvalue expression ===" << std::endl;
    std::cout << "-" << std::endl;

    showTypePars<decltype((a))>("decltype от '(a)', где a : 'int a = 0;'");

    {
        [[maybe_unused]] int& var = a;
        showTypePars<decltype((var))>("decltype от '(var)', где var : 'int& var = a;'");
    }

    {
        [[maybe_unused]] int&& var = std::move(a);
        showTypePars<decltype((var))>("decltype от '(var)', где var : 'int&& var = std::move(a);'");
    }

    {
        int* pa;
        [[maybe_unused]] int*& var = pa;
        showTypePars<decltype((var))>("decltype от '(var)', где var : 'int*& var = pa;'");
    }

    {
        [[maybe_unused]] int arr[1];
        showTypePars<decltype(arr[0])>("decltype от 'arr[0]', где arr : 'int arr[1];'");
    }

    // Строковая литерала по умолчанию имеет тип "массив char" и представляет собой lvalue expression
    showTypePars<decltype("string literal")>("decltype от \"string literal\"");

    std::cout << " === xvalue expression ===" << std::endl;
    std::cout << "-" << std::endl;

    showTypePars<decltype(std::move(a))>("decltype от 'std::move(a)', где a : 'int a = 0;'");

    std::cout << " === prvalue expression ===" << std::endl;
    std::cout << "-" << std::endl;

    showTypePars<decltype(a + 1)>("decltype от 'a + 1'");
}
