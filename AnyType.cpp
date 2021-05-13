#include "AnyType.h"


AnyType::AnyType(bool val)
{
    data.bool_var = val;
    type_hash = typeid(bool).hash_code();
}

AnyType::AnyType(char val)
{
    data.char_var= val;
    type_hash = typeid(char).hash_code();
}

AnyType::AnyType(int val)
{
    data.int_var = val;
    type_hash = typeid(int).hash_code();
}

AnyType::AnyType(float val)
{
    data.float_var = val;
    type_hash = typeid(float).hash_code();
}

AnyType::AnyType(double val)
{
    data.double_var = val;
    type_hash = typeid(double).hash_code();
}

AnyType::AnyType(const AnyType& copy)
{
    data = copy.data;
    type_hash = copy.type_hash;
}

AnyType::AnyType(AnyType&& copy)
{
    data = copy.data;
    type_hash = copy.type_hash;
    copy.data.bool_var = 0;
    copy.data.char_var = 0;
    copy.data.int_var = 0;
    copy.data.float_var = 0;
    copy.data.double_var = 0;
    copy.type_hash = 0;
}

AnyType& AnyType::operator= (const AnyType& copy)
{
    data = copy.data;
    type_hash = copy.type_hash;
    return *this;
}

AnyType& AnyType::operator= (AnyType&& copy)
{
    data = copy.data;
    type_hash = copy.type_hash;
    copy.data.bool_var = 0;
    copy.data.char_var = 0;
    copy.data.int_var = 0;
    copy.data.float_var = 0;
    copy.data.double_var = 0;
    copy.type_hash = 0;
    
    return *this;
}

AnyType& AnyType::operator= (const bool val)
{
    data.bool_var = val;
    type_hash = typeid(bool).hash_code();
    return *this;
}

AnyType& AnyType::operator= (const char val)
{
    data.char_var= val;
    type_hash = typeid(char).hash_code();
    return *this;
}

AnyType& AnyType::operator= (const int val)
{
    data.int_var = val;
    type_hash = typeid(int).hash_code();
    return *this;
}

AnyType& AnyType::operator= (const float val)
{
    data.float_var = val;
    type_hash = typeid(float).hash_code();
    return *this;
}

AnyType& AnyType::operator= (const double val)
{
    data.double_var = val;
    type_hash = typeid(double).hash_code();
    return *this;
}

bool AnyType::toBool()
{
    if (type_hash == typeid(bool).hash_code()) return data.bool_var;
    else throw mException("Unable to cast to bool");
}

char AnyType::toChar()
{
    if (type_hash == typeid(char).hash_code()) return data.char_var;
    else throw mException("Unable to cast to char");    
}

int AnyType::toInt()
{
    if (type_hash == typeid(int).hash_code()) return data.int_var;
    else throw mException("Unable to cast to int");
}

float AnyType::toFloat()
{
    if (type_hash == typeid(float).hash_code()) return data.float_var;
    else throw mException("Unable to cast to float");
}

double AnyType::toDouble()
{
    if (type_hash == typeid(double).hash_code()) return data.double_var;
    else throw mException("Unable to cast to double");
}
