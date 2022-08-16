#include "Date.hpp"

DateCursor::operator bool()
{
    unsigned int *ptr = (unsigned int *)the_master->date;
    unsigned int bit = *ptr >> pos;
    return bit & 1;
}

DateCursor &DateCursor::operator=(bool i)
{
    unsigned int *ptr = (unsigned int *)the_master->date;
    unsigned int mask = i << pos;
    if (!i)
        *ptr &= ~mask;
    else
        *ptr |= mask;
    return *this;
}

DateCursor &DateCursor::operator~()
{
    unsigned int *ptr = (unsigned int *)the_master->date;
    unsigned int mask = 1 << pos;
    *ptr ^= mask;
    return *this;
}

void Date::SetBitInWeekDay(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nWeekDay |= mask;
}
void Date::ResetBitInWeekDay(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nWeekDay &= ~mask;
}
void Date::InvertBitInWeekDay(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nWeekDay ^= mask;
}

void Date::SetBitInMonthDay(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nMonthDay |= mask;
}
void Date::ResetBitInMonthDay(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nMonthDay &= ~mask;
}
void Date::InvertBitInMonthDay(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nMonthDay ^= mask;
}

void Date::SetBitInMonth(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nMonth |= mask;
}
void Date::ResetBitInMonth(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nMonth &= ~mask;
}
void Date::InvertBitInMonth(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nMonth ^= mask;
}

void Date::SetBitInYear(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nYear |= mask;
}
void Date::ResetBitInYear(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nYear &= ~mask;
}
void Date::InvertBitInYear(unsigned int pos)
{
    unsigned int mask = 1 << pos;
    date->nYear ^= mask;
}