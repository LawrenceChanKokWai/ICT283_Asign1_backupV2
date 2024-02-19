
#include "Processor.h"

// +++++++++++++ PRIVATE ++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++
Processor::Processor()
{
    m_dataRead = 0;
    m_dataInserted = 0;
}

void Processor::LoadDisplayCount()
{
    std::cout   << Constant::INFO( Constant::TOTAL_READ_DATA_MSG ) << m_dataRead << '\n'
                << Constant::INFO( Constant::TOTAL_SAVED_DATA_MSG ) << m_dataInserted << '\n'
                << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
                << endl;
}

// +++++++++++++ PUBLIC +++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++
Processor &Processor::GetInstance()
{
    static Processor *s_instance = new Processor();
    return *s_instance;
}

void Processor::LoadCSVFilePathToVector( Vector<string> &csvFilePath, ifstream &input, const string &filename )
{
    string file_path;
    if( !input )
    {
        cerr    << "++++++++++++++++++++++++++++++++ STATUS +++++++++++++++++++++++++++++++++++++++++\n"
                << "Error Opening File: " + filename << endl;
    }
    else
    {
        cout    << "++++++++++++++++++++++++++++++++ STATUS +++++++++++++++++++++++++++++++++++++++++\n"
                << "Opening File: " + filename << endl;
        while( input.peek() != EOF )
        {
            input >> file_path;
            csvFilePath.InsertLast( file_path );
        }
    }
}

void Processor::LoadCSVDataToVector( Vector<string> &csvFilePath, Vector<WindRecType> &windRecTypeVec, WindRecType &windRecType )
{
    for( unsigned i(0); i<csvFilePath.GetUsed(); i++ )
    {
        string modifiedFilePath = "data/" + csvFilePath[i];
        ifstream CSVFile( modifiedFilePath );
        if( !CSVFile )
        {
            cerr << "Error Opening CSV File Path: " << modifiedFilePath << endl;
        }
        else
        {
            cout << "Opening CSV File Path: " << modifiedFilePath << endl;
        }

        string line;
        getline( CSVFile, line );
        while( CSVFile.peek() != EOF )
        {
            CSVFile >> windRecType;
            m_dataRead ++;

            windRecTypeVec.InsertLast( windRecType );
            m_dataInserted ++;
        }
    }
    LoadDisplayCount();
}

