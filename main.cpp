#include <iostream>
#include "AnyType.h"


int main()
{
    AnyType anyType = 1;
    anyType = true;
    anyType = 1.7;
    
    AnyType anyType1(std::move(anyType));

    try
    {
        int storedValue = anyType1.toInt();
    }

    catch(mException& ex)
    {
        std::cout << ex.getExceptionInfo() << '\n';
    }

    double storedValue = anyType1.toDouble();
    std::cout << storedValue << std::endl;
    
    return 0;
}
