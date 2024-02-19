#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include<iostream>
#include<sstream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>

#include "Processor.h"
#include "Constant.h"
#include "MeasurementType.h"

using namespace std;

/**
 * @brief Type alias for a pointer to member function of the Measurement class.
 *
 * This type alias represents a pointer to a member function of the Measurement class. The member function
 * takes two parameters: a reference to a float and a reference to an unsigned int, and returns a float.
 * It is used to define a pointer to a function that calculates a mean value.
 */
using MeanFunctionPtr = float (Measurement::*)(float&, unsigned&);

/**
 * @brief The Client class provides functionality for interacting with the user,
 * managing input validation, processing data, and displaying results.
 */
class Client
{
public:

    /**
     * @brief Displays the menu options to the user.
     *
     * This function prints the menu options to the console, including:
     *  - Option 1: Display data analysis for a specific month and year.
     *  - Option 2: Display data analysis for a specific month.
     *  - Option 3: Display data analysis for a specific year.
     *  - Option 4: Display data analysis for all months of a specific year.
     *  - Option 5: Exit the program.
     */
    void MenuList();

    /**
     * @brief Waits for the user to press the Enter key to continue.
     *
     * This function displays a message prompting the user to press the Enter key to continue,
     * and then waits until the Enter key is pressed before returning control.
     *
     * @note This function utilizes the conio.h library.
     */
    void EnterRequired();

    /**
     * @brief Clears the console screen.
     *
     * This function clears the contents of the console screen by calling the system command
     * "cls" (for Windows systems). This is used to provide a clean
     * display and resetting the console before displaying a new menu list.
     *
     * @note This function utilizes the system() function to execute a system command.
     */
    void ClearScreen();

    // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /**
     * @brief Validates the user's input for the month.
     *
     * This function prompts the user to enter a month and validates the input.
     * It ensures that the input is within a valid range (1-12) and is a numeric value.
     * If the input is invalid, it displays an error message and prompts the user to enter
     * a valid numeric value within the specified range.
     *
     * @return Validated month input provided by the user.
     */
    unsigned ClientMonthInputValidation();

    /**
     * @brief Validates the user's input for the year.
     *
     * This function prompts the user to enter a year and validates the input.
     * It ensures that the input is within a valid range (2010-2030) and is a numeric value.
     * If the input is invalid, it displays an error message and prompts the user to enter
     * a valid numeric value within the specified range.
     *
     * @return Validated year input provided by the user.
     */
    unsigned ClientYearInputValidation();

    /**
     * @brief Calculates the sum of selected wind speed inputs for a specific month and year.
     *
     * This function iterates through the wind record log and calculates the sum of wind speed
     * inputs for entries matching the specified month and year.
     *
     * @param[in] windRecLog Vector of wind records.
     * @param[in] month The month for which to calculate the sum.
     * @param[in] year The year for which to calculate the sum.
     * @return Sum of wind speed inputs for the specified month and year.
     */
    float GetSumFromSelectedInput(
        Vector<WindRecType> &windRecLog,
        const unsigned &month,
        const unsigned &year );

    /**
     * @brief Counts the number of entries matching the specified month and year in the wind record log.
     *
     * This function iterates through the wind record log and counts the number of entries that match
     * the specified month and year.
     *
     * @param[in] windRecLog Vector of wind records.
     * @param[in] month The month to match.
     * @param[in] year The year to match.
     * @return The number of entries matching the specified month and year.
     */
    unsigned GetClientMonthYearInputCount(
        Vector<WindRecType> &windRecLog,
        const unsigned &month,
        const unsigned &year );

    /**
     * @brief Calculates the mean of selected inputs based on the specified measurement type.
     *
     * This function calculates the mean of selected inputs for the given wind record type and
     * measurement type using the provided mean function pointer.
     *
     * @param[in] windRecType Wind record type.
     * @param[in] sum The sum of selected inputs.
     * @param[in] count The count of selected inputs.
     * @param[in] meanFunc Pointer to the mean calculation function.
     * @param[in] measurementType Type of measurement.
     * @return The mean of selected inputs.
     */
    float GetMeanFromSelectedInput(
        WindRecType &windRecType,
        float &sum,
        unsigned &count,
        MeanFunctionPtr meanFunc,
        MeasurementType measurementType);

    /**
    * @brief Calculates the sample standard deviation for selected inputs based on the specified measurement type.
    *
    * This function calculates the sample standard deviation of selected inputs for the given wind record type and
    * measurement type. It iterates through the wind record log, calculates the sum of squared differences from the mean,
    * and then calculates the sample standard deviation using the sum of squared differences and the count of inputs.
    *
    * @param[in] windRecLog Vector of wind records.
    * @param[in] windRecType Wind record type.
    * @param[in] mean The mean of selected inputs.
    * @param[in] count The count of selected inputs.
    * @param[in] measurementType Type of measurement.
    * @return The sample standard deviation of selected inputs.
    */
    float GetSampleStandardDeviation(
        Vector<WindRecType> &windRecLog,
        WindRecType &windRecType,
        float &mean,
        unsigned &count,
        MeasurementType measurementType);

    // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /**
     * @brief Calculates the monthly sum of each measurement type for a specific year.
     *
     * This function calculates the sum of each measurement type (e.g., wind speed, temperature, solar radiation)
     * for each month of the specified year from the wind record log.
     *
     * @param[in] windRecLog Vector of wind records.
     * @param[in] year The year for which to calculate the monthly sums.
     * @param[in] monthlySum An array to store the monthly sums for each measurement type.
     * @param[in] month The month index.
     * @param[in] measurementType Type of measurement.
     *
     * @return The monthly sum of the specified measurement type for the specified month and year.
     */
    float GetMonthlySumOfEachFromInput(Vector<WindRecType> &windRecLog, const unsigned &year, float monthlySum[], unsigned &month, MeasurementType measurementType);

    /**
    * @brief Calculates the monthly count of each measurement type for a specific year.
    *
    * This function calculates the count of each measurement type (e.g., number of wind speed measurements,
    * number of temperature measurements, number of solar radiation measurements) for each month of the
    * specified year from the wind record log.
    *
    * @param[in] windRecLog Vector of wind records.
    * @param[in] year The year for which to calculate the monthly counts.
    * @param[in] monthlyCount An array to store the monthly counts for each measurement type.
    * @param[in] month The month index.
    *
    * @return The monthly count of the specified measurement type for the specified month and year.
    */
    float GetMonthlySumCountOfEachFromInput( Vector<WindRecType> &windRecLog, const unsigned &year, unsigned monthlyCount[], unsigned &month );

    // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    /**
    * @brief Displays option one with data.
    *
    * This function displays the average wind speed and wind speed standard deviation
    * for a specific month and year.
    *
    * @param[in] windRecType Wind record type.
    * @param[in] mean The mean of wind speed inputs.
    * @param[in] ssD The sample standard deviation of wind speed inputs.
    * @param[in] month The month for which the data is displayed.
    * @param[in] year The year for which the data is displayed.
    *
    * @return void
    */
    void DisplayOptionOneWithData(
        WindRecType &windRecType,
        const float &mean,
        const float &ssD,
        const unsigned &month,
        const unsigned &year );

    /**
     * @brief Displays option one without data.
     *
     * This function displays a message indicating that there is no data available
     * for the specified month and year.
     *
     * @param[in] windRecType Wind record type.
     * @param[in] month The month for which the data is not available.
     * @param[in] year The year for which the data is not available.
     *
     * @return void
     */
    void DisplayOptionOneWithOutData(
        WindRecType &windRecType,
        const unsigned &month,
        const unsigned &year );

    /**
     * @brief Displays option two with data.
     *
     * This function displays the mean temperature and its standard deviation for a specific month.
     *
     * @param[in] windRecType Wind record type.
     * @param[in] mean The mean temperature.
     * @param[in] ssD The standard deviation of temperature.
     * @param[in] month The month index.
     *
     * @return void
     */
    void DisplayOptionTwoWithData( WindRecType &windRecType, float &mean, float &ssD, const unsigned &month );

    /**
    * @brief Displays option two without data.
    *
    * This function displays a message indicating no data of temperature for a specific month.
    *
    * @param[in] windRecType Wind record type.
    * @param[in] month The month index.
    *
    * @return void
    */
    void DisplayOptionTwoWithOutData( WindRecType &windRecType, const unsigned &month );

    /**
     * @brief Displays option three with data.
     *
     * This function displays the sum of solar radiation for a specific month.
     *
     * @param[in] windRecType Wind record type.
     * @param[in] month The month index.
     * @param[in] sum The sum of solar radiation.
     *
     * @return void
     */
    void DisplayOptionThreeWithData( WindRecType &windRecType, const unsigned &month, const float &sum );

    /**
     * @brief Displays option three without data.
     *
     * This function displays a message indicating no data of solar radiation for a specific month.
     *
     * @param[in] windRecType Wind record type.
     * @param[in] month The month index.
     *
     * @return void
     */
    void DisplayOptionThreeWithOutData( WindRecType &windRecType, const float &month );

    /**
     * @brief Displays measurement data for a specific month and writes it to a CSV file.
     *
     * This function displays measurement data including average wind speed, average ambient temperature,
     * and solar radiation for a specific month. It also writes the data to a CSV file specified by the
     * output file path.
     *
     * @param[in] windRecType The wind record type.
     * @param[in] outputFilePath The path to the output CSV file.
     * @param[in] month The month index.
     * @param[in] speedMean The average wind speed.
     * @param[in] speedSsd The standard deviation of wind speed.
     * @param[in] tempMean The average ambient temperature.
     * @param[in] tempSsd The standard deviation of ambient temperature.
     * @param[in] srSum The total solar radiation.
     *
     * @return void
     */
    void DisplayOptionFourWithData(
        WindRecType &windRecType,
        const string &outputFilePath,
        const unsigned &month,
        const float &speedMean,
        const float &speedSsd,
        const float &tempMean,
        const float &tempSsd,
        const float &srSum);

    /**
     * @brief Displays option four without data.
     *
     * This function displays a message indicating the absence of data for temperature, wind speed, and solar radiation
     * for a specific month.
     *
     * @param[in] windRecType Wind record type.
     * @param[in] month The month index.
     *
     * @return void
     */
    void DisplayOptionFourWithOutData( WindRecType &windRecType, const float &month );

    /**
     * @brief Outputs measurement data to a CSV file.
     *
     * This function writes measurement data including average wind speed, average ambient temperature,
     * and solar radiation to a CSV file specified by the output file path.
     *
     * @param[in] windRecType The wind record type.
     * @param[in] output_filePath The path to the output CSV file.
     * @param[in] month The month index.
     * @param[in] speedMean The average wind speed.
     * @param[in] speedSsd The standard deviation of wind speed.
     * @param[in] tempMean The average ambient temperature.
     * @param[in] tempSsd The standard deviation of ambient temperature.
     * @param[in] srSum The total solar radiation.
     *
     * @return void
     */
    void OutputStreamMeasurement(
        WindRecType &windRecType,
        const string &output_filePath,
        unsigned &month,
        float &speedMean,
        float &speedSsd,
        float &tempMean,
        float &tempSsd,
        float &srSum );


private:
    string m_clientInput;       ///< User input.
    unsigned m_convertedInput;  ///< Converted user input.

    /**
     * @brief Checks if the converted month input is valid.
     *
     * @return true if the month input is valid, false otherwise.
     */
    bool IsMonthInputValid() const;

    /**
     * @brief Checks if the converted year input is valid.
     *
     * @return true if the year input is valid, false otherwise.
     */
    bool IsYearInputValid() const;

    /**
     * @brief Checks if the given month exists in the wind record log.
     *
     * @param[in] windRecLog The vector of wind record types.
     * @param[in] month The month to check.
     *
     * @return true if the month is found, false otherwise.
     */
    bool IsClientMonthFound( Vector<WindRecType> &windRecLog, const unsigned &month ) const;

    /**
     * @brief Checks if the given year exists in the wind record log.
     *
     * @param[in] windRecLog The vector of wind record types.
     * @param[in] year The year to check.
     *
     * @return true if the year is found, false otherwise.
     */
    bool IsClientYearFound( Vector<WindRecType> &windRecLog, const unsigned &year ) const;

};

#endif // CLIENT_H_INCLUDED
