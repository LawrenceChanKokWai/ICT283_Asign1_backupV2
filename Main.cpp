
#include<iostream>
#include<fstream>
#include<limits>

#include "Processor.h"
#include "Client.h"

using namespace std;

int main()
{
    // Initialize required variables for Processor class
    const string file = "data/data_source_test.txt";
    const string outputFilePath = "WindTempSolar.csv";
    ifstream inFile( file );
    WindRecType windRecType;
    Vector<string> csvFilePath;
    Vector<WindRecType> windRecTypeVector;

    // Initialize required variable for Client class
    Client client;
    unsigned month = 0;
    float monthlySum[12] = { 0.0 };
    unsigned monthlyCount[12] = { 0 };
    unsigned clientInputMonth = 0;
    unsigned clientInputYear = 0;
    float sum = 0.0;
    unsigned count = 0;
    float mean = 0.0;
    float ssD = 0.0;
    float temperatureSum = 0.0;
    float windSpeedSum = 0.0;
    float solarRadiationSum = 0.0;
    float windSpeedMean = 0.0;
    float windSpeedSsD = 0.0;
    float temperatureMean = 0.0;
    float temperatureSsd = 0.0;
    MeanFunctionPtr windSpeedMeanFunc = nullptr;
    MeanFunctionPtr temperatureMeanFunc = nullptr;

    // routines
    Processor::GetInstance();                                                                       // create singleton instance
    Processor::GetInstance().LoadCSVFilePathToVector( csvFilePath, inFile, file );                  // Loading csv file path from txt file
    Processor::GetInstance().LoadCSVDataToVector( csvFilePath, windRecTypeVector, windRecType );    // Loading data into vector

    // Menu routines
    char user_choice;
    do
    {
        client.MenuList();

        cout << Constant::SELECTION_INPUT;
        user_choice = getch();
        switch( user_choice )
        {
        case '1':
            // Validation of user input month and year.
            cout << Constant::SELECTED_OPTION_ONE_MSG << endl;
            clientInputMonth = client.ClientMonthInputValidation();
            clientInputYear = client.ClientYearInputValidation();

            // Calculate WindSpeed Mean
            sum = client.GetSumFromSelectedInput( windRecTypeVector, clientInputMonth, clientInputYear );
            count = client.GetClientMonthYearInputCount( windRecTypeVector, clientInputMonth, clientInputYear );
            windSpeedMeanFunc = &WindSpeed::GetMean;
            mean = client.GetMeanFromSelectedInput(windRecType, sum, count, windSpeedMeanFunc, MeasurementType::WINDSPEED);
            //mean = client.GetMeanFromSelectedInput( windRecType, windSpeedSum, windSpeedCount );

            if( count > 0 )
            {
                // Calculate Sample Standard Deviation & Display with data
                ssD = client.GetSampleStandardDeviation( windRecTypeVector, windRecType, mean, count, MeasurementType::WINDSPEED );
                client.DisplayOptionOneWithData( windRecType, mean, ssD, clientInputMonth, clientInputYear );
            }
            else
            {
                // Display without data
                client.DisplayOptionOneWithOutData( windRecType, clientInputMonth, clientInputYear );
            }
            break;
        case '2':
            // Validation of user input year
            cout << Constant::SELECTED_OPTION_TWO_MSG << endl;
            clientInputYear = client.ClientYearInputValidation();

            // Calculate each monthly Sum & monthly Count for each month array
            sum = client.GetMonthlySumOfEachFromInput(windRecTypeVector, clientInputYear, monthlySum, month, MeasurementType::TEMPERATURE);
            count = client.GetMonthlySumCountOfEachFromInput(windRecTypeVector, clientInputYear, monthlyCount, month );

            temperatureMeanFunc = &Temperature::GetMean;
            cout << Constant::OUTPUT << '\n' <<
                 setw(5) << " " << clientInputYear << endl;
            for (unsigned month = 0; month < 12; month++)
            {
                if (monthlyCount[month] > 0)
                {
                    mean = client.GetMeanFromSelectedInput(
                               windRecType,
                               sum,
                               count,
                               temperatureMeanFunc,
                               MeasurementType::TEMPERATURE);
                    ssD = client.GetSampleStandardDeviation(
                              windRecTypeVector,
                              windRecType,
                              mean,
                              count,
                              MeasurementType::TEMPERATURE);
                    client.DisplayOptionTwoWithData( windRecType, mean, ssD, month );
                }
                else
                {
                    client.DisplayOptionTwoWithOutData( windRecType, month );
                }
            }
            break;
        case '3':
            cout << Constant::SELECTED_OPTION_THREE_MSG << endl;
            clientInputYear = client.ClientYearInputValidation();

            sum = client.GetMonthlySumOfEachFromInput(windRecTypeVector, clientInputYear, monthlySum, month, MeasurementType::SOLARRADIATION);
            count = client.GetMonthlySumCountOfEachFromInput(windRecTypeVector, clientInputYear, monthlyCount, month );
            cout << Constant::OUTPUT << endl;
            cout << setw(5) << " " << clientInputYear << endl;
            for (unsigned month = 0; month < 12; month++)
            {
                if (monthlyCount[month] > 0)
                {
                    client.DisplayOptionThreeWithData( windRecType, month, sum );
                }
                else
                {
                    client.DisplayOptionThreeWithOutData( windRecType, month );
                }
            }
            break;
        case '4':
            cout << Constant::SELECTED_OPTION_FOUR_MSG << endl;
            clientInputYear = client.ClientYearInputValidation();

            windSpeedSum = client.GetMonthlySumOfEachFromInput(windRecTypeVector, clientInputYear, monthlySum, month, MeasurementType::WINDSPEED);
            temperatureSum = client.GetMonthlySumOfEachFromInput(windRecTypeVector, clientInputYear, monthlySum, month, MeasurementType::TEMPERATURE);
            solarRadiationSum = client.GetMonthlySumOfEachFromInput(windRecTypeVector, clientInputYear, monthlySum, month, MeasurementType::SOLARRADIATION);
            count = client.GetMonthlySumCountOfEachFromInput(windRecTypeVector, clientInputYear, monthlyCount, month );

            windSpeedMeanFunc = &WindSpeed::GetMean;
            temperatureMeanFunc = &Temperature::GetMean;

            cout << Constant::OUTPUT << endl;
            cout << setw(5) << " " << clientInputYear << endl;
            for (unsigned month = 0; month < 12; month++)
            {
                if (monthlyCount[month] > 0)
                {
                    windSpeedMean = client.GetMeanFromSelectedInput(
                                        windRecType,
                                        windSpeedSum,
                                        count,
                                        windSpeedMeanFunc,
                                        MeasurementType::WINDSPEED);
                    windSpeedSsD = client.GetSampleStandardDeviation(
                                       windRecTypeVector,
                                       windRecType,
                                       windSpeedMean,
                                       count,
                                       MeasurementType::WINDSPEED);

                    temperatureMean = client.GetMeanFromSelectedInput(
                                          windRecType,
                                          temperatureSum,
                                          count,
                                          temperatureMeanFunc,
                                          MeasurementType::TEMPERATURE);
                    temperatureSsd = client.GetSampleStandardDeviation(
                                         windRecTypeVector,
                                         windRecType,
                                         temperatureMean,
                                         count,
                                         MeasurementType::TEMPERATURE);

                    client.DisplayOptionFourWithData(
                        windRecType,
                        outputFilePath,
                        month,
                        windSpeedMean,
                        windSpeedSsD,
                        temperatureMean,
                        temperatureSsd,
                        solarRadiationSum);

                    client.OutputStreamMeasurement(
                        windRecType,
                        outputFilePath,
                        month,
                        windSpeedMean,
                        windSpeedSsD,
                        temperatureMean,
                        temperatureSsd,
                        solarRadiationSum );
                }
                else
                {
                    client.DisplayOptionFourWithOutData( windRecType, month );
                }
            }
            cout << '\n' << setw(5) << " " << "[ INFO ] Data has been written to " << outputFilePath << endl;
            cout << endl;
            break;
        case '5':
            cout << Constant::SELECTED_OPTION_FIVE_MSG << endl;
            exit(0);
            break;
        default:
            break;
        }
        client.EnterRequired();
        client.ClearScreen();
    }
    while( user_choice !=27 );

    return 0;
}
