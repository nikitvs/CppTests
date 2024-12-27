#include <gtest/gtest.h>

//template <class T>
//void bar(const T& arg)
//{
//    std::cout << "bar lvalue: " << arg << std::endl;
//}

//template <class T>
//void bar(const T&& arg)
//{
//    std::cout << "bar rvalue: " << arg << std::endl;
//}

//template <class T>
//void foo(T&& arg)
//{
////    bar(arg);
////    bar(std::move(arg));
//    bar(std::forward<T>(arg));
//}

//TEST(Templates, PerfectForwarding_1)
//{
//    std::cout << "-" << std::endl;
//    foo("rvalue string");

//    std::string a = "'std::string a'";
//    foo(a);

//    const std::string b = "'const std::string b'";
//    foo(b);

//    std::string& c = a;
//    foo(c);
//    foo(c[0]);
//}
