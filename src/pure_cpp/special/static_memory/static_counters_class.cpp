#include "static_counters_class.h"

// Definition НЕ-inline статических полей
int StaticCountersClass::iCounter = 0;
int StaticCountersClass::vCounter = 0;

int StaticCountersClass::iCounterIncrement()
{
    return ++iCounter;
}

int StaticCountersClass::inlineICounterIncrement()
{
    return ++inlineICounter;
}

int StaticCountersClass::getICounter()
{
    return iCounter;
}

int StaticCountersClass::getVCounter()
{
    return vCounter;
}

int StaticCountersClass::getInlineICounter()
{
    return inlineICounter;
}

int StaticCountersClass::getInlineVCounter()
{
    return inlineVCounter;
}
