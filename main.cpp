#include <stdio.h>

struct Date
{
    unsigned short nWeekDay : 3;
    unsigned short nMonthDay : 6;
    unsigned short nMonth : 5;
    unsigned short nYear : 8;
};

class DateClass : public Date
{

public:
    DateClass()
    {
        nWeekDay = 0;
        nMonthDay = 0;
        nMonth = 0;
        nYear = 0;
    }
    int x;
};

int main()
{
    DateClass a;
    Date x;
    a.nWeekDay = 90;
    printf("%d %d\n", a.nWeekDay, a.nMonthDay);
    return 0;
}