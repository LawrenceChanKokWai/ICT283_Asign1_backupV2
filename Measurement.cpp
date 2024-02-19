
#include "Measurement.h"

Measurement::Measurement()
{
    m_measurement = INITIAL_VALUE;
}

Measurement::Measurement( const float &measurement )
{
    m_measurement = measurement;
}

float Measurement::GetMeasurement() const
{
    return m_measurement;
}

void Measurement::SetMeasurement( const float &measurement )
{
    m_measurement = measurement;
}

float Measurement::GetMean( float &sum, unsigned &count ) {
    return (sum / count);
}

float Measurement::GetSumSquareDifferences( float &sumSquareDifferences, float &perSquareDifference, float &mean )
{
    return sumSquareDifferences += pow( (perSquareDifference - mean ), 2);
}

float Measurement::GetStandardDeviation( float &sumSquareDifferences, unsigned &count )
{
    sumSquareDifferences /= count;
    return sqrt( sumSquareDifferences );
}
