#include <gtest/gtest.h>
#include "AnyType.cpp"

TEST(AnyType_Constructor, bool)
{
    AnyType ob(true);
    ASSERT_EQ(ob.dataType(), "Bool");
    ASSERT_EQ(ob.toBool(), 1);
}

TEST(AnyType_Constructor, char)
{
    AnyType ob('c');
    ASSERT_EQ(ob.dataType(), "Char");
    ASSERT_EQ(ob.toChar(), 'c');
}

TEST(AnyType_Constructor, int)
{
    AnyType ob(10);
    ASSERT_EQ(ob.dataType(), "Int");
    ASSERT_EQ(ob.toInt(), 10);
}

TEST(AnyType_Constructor, float)
{
    AnyType ob(4.2f);
    ASSERT_EQ(ob.dataType(), "Float");
    ASSERT_EQ(ob.toFloat(), 4.2f);
}

TEST(AnyType_Constructor, double)
{
    AnyType ob(4.2);
    ASSERT_EQ(ob.dataType(), "Double");
    ASSERT_EQ(ob.toDouble(), 4.2);
}

TEST(AnyType_Constructor, copy)
{
    AnyType ob('c');
    AnyType obcpy(ob);
    ASSERT_EQ(obcpy.dataType(), "Char");
    ASSERT_EQ(obcpy.toChar(), 'c');
}

TEST(AnyType_Constructor, move)
{
    AnyType ob('c');
    AnyType obmv(std::move(ob));
    ASSERT_EQ(obmv.dataType(), "Char");
    ASSERT_EQ(obmv.toChar(), 'c');
    ASSERT_EQ(ob.dataType(), "There is no stored value");
}

TEST(AnyType_Assig, bool)
{
    AnyType ob(true);
    ASSERT_EQ(ob.dataType(), "Bool");
    ASSERT_EQ(ob.toBool(), true);
    ob = false;
    ASSERT_EQ(ob.toBool(), false);
}

TEST(AnyType_Assig, char)
{
    AnyType ob('c');
    ASSERT_EQ(ob.dataType(), "Char");
    ASSERT_EQ(ob.toChar(), 'c');
    ob = 'd';
    ASSERT_EQ(ob.toChar(), 'd');
}

TEST(AnyType_Assig, int)
{
    AnyType ob(10);
    ASSERT_EQ(ob.dataType(), "Int");
    ASSERT_EQ(ob.toInt(), 10);
    ob = 1;
    ASSERT_EQ(ob.toInt(), 1);
}

TEST(AnyType_Assig, float)
{
    AnyType ob(4.2f);
    ASSERT_EQ(ob.dataType(), "Float");
    ASSERT_EQ(ob.toFloat(), 4.2f);
    ob = 3.2f;
    ASSERT_EQ(ob.toFloat(), 3.2f);
}

TEST(AnyType_Assig, double)
{
    AnyType ob(4.2);
    ASSERT_EQ(ob.dataType(), "Double");
    ASSERT_EQ(ob.toDouble(), 4.2);
    ob = 3.2;
    ASSERT_EQ(ob.toDouble(), 3.2);
}

TEST(AnyType_Assig, copy)
{
    AnyType ob('c'), obcpy;
    ASSERT_EQ(obcpy.dataType(), "There is no stored value");
    obcpy = ob;
    ASSERT_EQ(obcpy.dataType(), "Char");
    ASSERT_EQ(obcpy.toChar(), 'c');
}

TEST(AnyType_Assig, move)
{
    AnyType ob('c'), obmv;
    ASSERT_EQ(obmv.dataType(), "There is no stored value");
    obmv = std::move(ob);
    ASSERT_EQ(obmv.dataType(), "Char");
    ASSERT_EQ(obmv.toChar(), 'c');
    ASSERT_EQ(ob.dataType(), "There is no stored value");
}

TEST(ExtractFunc, toBool)
{
    AnyType ob('c');
    ASSERT_THROW(ob.toBool(), mException);
    ob = true;
    ASSERT_NO_THROW(ob.toBool());
    ASSERT_EQ(ob.dataType(), "Bool");
}

TEST(ExtractFunc, toChar)
{
    AnyType ob(1);
    ASSERT_THROW(ob.toChar(), mException);
    ob = 'c';
    ASSERT_NO_THROW(ob.toChar());
    ASSERT_EQ(ob.dataType(), "Char");
}

TEST(ExtractFunc, toInt)
{
    AnyType ob('c');
    ASSERT_THROW(ob.toInt(), mException);
    ob = 1;
    ASSERT_NO_THROW(ob.toInt());
    ASSERT_EQ(ob.dataType(), "Int");
}

TEST(ExtractFunc, toFloat)
{
    AnyType ob('c');
    ASSERT_THROW(ob.toFloat(), mException);
    ob = 4.2f;
    ASSERT_NO_THROW(ob.toFloat());
    ASSERT_EQ(ob.dataType(), "Float");
}

TEST(ExtractFunc, toDouble)
{
    AnyType ob('c');
    ASSERT_THROW(ob.toDouble(), mException);
    ob = 4.2;
    ASSERT_NO_THROW(ob.toDouble());
    ASSERT_EQ(ob.dataType(), "Double");
}

TEST(SwapFunc, swap)
{
    AnyType ob('c'), ob1(1);
    ASSERT_EQ(ob.toChar(), 'c');
    ASSERT_EQ(ob1.toInt(), 1);
    ob.swap(ob1);
    ASSERT_THROW(ob.toChar(), mException);
    ASSERT_EQ(ob.toInt(), 1);
    ASSERT_EQ(ob1.toChar(), 'c');
}

TEST(GetTypeFunc, dataType)
{
    AnyType ob(1);
    ASSERT_NE(ob.dataType(), "There is no stored value");
    ASSERT_NE(ob.dataType(), "Bool");
    ASSERT_EQ(ob.dataType(), "Int");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}