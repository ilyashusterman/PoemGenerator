//
// Created by ilya on 06/05/18.
//

#include "TestPoemGenerator.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
    STRCMP_EQUAL("world", "world");
}