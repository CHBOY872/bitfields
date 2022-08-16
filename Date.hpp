#ifndef DATE_HPP_SENTRY
#define DATE_HPP_SENTRY

struct DateStruct // main structure
{
    unsigned short nWeekDay : 3;
    unsigned short nMonthDay : 6;
    unsigned short nMonth : 5;
    unsigned short nYear : 8;
};
class Date;
class DateCursor // for getting bits from structure
{
    Date *the_master;
    unsigned pos : 8;

public:
    DateCursor(Date *_the_master, unsigned _pos = 0)
        : the_master(_the_master), pos(_pos) {}
    DateCursor &operator=(bool i); // overloading assignment (set 1, or 0)
    DateCursor &operator~();       // overloading negation
    operator bool();               // casting to bool
};

class Date // main class
{
    friend class DateCursor;
    DateStruct *date;

public:
    Date(unsigned _nWeekDay = 0, unsigned _nMonthDay = 0,
         unsigned _nMonth = 0, unsigned _nYear = 0)
        : date(new DateStruct)
    {
        date->nWeekDay = _nWeekDay;
        date->nMonthDay = _nMonthDay;
        date->nMonth = _nMonth;
        date->nYear = _nYear;
    }
    ~Date() { delete date; }
    /*
        set (1), reset(0), invert(from 1 to 0, from 0 to 1)
    */
    void SetBitInWeekDay(unsigned int pos);
    void ResetBitInWeekDay(unsigned int pos);
    void InvertBitInWeekDay(unsigned int pos);

    void SetBitInMonthDay(unsigned int pos);
    void ResetBitInMonthDay(unsigned int pos);
    void InvertBitInMonthDay(unsigned int pos);

    void SetBitInMonth(unsigned int pos);
    void ResetBitInMonth(unsigned int pos);
    void InvertBitInMonth(unsigned int pos);

    void SetBitInYear(unsigned int pos);
    void ResetBitInYear(unsigned int pos);
    void InvertBitInYear(unsigned int pos);

    // set own values in fields
    void SetnWeekDay(unsigned _nWeekDay) { date->nWeekDay = _nWeekDay; }
    void SetnMonthDay(unsigned _nMonthDay) { date->nMonthDay = _nMonthDay; }
    void SetnMonth(unsigned _nMonth) { date->nMonth = _nMonth; }
    void SetnYear(unsigned _nYear) { date->nYear = _nYear; }

    // get fields
    unsigned short GetnWeekDay() { return date->nWeekDay; }
    unsigned short GetnMonthDay() { return date->nMonthDay; }
    unsigned short GetnMonth() { return date->nMonth; }
    unsigned short GetnYear() { return date->nYear; }

    // get bit from structure
    DateCursor operator[](unsigned int idx)
    {
        return DateCursor(this, idx);
    }
};

#endif