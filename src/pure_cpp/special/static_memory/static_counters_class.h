#ifndef STATIC_COUNTERS_CLASS_H
#define STATIC_COUNTERS_CLASS_H

/// \details Класс сатических счетчиков с различным размещением definition
/// как самих счетчиков, так и методов взаимодействия с ними.
/// Здесь будут использованы следующие маркеры:
///     - cpp_definition (Internal implementation) - определение (поля или метода) является ДЕТАЛЬЮ РЕАЛИЗАЦИИ библиотеки
///        - h_definition (Visible implementation) - определение (поля или метода) является ВИДИМОЙ частью интерфейса библиотеки
class StaticCountersClass
{
public:
    /// \brief cpp_definition инкремент для iCounter
    static int iCounterIncrement();

    /// \brief h_definition инкремент для vCounter
    static int vCounterIncrement()
    {
        return ++vCounter;
    }

    /// \brief cpp_definition инкремент для inlineICounter
    static int inlineICounterIncrement();

    /// \brief h_definition инкремент для inlineVCounter
    static int inlineVCounterIncrement()
    {
        return ++inlineVCounter;
    }


    /// \brief cpp_definition геттер для iCounter
    static int getICounter();

    /// \brief cpp_definition геттер для vCounter
    static int getVCounter();

    /// \brief cpp_definition геттер для inlineICounter
    static int getInlineICounter();

    /// \brief cpp_definition геттер для inlineVCounter
    static int getInlineVCounter();


    /// \brief h_definition геттер для iCounter
    static int visibleGetICounter()
    {
        return iCounter;
    }

    /// \brief h_definition геттер для vCounter
    static int visibleGetVCounter()
    {
        return vCounter;
    }

    /// \brief h_definition геттер для inlineICounter
    static int visibleGetInlineICounter()
    {
        return inlineICounter;
    }

    /// \brief h_definition геттер для inlineVCounter
    static int visibleGetInlineVCounter()
    {
        return inlineVCounter;
    }

private:
    /// \brief Статический cpp_definition счетчик с cpp_definition реализацией инкремента
    static int iCounter;

    /// \brief Статический cpp_definition счетчик с h_definition реализацией инкремента
    static int vCounter;

    /// \brief Статический h_definition inline счетчик с cpp_definition реализацией инкремента
    static inline int inlineICounter = 0;

    /// \brief Статический h_definition inline счетчик с h_definition реализацией инкремента
    static inline int inlineVCounter = 0;
};

#endif // STATIC_COUNTERS_CLASS_H
