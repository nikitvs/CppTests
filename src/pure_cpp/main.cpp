#include <gtest/gtest.h>

class Environment final : public testing::Environment
{
public:
    // Настроить все тесты
    void SetUp() override
    {
        // Отображать bool как строку
        std::cout << std::boolalpha;
    }
};


int main(int argc, char** argv)
{
    // Настроить окружение для тестов
    testing::AddGlobalTestEnvironment(new Environment);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
