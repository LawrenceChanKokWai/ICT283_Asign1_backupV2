
#include "Temperature.h"

Temperature::Temperature(): Measurement() {}

Temperature::Temperature( const float &measurement ): Measurement( measurement ) {}

ostream &operator << ( ostream &output, const Temperature &TEMP )
{
    output << TEMP.GetMeasurement();

    return output;
}

istream &operator >> ( istream &input, Temperature &TEMP )
{
    string temperatureTempField;

    getline( input, temperatureTempField, '\n' );

    TEMP.SetMeasurement( stof(temperatureTempField) );

    return input;
}
