#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>

#include "WindRecType.h"
#include "Vector.h"
#include "Constant.h"

using namespace std;

/**
 * @brief The Processor class handles processing of CSV data as a singleton.
 *
 * This class provides functionality to load CSV file paths from a txt file and processes data into vectors,
 * and perform other processing tasks. It follows the singleton design pattern.
 */
class Processor
{
public:

    /**
     * @brief Returns the singleton instance of Processor.
     *
     * @return Processor& A reference to the singleton instance.
     */
    static Processor &GetInstance();

    /**
     * @brief Loads the CSV file paths from an txt file and stream into a vector.
     *
     * @param[in] csvFilePath The vector to store the CSV file paths.
     * @param[in] input The input stream from which to read the file paths.
     * @param[in] filename The name of the txt file being loaded.
     */
    void LoadCSVFilePathToVector( Vector<string> &csvFilePath, ifstream &input, const string &filename );

    /**
     * @brief Loads CSV data from a vector of file paths into a vector of WindRecType objects.
     *
     * @param[in] csvFilePath The vector containing the CSV file paths.
     * @param[in] windRecTypeVec The vector to store the WindRecType objects.
     * @param[in] windRecType An object of type WindRecType.
     */
    void LoadCSVDataToVector( Vector<string> &csvFilePath, Vector<WindRecType> &windRecTypeVec, WindRecType &windRecType );

private:
    static Processor *s_instance;   /**< Pointer to the singleton instance. */
    unsigned m_dataRead;            /**< Counter for the number of data read. */
    unsigned m_dataInserted;        /**< Counter for the number of data inserted. */

     /**
     * @brief Private constructor to prevent instantiation.
     */
    Processor();

    /**
     * @brief Loads the display count.
     *
     * This function loads the display count for the Processor instance.
     */
    void LoadDisplayCount();
};

#endif // PROCESSOR_H_INCLUDED
