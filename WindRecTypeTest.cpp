
#include<iostream>

#include "WindRecType.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestDefaultConstructor( WindRecType &windRecord, const string &title );
void TestParameterizedObject( WindRecType &windRecord, const string &title, const float &wind, const float &solarRad, const float &temp );
void TestSetters( WindRecType &windRecord, const string &title, const float &wind, const float &solarRad, const float &temp );

int main()
{
    WindRecType windRecType;
    Date date(11,12,2010);
    Time time(11,22);
    float tempWindSpeed = 11.11;
    float tempSolarRadiation = 22.22;
    float tempTemperature = 33.33;
    float newWindSpeed = 22.22;
    float newSolarRadiation = 33.33;
    float newTemperature = 44.44;
    WindSpeed windSpeed(tempWindSpeed);
    SolarRadiation solarRadiation(tempSolarRadiation);
    Temperature temperature(tempTemperature);
    WindRecType paramWindRecords( date, time, windSpeed, solarRadiation, temperature );

    TestDefaultConstructor( windRecType, "Test On Default Constructor" );
    TestParameterizedObject( paramWindRecords, "Test On Parameterized Constructor", tempWindSpeed, tempSolarRadiation, tempTemperature );

    paramWindRecords.SetRecordDate(Date(22,12,2021));
    paramWindRecords.SetRecordTime(Time(12,10));
    paramWindRecords.SetRecordWindSpeed(newWindSpeed);
    paramWindRecords.SetRecordSolarRadiation(newSolarRadiation);
    paramWindRecords.SetRecordTemperature(newTemperature);
    TestSetters( paramWindRecords, "Test On Setting Date, Time, windSpeed, solarRadiation, and temperature Object", newWindSpeed, newSolarRadiation, newTemperature );

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

void TestDefaultConstructor( WindRecType &windRecord, const string &title )
{
    cout << title << endl;
    cout << '\t' << "[ Date Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetDay()==0,   "Date Object day as 0" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetMonth()==0, "Date Object month as 0" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetYear()==0,  "Date Object year as 0" );
    cout << '\t' << "[ Time Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetHour()==0,   "Time Object hour as 0" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetMinute()==0, "Time Object minute as 0" );
    cout << '\t' << "[ WindSpeed Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordWindSpeed().GetMeasurement()==0,   "WindSpeed Object measurement as 0" );
    cout << '\t' << "[ SolarRadiation Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordSolarRadiation().GetMeasurement()==0,   "SolarRadiation Object measurement as 0" );
    cout << '\t' << "[ Temperature Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTemperature().GetMeasurement()==0,   "Temperature Object measurement as 0" );
    cout << endl;
}

void TestParameterizedObject( WindRecType &windRecord, const string &title, const float &wind, const float &solarRad, const float &temp )
{
    cout << title << endl;
    cout << '\t' << "[ Date Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetDay()==11,   "Date Object day as 11" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetMonth()==12, "Date Object month as 12" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetYear()==2010,  "Date Object year as 2010" );
    cout << '\t' << "[ Time Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetHour()==11,   "Time Object hour as 11" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetMinute()==22, "Time Object minute as 22" );
    cout << '\t' << "[ WindSpeed Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordWindSpeed().GetMeasurement()==wind,   "WindSpeed Object measurement as 11.11" );
    cout << '\t' << "[ SolarRadiation Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordSolarRadiation().GetMeasurement()==solarRad,   "SolarRadiation Object measurement as 22.22" );
    cout << '\t' << "[ Temperature Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTemperature().GetMeasurement()==temp,   "Temperature Object measurement as 33.33" );
    cout << endl;
}

void TestSetters( WindRecType &windRecord, const string &title, const float &wind, const float &solarRad, const float &temp )
{
    cout << title << endl;
    cout << '\t' << "[ Date Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetDay()==22,   "Date Object day as 22" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetMonth()==12, "Date Object month as 12" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordDate().GetYear()==2021,  "Date Object year as 2021" );
    cout << '\t' << "[ Time Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetHour()==12,   "Time Object hour as 12" );
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTime().GetMinute()==10, "Time Object minute as 10" );
    cout << '\t' << "[ WindSpeed Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordWindSpeed().GetMeasurement()==wind,   "WindSpeed Object measurement as 22.22" );
    cout << '\t' << "[ SolarRadiation Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordSolarRadiation().GetMeasurement()==solarRad,   "SolarRadiation Object measurement as 33.33" );
    cout << '\t' << "[ Temperature Object ] --> " << endl;
    cout << '\t' << '\t';
    Assert( windRecord.GetRecordTemperature().GetMeasurement()==temp,   "Temperature Object measurement as 44.44" );
    cout << endl;
}


