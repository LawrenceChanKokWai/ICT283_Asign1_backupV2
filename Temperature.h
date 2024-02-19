
/**
 * @file ICT283_AssignmentOne_Temperature.h
 * @brief Defines the Temperature class for representing the measurement of the wind records.
 * @author Chan Kok Wai
 * @version 1.0.0
 */
#ifndef TEMPERATURE_H_INCLUDED
#define TEMPERATURE_H_INCLUDED

#include<iostream>

#include "Measurement.h"

using namespace std;

/**
* @brief Represents a temperature measurement.
*/
class Temperature: public Measurement
{
public:

    /**
    * @brief Default constructor.
    *
    * @post Creates a Temperature object with initial values.
    */
    Temperature();

    /**
    * @brief Parameterized constructor.
    *
    * @param[in] measurement The measurement variable of the Temperature.
    * @post Creates a Temperature object with specified temperature measurement.
    */
    Temperature( const float &measurement );
};

/**
 * @brief Overloaded stream insertion operator for Temperature objects.
 * @param[out] output The output stream.
 * @param[in] TEMP The Temperature object to output.
 * @return The modified output stream.
 */
ostream &operator << ( ostream &output, const Temperature &TEMP );

/**
 * @brief Overloaded stream extraction operator for Temperature objects.
 * @param[in] input The input stream.
 * @param[out] TEMP The Temperature object to input into.
 * @return The modified input stream.
 */
istream &operator >> ( istream &input, Temperature &TEMP );

#endif // TEMPERATURE_H_INCLUDED
