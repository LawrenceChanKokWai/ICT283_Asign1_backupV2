
/**
 * @file ICT283_AssignmentOne_SolarRadiation.h
 * @brief Defines the SolarRadiation class for representing the measurement of the wind records.
 * @author Chan Kok Wai
 * @version 1.0.0
 */
#ifndef SOLARRADIATION_H_INCLUDED
#define SOLARRADIATION_H_INCLUDED

#include<iostream>

#include "Measurement.h"

using namespace std;

/**
* @brief Represents a temperature measurement.
*/
class SolarRadiation: public Measurement
{
public:

    /**
    * @brief Default constructor.
    *
    * @post Creates a SolarRadiation object with initial values.
    */
    SolarRadiation();

    /**
    * @brief Parameterized constructor.
    *
    * @param[in] measurement The measurement variable of the Solar Radiation.
    * @post Creates a SolarRadiation object with specified solar radiation measurement.
    */
    SolarRadiation( const float &measurement );
};

/**
 * @brief Overloaded stream insertion operator for SolarRadiation objects.
 * @param[out] output The output stream.
 * @param[in] SR The Solar Radiation object to output.
 * @return The modified output stream.
 */
ostream &operator << ( ostream &output, const SolarRadiation &SR );

/**
 * @brief Overloaded stream extraction operator for Solar Radiation objects.
 * @param[in] input The input stream.
 * @param[out] SR The Solar Radiation object to input into.
 * @return The modified input stream.
 */
istream &operator >> ( istream &input, SolarRadiation &SR );

#endif // SOLARRADIATION_H_INCLUDED
