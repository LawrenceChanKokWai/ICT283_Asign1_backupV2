
#include "Client.h"

// ++++++++++++ PUBLIC ++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++
void Client::MenuList()
{
    cout   << Constant::MENU_OPTIONS_MSG
           << Constant::MENU_OPTION_ONE_MSG
           << Constant::MENU_OPTION_TWO_MSG
           << Constant::MENU_OPTION_THREE_MSG
           << Constant::MENU_OPTION_FOUR_MSG
           << Constant::MENU_OPTION_FIVE_MSG << endl;
}

void Client::EnterRequired()
{
    cout << Constant::INFO( Constant::PRESS_ENTER_TO_CONTINUE_MSG ) << endl;
    while( getch() != 13 );
}

void Client::ClearScreen()
{
    system("cls");
}

unsigned Client::ClientMonthInputValidation()
{
    do
    {
        cout << Constant::INFO(Constant::MONTH_RANGE_MSG) << '\n'
             << Constant::SELECTION_INPUT;
        cin >> m_clientInput;
        try
        {
            m_convertedInput = stoi(m_clientInput);
        }
        catch (...)
        {
            cout << Constant::STATUS(!IsMonthInputValid(), Constant::INVALID_NUMERIC_ENTRY_MSG) << '\n';
        }
    }
    while (IsMonthInputValid());   // Continue looping until the input is valid
    return m_convertedInput;
}

unsigned Client::ClientYearInputValidation()
{
    do
    {
        cout << Constant::INFO(Constant::YEAR_RANGE_MSG) << '\n'
             << Constant::SELECTION_INPUT;
        cin >> m_clientInput;
        try
        {
            m_convertedInput = stoi(m_clientInput);
        }
        catch (...)
        {
            cout << Constant::STATUS(!IsYearInputValid(), Constant::INVALID_NUMERIC_ENTRY_MSG) << '\n';
        }
    }
    while (IsYearInputValid());   // Continue looping until the input is valid
    return m_convertedInput;
}

float Client::GetSumFromSelectedInput( Vector<WindRecType> &windRecLog, const unsigned &month, const unsigned &year )
{
    unsigned sum = 0.0;

    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr ++ )
    {
        if( IsClientMonthFound(windRecLog, month) && IsClientYearFound(windRecLog, year) )
        {
            sum += ptr->GetRecordWindSpeed().GetMeasurement();
        }
    }

    /**
    for( unsigned i(0); i<windRecLog.GetUsed(); i++ )
    {
        if( IsClientMonthFound( windRecLog, month ) &&
                IsClientYearFound( windRecLog, year ) )
        {
            sum +=  windRecLog[i].GetRecordWindSpeed().GetMeasurement();
        }
    }
    */
    return sum;
}

unsigned Client::GetClientMonthYearInputCount( Vector<WindRecType> &windRecLog, const unsigned &month, const unsigned &year )
{
    unsigned count = 0;

    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr++ )
    {
        if( IsClientMonthFound(windRecLog, month) && IsClientYearFound(windRecLog, year) )
        {
            count ++;
        }
    }

    /**
    for( unsigned i(0); i<windRecLog.GetUsed(); i++ )
    {
        if( IsClientMonthFound( windRecLog, month ) &&
                IsClientYearFound( windRecLog, year ) )
        {
            count ++;
        }
    }
    */
    return count;
}

float Client::GetMeanFromSelectedInput(
    WindRecType &windRecType,
    float &sum,
    unsigned &count,
    MeanFunctionPtr meanFunc,
    MeasurementType measurementType )
{
    switch (measurementType)
    {
    case MeasurementType::WINDSPEED:
        return (windRecType.GetRecordWindSpeed().*meanFunc)(sum, count);
    case MeasurementType::TEMPERATURE:
        return (windRecType.GetRecordTemperature().*meanFunc)(sum, count);
    case MeasurementType::SOLARRADIATION:
        return (windRecType.GetRecordSolarRadiation().*meanFunc)(sum, count);
    default:
        cerr << "Invalid measurement type" << endl;
        return 0.0;
    }
}

float Client::GetSampleStandardDeviation(Vector<WindRecType> &windRecLog, WindRecType &windRecType, float &mean, unsigned &count, MeasurementType measurementType)
{
    float squareDiffForEachElement = 0.0;
    float sumSquareDiff = 0.0;
    float variance = 0.0;

    /**
    for (unsigned i = 0; i < windRecLog.GetUsed(); i++)
    {
        switch (measurementType)
        {
        case MeasurementType::WINDSPEED:
            squareDiffForEachElement = windRecLog[i].GetRecordWindSpeed().GetMeasurement();
            sumSquareDiff = windRecType.GetRecordWindSpeed().GetSumSquareDifferences(variance, squareDiffForEachElement, mean);
            break;
        case MeasurementType::TEMPERATURE:
            squareDiffForEachElement = windRecLog[i].GetRecordTemperature().GetMeasurement();
            sumSquareDiff = windRecType.GetRecordTemperature().GetSumSquareDifferences(variance, squareDiffForEachElement, mean);
            break;
        case MeasurementType::SOLARRADIATION:
            squareDiffForEachElement = windRecLog[i].GetRecordSolarRadiation().GetMeasurement();
            sumSquareDiff = windRecType.GetRecordSolarRadiation().GetSumSquareDifferences(variance, squareDiffForEachElement, mean);
            break;
        default:
            cerr << "Invalid measurement type" << endl;
            return 0.0;
        }
    }
    */

    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr++ )
    {
        switch (measurementType)
        {
        case MeasurementType::WINDSPEED:
            squareDiffForEachElement = ptr->GetRecordWindSpeed().GetMeasurement();
            sumSquareDiff = windRecType.GetRecordWindSpeed().GetSumSquareDifferences(variance, squareDiffForEachElement, mean);
            break;
        case MeasurementType::TEMPERATURE:
            squareDiffForEachElement = ptr->GetRecordTemperature().GetMeasurement();
            sumSquareDiff = windRecType.GetRecordTemperature().GetSumSquareDifferences(variance, squareDiffForEachElement, mean);
            break;
        case MeasurementType::SOLARRADIATION:
            squareDiffForEachElement = ptr->GetRecordSolarRadiation().GetMeasurement();
            sumSquareDiff = windRecType.GetRecordSolarRadiation().GetSumSquareDifferences(variance, squareDiffForEachElement, mean);
            break;
        default:
            cerr << "Invalid measurement type" << endl;
            return 0.0;
        }
    }

    switch (measurementType)
    {
    case MeasurementType::WINDSPEED:
        return windRecType.GetRecordWindSpeed().GetStandardDeviation(sumSquareDiff, count);
    case MeasurementType::TEMPERATURE:
        return windRecType.GetRecordTemperature().GetStandardDeviation(sumSquareDiff, count);
    case MeasurementType::SOLARRADIATION:
        return windRecType.GetRecordSolarRadiation().GetStandardDeviation(sumSquareDiff, count);
    default:
        cerr << "Invalid measurement type" << endl;
        return 0.0;
    }
}

void Client::DisplayOptionOneWithData( WindRecType &windRecType, const float &mean, const float &ssD, const unsigned &month, const unsigned &year )
{
    cout    << Constant::OUTPUT << endl;
    cout    << setw(5) << " " << windRecType.GetRecordDate().GetMonthInStr(month) << " " << year << ":" << endl;
    cout    << setw(8) << " " << Constant::AVERAGE_WINDSPEED << setprecision(3) << mean << endl;
    cout    << setw(8) << " " << Constant::WINDSPEED_STANDARD_DEVIATION << setprecision(3) << ssD << '\n' << endl;
}

void Client::DisplayOptionOneWithOutData( WindRecType &windRecType, const unsigned &month, const unsigned &year )
{
    cout    << Constant::OUTPUT << endl;
    cout    << setw(5) << " " << windRecType.GetRecordDate().GetMonthInStr(month) << " " << year << ": NO DATA" << '\n' << endl;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------

float Client::GetMonthlySumOfEachFromInput(Vector<WindRecType> &windRecLog, const unsigned &year, float monthlySum[], unsigned &month, MeasurementType measurementType)
{
    // Initialize the monthly sum to 0
    for (int i = 0; i < 12; ++i)
    {
        monthlySum[i] = 0.0;
    }

    /**
    for (unsigned i = 0; i < windRecLog.GetUsed(); i++)
    {
        if (IsClientYearFound(windRecLog, year))
        {
            // Get the month index (0-based)
            month = windRecLog[i].GetRecordDate().GetMonth() - 1;
            switch( measurementType )
            {
            case MeasurementType::WINDSPEED:
                monthlySum[month] += windRecLog[i].GetRecordWindSpeed().GetMeasurement();
                break;
            case MeasurementType::TEMPERATURE:
                monthlySum[month] += windRecLog[i].GetRecordTemperature().GetMeasurement();
                break;
            case MeasurementType::SOLARRADIATION:
                monthlySum[month] += windRecLog[i].GetRecordSolarRadiation().GetMeasurement();
                break;
            default:
                cerr << "Invalid measurement type" << endl;
                break;
            }
        }
    }
    */

    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr++ )
    {
        if (IsClientYearFound(windRecLog, year))
        {
            // Get the month index (0-based)
            month = ptr->GetRecordDate().GetMonth() - 1;
            switch( measurementType )
            {
            case MeasurementType::WINDSPEED:
                monthlySum[month] += ptr->GetRecordWindSpeed().GetMeasurement();
                break;
            case MeasurementType::TEMPERATURE:
                monthlySum[month] += ptr->GetRecordTemperature().GetMeasurement();
                break;
            case MeasurementType::SOLARRADIATION:
                monthlySum[month] += ptr->GetRecordSolarRadiation().GetMeasurement();
                break;
            default:
                cerr << "Invalid measurement type" << endl;
                break;
            }
        }
    }

    return monthlySum[month];
}


float Client::GetMonthlySumCountOfEachFromInput( Vector<WindRecType> &windRecLog, const unsigned &year, unsigned monthlyCount[], unsigned &month )
{
    /**
    for (unsigned i = 0; i < windRecLog.GetUsed(); i++)
    {
        if (IsClientYearFound(windRecLog, year))
        {
            month = windRecLog[i].GetRecordDate().GetMonth() - 1;
            monthlyCount[month] ++;
        }
    }
    */
    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr++ )
    {
        if( IsClientYearFound(windRecLog, year ) )
        {
            month = ptr->GetRecordDate().GetMonth() -1;
            monthlyCount[month] ++;
        }
    }
    return monthlyCount[month];
}

void Client::DisplayOptionTwoWithData( WindRecType &windRecType, float &mean, float &ssD, const unsigned &month )
{
    cout    << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": "
            << setprecision(3) << mean << " degrees C, stdev: "
            << setprecision(3) << ssD << endl;
}

void Client::DisplayOptionTwoWithOutData( WindRecType &windRecType, const unsigned &month )
{
    cout    << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << " " << ": NO DATA" << endl;
}

// ----------------- OPTION THREE ---------------------------------------------------------------------------------------------
void Client::DisplayOptionThreeWithData( WindRecType &windRecType, const unsigned &month, const float &sum )
{
    cout    << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": "
            << setprecision(4) << sum / 60000 << " kWh/m2" << endl;
}

void Client::DisplayOptionThreeWithOutData( WindRecType &windRecType, const float &month )
{
    cout << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": No Data" << endl;
}

// ---------------- OPTION FOUR ------------------------------------------------------------------------------------------------
void Client::DisplayOptionFourWithData(
    WindRecType &windRecType,
    const string &outputFilePath,
    const unsigned &month,
    const float &speedMean,
    const float &speedSsd,
    const float &tempMean,
    const float &tempSsd,
    const float &srSum)
{
    cout    << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ","
            << speedMean << "(" << speedSsd << "),"
            << tempMean << "(" << tempSsd << "),"
            << srSum / 60000 << endl;
}

void Client::DisplayOptionFourWithOutData( WindRecType &windRecType, const float &month )
{
    cout << setw(7) << " " << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ": No Data" << endl;
}


// ++++++++++++ PRIVATE ++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++
bool Client::IsMonthInputValid() const
{
    return ( m_convertedInput <= 0 || m_convertedInput > 12 );
}

bool Client::IsYearInputValid() const
{
    return ( m_convertedInput <= 2010 || m_convertedInput > 2030 );
}

bool Client::IsClientMonthFound( Vector<WindRecType> &windRecLog, const unsigned &month ) const
{
    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr++ )
    {
        if( month == ptr->GetRecordDate().GetMonth() )
        {
            return true;
        }
    }

    /**
    for( unsigned i(0); i<windRecLog.GetUsed(); i++ )
    {
        if( month == windRecLog[i].GetRecordDate().GetMonth() )
        {
            return true;
        }
    }
    */

    return false;
}

bool Client::IsClientYearFound( Vector<WindRecType> &windRecLog, const unsigned &year ) const
{
    /**
    for( unsigned i(0); i<windRecLog.GetUsed(); i++ )
    {
        if( year == windRecLog[i].GetRecordDate().GetYear() )
        {
            return true;
        }
    }
    */

    for( WindRecType *ptr = windRecLog.Start(); ptr != windRecLog.Finish(); ptr++ )
    {
        if( year == ptr->GetRecordDate().GetYear() )
        {
            return true;
        }
    }
    return false;
}

void Client::OutputStreamMeasurement(
    WindRecType &windRecType,
    const string &output_filePath,
    unsigned &month,
    float &speedMean,
    float &speedSsd,
    float &tempMean,
    float &tempSsd,
    float &srSum )
{
    ofstream outputFile( output_filePath );

    if( !outputFile )
    {
        cerr << "[ ERROR ] Opening File: " << output_filePath << endl;
    }
    outputFile << "Month,Average Wind Speed(stdev),Average Ambient Temperature(stdev),Solar Radiation" << endl;

    outputFile << windRecType.GetRecordDate().GetMonthInStr(month + 1) << ","
               << speedMean << "(" << speedSsd << "),"
               << tempMean << "(" << tempSsd << "),"
               << srSum / 60000 << endl;

    // Close the CSV file
    outputFile.close();
}


