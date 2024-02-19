
#include<iostream>
#include<string>

#include "Date.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestInitialization( Date &date );
void TestParameterizedConstructor( Date &date );
void TestSettingDayOfDate( Date &date );
void TestSettingMonthOfDate( Date &date );
void TestSettingYearOfDate( Date &date );
void TestGetMonthIntoString( Date &date );



int main()
{
    Date myDate;
    Date paramDate(11,12,2002);

    TestInitialization( myDate );
    TestParameterizedConstructor( paramDate );
    TestSettingDayOfDate( myDate );
    TestSettingMonthOfDate( myDate );
    TestSettingYearOfDate( myDate );
    TestGetMonthIntoString( myDate );

    return 0;
}

void Assert( bool condition, const string &message )
{
    if( condition )
    {
        cout << "\t[ PASS ] " <<  message << endl;
    }
    else
    {
        cout << "\t[ FAIL ] " << message << endl;
    }
}

void TestInitialization( Date &date )
{
    cout << "Test on initializing a default date: " << endl;
    Assert( date.GetDay() == 0, "Default constructor day of a date is 0" );
    Assert( date.GetMonth() == 0, "Default constructor month of a date is 0" );
    Assert( date.GetYear() == 0, "Default constructor year of a date is 0" );
}

void TestParameterizedConstructor( Date &date )
{
    cout << "\nTest on parameterized constructor date: " << endl;
    Assert( date.GetDay() == 11, "Default constructor day of a date is 11" );
    Assert( date.GetMonth() == 12, "Default constructor month of a date is 12" );
    Assert( date.GetYear() == 2002, "Default constructor year of a date is 2002" );
}

void TestSettingDayOfDate( Date &date )
{
    cout << "\nTest on setting day of a date: " << endl;
    date.SetDay(1);
    Assert( date.GetDay() == 1, "Setting day of a date to 1" );
}

void TestSettingMonthOfDate( Date &date )
{
    cout << "\nTest on setting month of a date: " << endl;
    date.SetMonth(2);
    Assert( date.GetMonth() == 2, "Setting month of a date to 2" );
}

void TestSettingYearOfDate( Date &date )
{
    cout << "\nTest on setting year of a date: " << endl;
    date.SetYear( 2021 );
    Assert( date.GetYear() == 2021, "Setting year of a date to 2021" );
}

void TestGetMonthIntoString( Date &date )
{
    cout << "\nTest on converting numeric month to string month: " << endl;
    Assert( date.GetMonthInStr( date.GetMonth() )=="February", "Converting month to February" );
}
