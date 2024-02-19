#include "Date.h"

Date::Date()
{
    m_day = INITIAL_VALUE;
    m_month = INITIAL_VALUE;
    m_year = INITIAL_VALUE;
}

Date::Date(const unsigned &day, const unsigned &month, const unsigned &year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

unsigned Date::GetDay() const
{
    return m_day;
}

unsigned Date::GetMonth() const
{
    return m_month;
}

unsigned Date::GetYear() const
{
    return m_year;
}

void Date::SetDay(const unsigned &day)
{
    m_day = day;
}

void Date::SetMonth(const unsigned &month)
{
    m_month = month;
}

void Date::SetYear(const unsigned &year)
{
    m_year = year;
}

string Date::GetMonthInStr(const unsigned &month) const
{
    string strInMonth;
    switch(month)
    {
    case 1:
        strInMonth = "January";
        break;
    case 2:
        strInMonth = "February";
        break;
    case 3:
        strInMonth = "March";
        break;
    case 4:
        strInMonth = "April";
        break;
    case 5:
        strInMonth = "May";
        break;
    case 6:
        strInMonth = "June";
        break;
    case 7:
        strInMonth = "July";
        break;
    case 8:
        strInMonth = "August";
        break;
    case 9:
        strInMonth = "September";
        break;
    case 10:
        strInMonth = "October";
        break;
    case 11:
        strInMonth = "November";
        break;
    case 12:
        strInMonth = "December";
        break;
    default:
        strInMonth = "Error";
        break;
    }
    return strInMonth;
}

ostream &operator << (ostream &outputStream, const Date &D)
{
    outputStream << D.GetDay() << " "
                                << D.GetMonthInStr(D.GetMonth()) << " "
                                << D.GetYear();

    return outputStream;
}

istream &operator >> (istream &inputStream, Date &D)
{
    string tempField = "";

    getline(inputStream, tempField, '/');
    D.SetDay(stoi(tempField));

    getline(inputStream, tempField, '/');
    D.SetMonth(stoi(tempField));

    getline(inputStream, tempField, ' ');
    D.SetYear(stoi(tempField));

    return inputStream;
}
