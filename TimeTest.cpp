
#include<iostream>
#include<string>

#include "Time.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestInitialization( Time &time );
void TestParameterizedConstructor( Time &time );
void TestSettingHourOfTime( Time &time );
void TestSettingMinuteOfTime( Time &time );


int main()
{
    Time myTime;
    Time paramTime(11,12);

    TestInitialization( myTime );
    TestParameterizedConstructor( paramTime );
    TestSettingHourOfTime( myTime );
    TestSettingMinuteOfTime( myTime );

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

void TestInitialization( Time &time )
{
    cout << "Test on initializing a default time: " << endl;
    Assert( time.GetHour() == 0, "Default constructor hour of time is 0" );
    Assert( time.GetMinute() == 0, "Default constructor minute of a time is 0" );
}

void TestParameterizedConstructor(Time &time )
{
    cout << "\nTest on parameterized constructor time: " << endl;
    Assert( time.GetHour() == 11, "Default constructor day of a date is 11" );
    Assert( time.GetMinute() == 12, "Default constructor month of a date is 12" );
}

void TestSettingHourOfTime( Time &time )
{
    cout << "\nTest on setting hour of a time: " << endl;
    time.SetHour(1);
    Assert( time.GetHour() == 1, "Setting hour of a time to 1" );
}

void TestSettingMinuteOfTime( Time &time )
{
    cout << "\nTest on setting minute of a time: " << endl;
    time.SetMinute(20);
    Assert( time.GetMinute() == 20, "Setting minute of a time to 20" );
}
