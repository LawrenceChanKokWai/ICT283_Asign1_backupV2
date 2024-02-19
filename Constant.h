#ifndef CONSTANT_H_INCLUDED
#define CONSTANT_H_INCLUDED

#include<string>

/**
 * @brief Namespace containing constant messages used in the program.
 */
namespace Constant
{
const std::string POPULATING_DATA_MSG = "Populating data from file path ";
const std::string TOTAL_READ_DATA_MSG = "Total Read Data: ";
const std::string TOTAL_ERROR_DATA_MSG = "Total Error Data Skipped: ";
const std::string TOTAL_SAVED_DATA_MSG = "Total Saved Data To Structure: ";
const std::string OUTPUT = "\n[ OUTPUT ] --> ";
const std::string SELECTION_INPUT = "[ SELECTION ] --> ";
const std::string SELECTED_OPTION_ONE_MSG = "\n[ SELECTED ] : +++++ Option One +++++";
const std::string SELECTED_OPTION_TWO_MSG = "\n[ SELECTED ] : +++++ Option Two +++++";
const std::string SELECTED_OPTION_THREE_MSG = "\n[ SELECTED ] : +++++ Option Three +++++";
const std::string SELECTED_OPTION_FOUR_MSG = "\n[ SELECTED ] : +++++ Option Four +++++";
const std::string SELECTED_OPTION_FIVE_MSG = "\n[ SELECTED ] : +++++ Option Five +++++\n[ SYSTEM ] : EXIT PROGRAM";
const std::string PRESS_ENTER_TO_CONTINUE_MSG = "Please ENTER to continue with the system.......-->";
const std::string MENU_OPTIONS_MSG = "Below are the options available: ";
const std::string MENU_OPTION_ONE_MSG = "\n\t[ 1 ] : The average wind speed and sample standard deviation for this \n\t\twind speed given a specific month and year.";
const std::string MENU_OPTION_TWO_MSG = "\n\t[ 2 ] : Average ambient air temperature and sample standard deviation for each month of a year. ";
const std::string MENU_OPTION_THREE_MSG = "\n\t[ 3 ] : Total solar radiation in kWh/m2 for every month of a specified year.";
const std::string MENU_OPTION_FOUR_MSG = "\n\t[ 4 ] : Average wind speed (km/h), average ambient temperature and \n\t\ttotal solar radiation in kWh/m2 for each month of a specific year.";
const std::string MENU_OPTION_FIVE_MSG = "\n\t[ 5 ] : Exit the program.";
const std::string MONTH_RANGE_MSG = "Please enter month between 1 ~ 12, and press [ ENTER ]";
const std::string YEAR_RANGE_MSG = "Please enter a year between 2010 ~ 2030, and press [ ENTER ]";
const std::string INVALID_NUMERIC_ENTRY_MSG = "Invalid Numeric Entry.";
const std::string AVERAGE_WINDSPEED = "Average speed: ";
const std::string AVERAGE_TEMPERATURE = "\n\tAverage Temperature: ";
const std::string WINDSPEED_STANDARD_DEVIATION = "Sample stdev : ";
const std::string TEMPERATURE_STANDARD_DEVIATION = "Temperature Standard Deviation: ";

/**
 * @brief Returns a status message based on a condition.
 *
 * @param condition The condition to evaluate.
 * @param message The message to include in the status.
 * @return A status message indicating success or failure.
 */
inline std::string STATUS( bool condition, const std::string &message )
{
    return( condition ? "[ SUCCESS ] " + message : "[ FAIL ] " + message );
}

/**
 * @brief Returns an information message.
 *
 * @param message The message to include in the information.
 * @return An information message.
 */
inline std::string INFO( const std::string &message )
{
    return "[ INFO ] " + message;
}

}

#endif // CONSTANT_H_INCLUDED
