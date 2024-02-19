
#include "WindRecType.h"

WindRecType::WindRecType()
{
    m_date              = Date();
    m_time              = Time();
    m_windSpeed         = WindSpeed();
    m_solarRadiation    = SolarRadiation();
    m_temperature       = Temperature();
}

WindRecType::WindRecType( const Date &date,
                          const Time &time,
                          const WindSpeed &windSpeed,
                          const SolarRadiation &solarRadiation,
                          const Temperature &temperature )
{
    m_date              = date;
    m_time              = time;
    m_windSpeed         = windSpeed;
    m_solarRadiation    = solarRadiation;
    m_temperature       = temperature;
}

Date WindRecType::GetRecordDate() const
{
    return m_date;
}

Time WindRecType::GetRecordTime() const
{
    return m_time;
}

WindSpeed WindRecType::GetRecordWindSpeed() const
{
    return m_windSpeed;
}

SolarRadiation WindRecType::GetRecordSolarRadiation() const
{
    return m_solarRadiation;
}

Temperature WindRecType::GetRecordTemperature() const
{
    return m_temperature;
}

void WindRecType::SetRecordDate( const Date &date )
{
    m_date = date;
}

void WindRecType::SetRecordTime( const Time &time )
{
    m_time = time;
}

void WindRecType::SetRecordWindSpeed( const WindSpeed &windSpeed )
{
    m_windSpeed = windSpeed;
}

void WindRecType::SetRecordSolarRadiation( const SolarRadiation &solarRadiation )
{
    m_solarRadiation = solarRadiation;
}

void WindRecType::SetRecordTemperature( const Temperature &temperature )
{
    m_temperature = temperature;
}

ostream &operator << ( ostream &output, const WindRecType &WRT )
{
    output  << WRT.GetRecordDate()              << " "
            << WRT.GetRecordTime()              << " "
            << WRT.GetRecordWindSpeed()         << " "
            << WRT.GetRecordSolarRadiation()    << " "
            << WRT.GetRecordTemperature();

    return output;
}

istream &operator >> ( istream &input, WindRecType &WRT )
{
    Date            tempDate;
    Time            tempTime;
    WindSpeed       tempWindSpeed;
    SolarRadiation  tempSolarRadiation;
    Temperature     tempTemperature;

    input >> tempDate >> tempTime >> tempWindSpeed >> tempSolarRadiation >> tempTemperature;

    WRT.SetRecordDate           ( tempDate );
    WRT.SetRecordTime           ( tempTime );
    WRT.SetRecordWindSpeed      ( tempWindSpeed );
    WRT.SetRecordSolarRadiation ( tempSolarRadiation );
    WRT.SetRecordTemperature    ( tempTemperature );

    return input;
}
