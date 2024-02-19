#ifndef WINDRECTYPE_H_INCLUDED
#define WINDRECTYPE_H_INCLUDED

#include<iostream>
#include<string>

#include "Date.h"
#include "Time.h"
#include "WindSpeed.h"
#include "SolarRadiation.h"
#include "Temperature.h"

using namespace std;

/**
 * @class WindRecType
 * @brief Represents a wind record type with date, time, and wind speed components.
 *
 * The WindRecType class encapsulates information about a specific wind record,
 * including date, time, wind speed, solar radiation, and temperature. It provides methods to retrieve and set
 * these components.
 */
class WindRecType
{
public:

    /**
     * @brief Default constructor for the WindRecType class.
     *
     * Initializes a WindRecType object with default values.
     */
    WindRecType();

    /**
    * @brief Parameterized constructor for the WindRecType class.
    *
    * Initializes a WindRecType object with specified date, and time.
    *
    * @param[in] date The date component of the wind record.
    * @param[in] time The time component of the wind record.
    */
    WindRecType( const Date &date, const Time &time, const WindSpeed &windSpeed, const SolarRadiation &solarRadiation, const Temperature &temperature );

    /**
    * @brief Get the date component of the wind record.
    *
    * @return The date as a Date object.
    */
    Date GetRecordDate() const;

    /**
     * @brief Get the time component of the wind record.
     *
     * @return The time as a Time object.
     */
    Time GetRecordTime() const;

    /**
     * @brief Get the wind speed component of the wind record.
     *
     * @return The wind speed as a WindSpeed Measurement object.
     */
    WindSpeed GetRecordWindSpeed() const;

    /**
     * @brief Get the solar radiation component of the wind record.
     *
     * @return The solar radiation as a SolarRadiation Measurement object.
     */
    SolarRadiation GetRecordSolarRadiation() const;

    /**
     * @brief Get the temperature component of the wind record.
     *
     * @return The temperature as a Temperature Measurement object.
     */
    Temperature GetRecordTemperature() const;

    /**
     * @brief Set the date component of the wind record.
     *
     * @param[in] date The new date to set.
     */
    void SetRecordDate( const Date &date );

    /**
     * @brief Set the time component of the wind record.
     *
     * @param[in] time The new time to set.
     */
    void SetRecordTime( const Time &time );

    /**
    * @brief Set the wind speed component of the wind record.
    *
    * @param[in] windSpeed The new wind speed measurement to set.
    */
    void SetRecordWindSpeed( const WindSpeed &windSpeed );

    /**
    * @brief Set the solar radiation component of the wind record.
    *
    * @param[in] solarRadiation The new solar radiation measurement to set.
    */
    void SetRecordSolarRadiation( const SolarRadiation &solarRadiation );

    /**
    * @brief Set the temperature component of the wind record.
    *
    * @param[in] temperature The new temperature measurement to set.
    */
    void SetRecordTemperature( const Temperature &temperature );


private:
    Date m_date;                        /**< The date component of the wind record. */
    Time m_time;                        /**< The time component of the wind record. */
    WindSpeed m_windSpeed;              /**< The wind speed component of the wind record. */
    SolarRadiation m_solarRadiation;    /**< The solar radiation component of the wind record. */
    Temperature m_temperature;          /**< The temperature component of the wind record. */
};

/**
 * @brief Overloaded stream insertion operator for outputting WindRecType to an ostream.
 *
 * @param[out] output The output stream.
 * @param[in] WRT The WindRecType object to output.
 * @return A reference to the output stream.
 */
ostream &operator << ( ostream &output, const WindRecType &WRT );

/**
 * @brief Overloaded stream extraction operator for reading WindRecType from an istream.
 *
 * @param[in,out] input The input stream.
 * @param[in,out] WRT The WindRecType object to populate from the input.
 * @return A reference to the input stream.
 */
istream &operator >> ( istream &input, WindRecType &WRT );

#endif // WINDRECTYPE_H_INCLUDED
