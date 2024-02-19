
#include<iostream>

#include "WindSpeed.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestInitialization( const WindSpeed &WS );
void TestParameterizedConstructor( const WindSpeed &WS, const float &speed );
void SettingWindSpeedMeasurement( const WindSpeed &WS, const float &reading );

int main()
{
    float speed = 12.12;
    float newSpeed = 24.35;
    WindSpeed windSpeed;
    WindSpeed paramWindSpeed(speed);

    TestInitialization( windSpeed );
    TestParameterizedConstructor( paramWindSpeed, speed );

    paramWindSpeed.SetMeasurement( newSpeed );
    SettingWindSpeedMeasurement( paramWindSpeed, newSpeed );


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

void TestInitialization( const WindSpeed &WS )
{
    cout << "Test on Default WindSpeed Object" << endl;
    Assert( WS.GetMeasurement()==0.0, "Default WindSpeed Object Measurement set as 0.0" );
    cout << endl;
}

void TestParameterizedConstructor( const WindSpeed &WS, const float &reading )
{
    cout << "Test on Parameterized Constructed WindSpeed Object" << endl;
    Assert( WS.GetMeasurement()==reading, "Constructed WindSpeed Object Measurement set as 12.12" );
    cout << endl;
}

void SettingWindSpeedMeasurement( const WindSpeed &WS, const float &reading )
{
    cout << "Test on Parameterized Constructed WindSpeed Object" << endl;
    Assert( WS.GetMeasurement()== reading, "New Speed set as 24.35" );
    cout << endl;
}
