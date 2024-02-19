///
/// @file Date.h
/// @brief Date class definition.
///
/// This file contains the definition of the Date class, which represents the date.
/// The class allows setting and retrieving the day, month, and year associated with the date.
/// It also overloads stream operators for input and output to facilitate I/O operations.
///
/// @author Chan Kok Wai ( Student Number: 33924804 )
/// @version 1.0
///
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<iostream>

using namespace std;

class Date
{
public:

    ///
    /// @brief Default constructor for Date class.
    ///
    /// This constructor creates a Date object with default values for day, month, and year attributes that is set as 0.
    ///
    Date();

    ///
    /// @brief Parameterized Constructor For The Date Class
    ///
    /// This constructor creates a Date Class with user defined values for the day, month, and year as parameters.
    ///
    /// @param day The day associated with the date.
    /// @param month The month associated with the date.
    /// @param year The year associated with the date.
    ///
    Date(const unsigned &day, const unsigned &month, const unsigned &year);

    ///
    /// @brief Method that allows retrieving the day that is associated with the Date class.
    ///
    /// @return unsigned data type of the day associated with the date.
    ///
    unsigned GetDay() const;

    ///
    /// @brief Method that allows retrieving the month that is associated with the Date class.
    ///
    /// @return unsigned data type of the month associated with the date.
    ///
    unsigned GetMonth() const;

    ///
    /// @brief Method that allows retrieving the year that is associated with the Date class.
    ///
    /// @return unsigned data type of the year associated with the date.
    unsigned GetYear() const;

    ///
    /// @brief Method that allows setting the day associated with the Date class.
    ///
    /// @param day referenced day with the Date class.
    ///
    void SetDay(const unsigned &day);

    ///
    /// @brief Method that allows setting the month associated with the Date class.
    ///
    /// @param month referenced month with the Date class.
    ///
    void SetMonth(const unsigned &month);

    ///
    /// @brief Method that allows setting the year associated with the Date class.
    ///
    /// @param year referenced year with the Date class.
    ///
    void SetYear(const unsigned &year);

    ///
    /// @brief Method that allows retrieving the month in string with the Date class.
    ///
    /// @param month referencing the month in string.
    ///
    string GetMonthInStr(const unsigned &month) const;

private:
    unsigned INITIAL_VALUE = 0;

    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
};

///
/// @brief Function: Overloaded stream insertion operator for Date class.
///
/// This allows a Date object to be printed to an output stream using the standard output format.
/// The day (unsigned data type), month (string data type), and year (unsigned data type) will be printed.
///
/// @param outputStream The output stream where the Date object will be printed.
/// @param D The Date object to be printed.
/// @return A reference to the output stream after printing the Date object.
///
ostream &operator << (ostream &outputStream, const Date &D);

///
/// @brief Function: Overloaded stream extraction operator for Date class.
///
/// This allows a Date object to be read from an input stream using the standard input format.
/// The input should contain the day (unsigned data type), month (unsigned data type), and year (unsigned data type).
///
/// @param inputStream The input stream from which the Date object will be read.
/// @param D The Date object where the read information will be stored.
/// @return A reference to the input stream after setting the Date object.
///
istream &operator >> (istream &inputStream , Date &D);

#endif // DATE_H_INCLUDED
