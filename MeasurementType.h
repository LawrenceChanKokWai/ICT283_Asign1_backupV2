#ifndef MEASUREMENTTYPE_H_INCLUDED
#define MEASUREMENTTYPE_H_INCLUDED

enum class MeasurementType
{
    WINDSPEED,
    TEMPERATURE,
    SOLARRADIATION
};

//using MeanFunctionPtr = float (Measurement::*)(float&, unsigned&);

#endif // MEASUREMENTTYPE_H_INCLUDED
