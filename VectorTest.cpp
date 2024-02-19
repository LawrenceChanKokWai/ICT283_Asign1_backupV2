
#include<iostream>
#include<typeinfo>

#include "Vector.h"

void Assert_Equals( bool condition, const std::string &message );
void TestInitialization();
void TestVectorDataTypeInitialization();
void TestInsertObjectOnLast();
void TestInsertObjectAt();
void TestRemoveObjectAtLast();
void TestRemoveObjectAt();
void TestOnPointerStartAndFinish();
void TestOnIndexOperator();
void TestCopyConstructor();
void TestEqualsAssignmentOperator();

int main()
{
    TestInitialization();
    TestVectorDataTypeInitialization();
    TestInsertObjectOnLast();
    TestInsertObjectAt();
    TestRemoveObjectAtLast();
    TestRemoveObjectAt();
    TestOnPointerStartAndFinish();
    TestOnIndexOperator();
    TestCopyConstructor();
    TestEqualsAssignmentOperator();

    return 0;
}

//++++ Use for testing +++
void Assert_Equals( bool condition, const std::string &message )
{
    std::cout << (condition ? "\t-->[ PASS ] " : "\t-->[ FAIL ] ") << message << std::endl;
}

//++++ Test on initialization of WindRecType Measurement +++
void TestInitialization()
{
    Vector<unsigned> unsignedVec;
    std::cout << "Test on initialization of Vector" << std::endl;
    Assert_Equals( unsignedVec.GetCapacity() == 2, "Constructed initial capacity is set to default" );
    Assert_Equals( unsignedVec.GetUsed() == 0, "Constructed initial used slot is set to default" );
    std::cout << std::endl;
}

void TestVectorDataTypeInitialization()
{
    Vector<unsigned> unsignedVec;
    Vector<std::string> stringVec;
    Vector<float> floatVec;
    std::cout << "Test on data type initialization of Vector" << std::endl;
    Assert_Equals( typeid(unsignedVec) == typeid(Vector<unsigned>), "Vector data type set as unsigned data type" );
    Assert_Equals( typeid(stringVec) == typeid(Vector<std::string>), "Vector data type set as string data type" );
    Assert_Equals( typeid(floatVec) == typeid(Vector<float>), "Vector data type set as float data type" );
    std::cout << std::endl;
}

void TestInsertObjectOnLast()
{
    Vector<unsigned> unsignedVec;
    std::cout << "Test on Insertion of object to Vector's last index" << std::endl;
    Assert_Equals( unsignedVec.InsertLast(10), "Insertion to Last index" );
    Assert_Equals( unsignedVec.InsertLast(20), "Insertion to Last index" );
    Assert_Equals( unsignedVec.InsertLast(30), "Insertion to Last index" );
    Assert_Equals( unsignedVec.InsertLast(40), "Insertion to Last index" );
    std::cout << "\t--> Output of Vector's element: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << '\n' << std::endl;
}

void TestInsertObjectAt()
{
    Vector<unsigned> unsignedVec;
    std::cout << "Test on Insertion of object to Vector's index [1]" << std::endl;
    Assert_Equals( unsignedVec.InsertLast(10), "Insertion to Last index" );
    Assert_Equals( unsignedVec.InsertLast(20), "Insertion to Last index" );
    Assert_Equals( unsignedVec.InsertLast(30), "Insertion to Last index" );
    Assert_Equals( unsignedVec.InsertLast(40), "Insertion to Last index" );
    std::cout << "\t--> Output of Vector's element before insertion: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    Assert_Equals( unsignedVec.InsertAt(50, 1), "Insert Object 50 at index[1]" );
    std::cout << "\t--> Output of Vector's element after insertion: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

void TestOnPointerStartAndFinish()
{
    Vector<unsigned> unsignedVec;
    unsignedVec.InsertLast(10);
    unsignedVec.InsertLast(20);
    unsignedVec.InsertLast(30);
    unsignedVec.InsertLast(40);
    std::cout << "\nTest `for loop` output of Vector's element using *Start And *Finish: " << '\n' << '\t' << "-->[ Output ]: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    Assert_Equals( *unsignedVec.Start() == 10, "Start pointer pointing at index [0]" );
    Assert_Equals( *(unsignedVec.Finish()-1) == 40, "Finish pointer pointing at last index -1" );
    std::cout << std::endl;
}

void TestOnIndexOperator()
{
    Vector<unsigned> unsignedVec;
    unsignedVec.InsertLast(10);
    unsignedVec.InsertLast(20);
    unsignedVec.InsertLast(30);
    unsignedVec.InsertLast(40);
    std::cout << "Test for index accessor: " << '\n' << '\t' << "-->[ Output ]: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    Assert_Equals( unsignedVec[0] == 10, "Index[0] is 10" );
    Assert_Equals( unsignedVec[1] == 20, "Index[1] is 20" );
    Assert_Equals( unsignedVec[2] == 30, "Index[2] is 30" );
    Assert_Equals( unsignedVec[3] == 40, "Index[3] is 40" );
}

void TestRemoveObjectAtLast()
{
    Vector<unsigned> unsignedVec;
    std::cout << "\nTest on removing object of the last element in the Vector" << std::endl;
    unsignedVec.InsertLast(10);
    unsignedVec.InsertLast(20);
    unsignedVec.InsertLast(30);
    unsignedVec.InsertLast(40);
    std::cout << "\t--> Output of Vector's element before removing last element: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    Assert_Equals( unsignedVec.RemoveLast(), "Last element removed" );
    std::cout << "\t--> Output of Vector's element after removing last element: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

void TestRemoveObjectAt()
{
    Vector<unsigned> unsignedVec;
    std::cout << "\nTest on removing object from a specific index" << std::endl;
    unsignedVec.InsertLast(10);
    unsignedVec.InsertLast(20);
    unsignedVec.InsertLast(30);
    unsignedVec.InsertLast(40);
    std::cout << "\t--> Output of Vector's element before removing element from a specific index: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    Assert_Equals( unsignedVec.RemoveAt(1), "index[1] removed" );
    std::cout << "\t--> Output of Vector's element after removing element from a specific index: ";
    for( unsigned *ptr = unsignedVec.Start(); ptr != unsignedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

void TestCopyConstructor()
{
    Vector<unsigned> unsignedVec;
    unsignedVec.InsertLast(10);
    unsignedVec.InsertLast(20);
    unsignedVec.InsertLast(30);
    unsignedVec.InsertLast(40);

    Vector<unsigned> copiedVec( unsignedVec );
    std::cout << "\nTest on Copy Constructor" << std::endl;
    Assert_Equals( copiedVec.GetCapacity() == unsignedVec.GetCapacity(), "copiedVec & unsignedVec [Capacity] are the same" );
    Assert_Equals( copiedVec.GetUsed() == unsignedVec.GetUsed(), "copiedVec & unsignedVec [Used Slot] are the same" );
    Assert_Equals( &copiedVec[0] != &unsignedVec[0], "copiedVec[0] & unsignedVec[0] address are not the same");
    Assert_Equals( &copiedVec[1] != &unsignedVec[1], "copiedVec[1] & unsignedVec[1] address are not the same");
    Assert_Equals( &copiedVec[2] != &unsignedVec[2], "copiedVec[2] & unsignedVec[2] address are not the same");
    Assert_Equals( &copiedVec[3] != &unsignedVec[3], "copiedVec[3] & unsignedVec[3] address are not the same");
    Assert_Equals(
        copiedVec[0] == unsignedVec[0] &&
        copiedVec[1] == unsignedVec[1] &&
        copiedVec[2] == unsignedVec[2] &&
        copiedVec[3] == unsignedVec[3],
        "copiedVec[0][1][2][3][4] & unsignedVec[0][1][2][3][4] elements are with the same value"
    );
    std::cout << "\t--> Output of copiedVec: ";
    for( unsigned *ptr = copiedVec.Start(); ptr != copiedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << "\n\t--> Output of unsignedVec: ";
    for( unsigned i(0); i< unsignedVec.GetUsed(); i++ )
    {
        std::cout << unsignedVec[i] << " ";
    }
    std::cout << std::endl;
}

void TestEqualsAssignmentOperator()
{
    Vector<unsigned> unsignedVec;
    unsignedVec.InsertLast(10);
    unsignedVec.InsertLast(20);
    unsignedVec.InsertLast(30);
    unsignedVec.InsertLast(40);

    Vector<unsigned> copiedVec = unsignedVec;
    std::cout << "\nTest on Equals Assignment Operator" << std::endl;
    Assert_Equals( copiedVec.GetCapacity() == unsignedVec.GetCapacity(), "copiedVec & unsignedVec [Capacity] are the same" );
    Assert_Equals( copiedVec.GetUsed() == unsignedVec.GetUsed(), "copiedVec & unsignedVec [Used Slot] are the same" );
    Assert_Equals( &copiedVec[0] != &unsignedVec[0], "copiedVec[0] & unsignedVec[0] address are not the same");
    Assert_Equals( &copiedVec[1] != &unsignedVec[1], "copiedVec[1] & unsignedVec[1] address are not the same");
    Assert_Equals( &copiedVec[2] != &unsignedVec[2], "copiedVec[2] & unsignedVec[2] address are not the same");
    Assert_Equals( &copiedVec[3] != &unsignedVec[3], "copiedVec[3] & unsignedVec[3] address are not the same");
    Assert_Equals(
        copiedVec[0] == unsignedVec[0] &&
        copiedVec[1] == unsignedVec[1] &&
        copiedVec[2] == unsignedVec[2] &&
        copiedVec[3] == unsignedVec[3],
        "copiedVec[0][1][2][3][4] & unsignedVec[0][1][2][3][4] elements are with the same value"
    );
    std::cout << "\t--> Output of copiedVec: ";
    for( unsigned *ptr = copiedVec.Start(); ptr != copiedVec.Finish(); ++ptr )
    {
        std::cout << *ptr << " ";
    }
    std::cout << "\n\t--> Output of unsignedVec: ";
    for( unsigned i(0); i< unsignedVec.GetUsed(); i++ )
    {
        std::cout << unsignedVec[i] << " ";
    }
    std::cout << std::endl;
}
