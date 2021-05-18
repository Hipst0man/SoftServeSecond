#include <iostream>

class mException : public std::exception
{
private:
    std::string info;
public:
    mException(std::string _info) : info(_info) {}
    std::string what() {return info;}
};

union DataUnion
{
    bool bool_var;
    char char_var;
    int int_var;
    float float_var;
    double double_var;   
};

class AnyType
{
    DataUnion data;
    size_t type_hash;
    
public:

    AnyType() = delete;
    AnyType(bool val);
    AnyType(char val);
    AnyType(int val);
    AnyType(float val);
    AnyType(double val);
    AnyType(const AnyType& copy);
    AnyType(AnyType&& copy);
    
    ~AnyType();

    AnyType& operator= (const AnyType& copy);
    AnyType& operator= (AnyType&& copy);
    AnyType& operator= (const bool val);
    AnyType& operator= (const char val);
    AnyType& operator= (const int val);
    AnyType& operator= (const float val);
    AnyType& operator= (const double val);

    bool toBool() const;
    char toChar() const;
    int toInt() const;
    float toFloat() const;
    double toDouble() const;

    void swap(AnyType& right);
    std::string dataType();
    
};
