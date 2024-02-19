
#include "WindSpeed.h"

WindSpeed::WindSpeed(): Measurement(){}

WindSpeed::WindSpeed( const float &measurement ): Measurement( measurement ){}

ostream &operator << ( ostream &output, const WindSpeed &WS )
{
    output << WS.GetMeasurement();

    return output;
}

istream &operator >> ( istream &input, WindSpeed &WS )
{
    string tempWindSpeed;
    const unsigned columnToSkip =10;

    for( unsigned i(0); i<columnToSkip; i++ )
    {
        getline( input, tempWindSpeed, ',' );
    }
    getline( input, tempWindSpeed, ',' );

    WS.SetMeasurement( stof(tempWindSpeed) );

    return input;
}
