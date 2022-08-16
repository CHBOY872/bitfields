#include <stdio.h>
#include "Date.hpp"

int main()
{
    Date str(2, 5, 6, 9);

    printf("%d %d %d %d\n", str.GetnMonth(), str.GetnMonthDay(),
           str.GetnWeekDay(), str.GetnYear());

    str.ResetBitInYear(3);
    str.InvertBitInMonthDay(2);
    str.SetBitInMonth(3);

    printf("%d %d %d %d\n", str.GetnMonth(), str.GetnMonthDay(),
           str.GetnWeekDay(), str.GetnYear());

    return 0;
}