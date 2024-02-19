
#include<iostream>

#include "Temperature.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestInitalization( const Temperature &temp );
void TestReading( const Temperature &temp, const float &measurement, const string &title, const string &subTitle );

int main()
{
    float tempReading = 11.11;
    float newReading = 22.22;
    Temperature myTemp;
    Temperature paramTemp( tempReading );

    TestInitalization( myTemp );
    TestReading( paramTemp, tempReading, "Test on Parametrized Constructor", "Constructed temperature Object set as 11.11" );

    paramTemp.SetMeasurement( newReading );
    TestReading( paramTemp, newReading, "Test on Setting temperature measurement", "Constructed temperature Object set as 22.22" );

    return 0;
}

void Assert( bool condition, const string &message )
{
    if( condition )
    {
        cout << "\t[ PASS ] " << message << endl;
    }
    else
    {
        cout << "\t[ FAIL ] " << message << endl;
    }
}

void TestInitalization( const Temperature &temp )
{
    cout << "Test on Default Constructor" << endl;
    Assert( temp.GetMeasurement() == 0.0, "Default temperature Object set as 0.0" );
    cout << endl;
}

void TestReading( const Temperature &temp, const float &measurement, const string &title, const string &subTitle )
{
    cout << title << endl;
    Assert( temp.GetMeasurement()== measurement, subTitle );
    cout << endl;
}


