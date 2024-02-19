#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED

#include<cmath>

/**
 * @name Measurement
 * @brief Represents a base class.
 * @{
 */

/**
* @brief Represents a base class.
*/
class Measurement
{

public:

    /**
    * @brief Default constructor.
    * @post Creates a Measurement object with initial values.
    */
    Measurement();

    /**
     * @brief Parameterized constructor.
     * @param[in] measurement The measurement of the reading.
     * @post Creates a Measurement object with specified measurement.
     */
    Measurement( const float &measurement );

    /**
     * @brief Getter for the measurement variable.
     *
     * @return The measurement variable of the Observations.
     */
    float GetMeasurement() const;

    /**
     * @brief Setter for the measurement variable.
     *
     * @param[in] measurement The new measurement variable to set.
     * @post Sets the measurement variable to the specified value.
     */
    void SetMeasurement( const float &measurement );


    float GetMean( float &sum, unsigned &count );

    float GetSumSquareDifferences( float &sumSquareDifferences, float &perSquareDifference, float &mean );

    float GetStandardDeviation( float &sumSquareDifferences, unsigned &count );


private:
    unsigned INITIAL_VALUE = 0.0;   ///< Initial value for the Measurement.

    float m_measurement;            ///< measurement component of the Measurement Object.

};

#endif // MEASUREMENT_H_INCLUDED
