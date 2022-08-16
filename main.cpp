#include <stdio.h>
#include <stdlib.h>

struct DateStruct
{
    unsigned short nWeekDay : 3;
    unsigned short nMonthDay : 6;
    unsigned short nMonth : 5;
    unsigned short nYear : 8;
};
class DateClass;
class DateClassCursor
{
    DateClass *the_master;
    unsigned pos : 8;

public:
    DateClassCursor(DateClass *_the_master, unsigned _pos = 0)
        : the_master(_the_master), pos(_pos) {}
    DateClassCursor &operator=(bool i);
    operator bool();
};

class DateClass
{
    friend class DateClassCursor;
    DateStruct *date;

public:
    DateClass(unsigned _nWeekDay = 0, unsigned _nMonthDay = 0,
              unsigned _nMonth = 0, unsigned _nYear = 0)
        : date(new DateStruct)
    {
        date->nWeekDay = _nWeekDay;
        date->nMonthDay = _nMonthDay;
        date->nMonth = _nMonth;
        date->nYear = _nYear;
    }

    void SetnWeekDay(unsigned _nWeekDay) { date->nWeekDay = _nWeekDay; }
    void SetnMonthDay(unsigned _nMonthDay) { date->nMonthDay = _nMonthDay; }
    void SetnMonth(unsigned _nMonth) { date->nMonth = _nMonth; }
    void SetnYear(unsigned _nYear) { date->nYear = _nYear; }

    unsigned GetnWeekDay() { return date->nWeekDay; }
    unsigned GetnMonthDay() { return date->nMonthDay; }
    unsigned GetnMonth() { return date->nMonth; }
    unsigned GetnYear() { return date->nYear; }

    DateClassCursor operator[](unsigned int idx)
    {
        return DateClassCursor(this, idx);
    }
};

DateClassCursor::operator bool()
{
    unsigned int *ptr = (unsigned int *)the_master->date;
    unsigned int bit = *ptr >> pos;
    return bit & 1;
}

DateClassCursor &DateClassCursor::operator=(bool i)
{
    unsigned int *ptr = (unsigned int *)the_master->date;
    unsigned int mask = i << pos;
    if (!i)
    {
        mask = !mask;
        *ptr &= mask;
    }
    else
        *ptr |= mask;
    return *this;
}

int main()
{
    DateClass str(0, 0, 0, 0);
    unsigned int *ptr = (unsigned int *)&str;
    for (int i = 0; i < 32; i++)
    {
        str[i] = 1;
        printf("%d\n", (bool)str[i]);
    }
    str.SetnMonthDay(0);
    printf("%d %d %d %d\n", str.GetnMonth(), str.GetnMonthDay(),
           str.GetnWeekDay(), str.GetnYear());
    return 0;
}