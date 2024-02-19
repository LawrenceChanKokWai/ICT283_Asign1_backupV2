
#include<iostream>

#include "SolarRadiation.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestInitalization( const SolarRadiation &solarRadiation );
void TestReading(
    const SolarRadiation &solarRadiation,
    const float &measurement,
    const string &title,
    const string &subTitle );


int main()
{
    float tempReading = 11.11;
    float newReading = 22.22;
    SolarRadiation solarRadiation;
    SolarRadiation paramSolarRadiation( tempReading );

    TestInitalization( solarRadiation );
    TestReading( paramSolarRadiation,
                 tempReading,
                 "Test On Parameterized Constructor",
                 "Test on measurement set as 11.11" );

    paramSolarRadiation.SetMeasurement( newReading );
    TestReading( paramSolarRadiation,
                 newReading,
                 "Test On SetMeasurement to a SolarRadiation Object",
                 "Test on setting measurement set as 22.22" );

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

void TestInitalization( const SolarRadiation &solarRadiation )
{
    cout << "Test on Default Constructor" << endl;
    Assert( solarRadiation.GetMeasurement() == 0.0, "Default solar radiation Object set as 0.0" );
    cout << endl;
}

void TestReading( const SolarRadiation &solarRadiation, const float &measurement, const string &title, const string &subTitle )
{
    cout << title << endl;
    Assert( solarRadiation.GetMeasurement()== measurement, subTitle );
    cout << endl;
}

