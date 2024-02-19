
#include<iostream>

#include "Client.h"

using namespace std;

void Assert( bool condition, const string &message );
void TestMenuListDisplay( Client &client);
void TestClientMonthInputValidation( Client &client );
void TestClientYearInputValidation( Client &client );

int main()
{
    Client client;

    TestClientMonthInputValidation( client );
    TestClientYearInputValidation( client );
    TestMenuListDisplay( client );

    return 0;
}

void Assert( bool condition, const string &message )
{
    if( condition )
    {
        cout << "\t[ PASS ] " << message << endl;
    }
    else
    {
        cout << "\t[ FAIL ] " << message << endl;
    }
}

void TestMenuListDisplay( Client &client)
{
    client.MenuList();
}

void TestClientMonthInputValidation( Client &client )
{
    unsigned monthInput = client.ClientMonthInputValidation();
    cout << "Test Month Input from Client Validation " << endl;
    Assert( monthInput >= 1 && monthInput <= 12, "Should return a valid month value" );
    cout << endl;
}

void TestClientYearInputValidation( Client &client )
{
    unsigned yearInput = client.ClientYearInputValidation();
    cout << "Test Year Input from Client Validation " << endl;
    Assert( yearInput >= 2011 && yearInput <= 2029, "Should return a valid year value" );
    cout << endl;
}
