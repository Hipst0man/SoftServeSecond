#include <iostream>
#include "AnyType.h"


int main()
{
    AnyType anyType = 1;
    anyType = true;
    anyType = 1.7;
    
    AnyType anyType1(std::move(AnyType(2.0)));
    anyType1.swap(anyType);

    try
    {
        int storedValue = anyType1.toInt();
    }

    catch(mException& ex)
    {
        std::cout << ex.what() << '\n';
    }

    double storedValue = anyType1.toDouble();
    std::cout << storedValue << " " << anyType1.dataType() << std::endl;
    
    return 0;
}
