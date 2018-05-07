//
// Created by ilya on 06/05/18.
//

#include "TestPoemGenerator.h"
#include "CppUTest/TestHarness.h"
#include "../src/PoemGenerator.h"

TEST_GROUP(FirstTestGroup)
{
    PoemGenerator* poemgenerator;
    void setup(){
        poemgenerator = new PoemGenerator();
    }
    void teardown()
    {
        delete poemgenerator;
    }
};

TEST(FirstTestGroup, FirstTest)
{
    LONGS_EQUAL(poemgenerator->applyRow(), 2);
}