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
    ~DateClass() { delete date; }

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
    int *temp = (int *)the_master->date;
    bool res = *temp >> pos;
    return res & 1;
}

int main()
{
    DateClass z(7, 9, 10, 2);
    for (int i = 0; i < 32; i++)
    {
        printf("%d\n", (bool)z[i]);
    }

    return 0;
}