
/**
 * @file ICT283_AssignmentOne_WindSpeed.h
 * @brief Defines the WindSpeed class for representing the measurement of the wind speed.
 * @author Chan Kok Wai
 * @version 1.0.0
 */
#ifndef WINDSPEED_H_INCLUDED
#define WINDSPEED_H_INCLUDED

#include<iostream>

#include "Measurement.h"

using namespace std;

/**
* @brief Represents a wind speed measurement.
*/
class WindSpeed: public Measurement
{

public:

    /**
    * @brief Default constructor.
    *
    * @post Creates a WindSpeed object with initial values.
    */
    WindSpeed();

    /**
    * @brief Parameterized constructor.
    *
    * @param[in] measurement The measurement variable of the WindSpeed.
    * @post Creates a WindSpeed object with specified wind speed measurement.
    */
    WindSpeed( const float &measurement );

};

/**
 * @brief Overloaded stream insertion operator for WindSpeed objects.
 * @param[out] output The output stream.
 * @param[in] WS The WindSpeed object to output.
 * @return The modified output stream.
 */
ostream &operator << ( ostream &output, const WindSpeed &WS );

/**
 * @brief Overloaded stream extraction operator for WindSpeed objects.
 * @param[in] input The input stream.
 * @param[out] WS The WindSpeed object to input into.
 * @return The modified input stream.
 */
istream &operator >> ( istream &input, WindSpeed &WS );

#endif // WINDSPEED_H_INCLUDED
