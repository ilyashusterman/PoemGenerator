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
TEST(FirstTestGroup, TEST_FirstTestGroup_TestHaveSimilarEnding_Test)
{
    CHECK_TRUE(poemgenerator->haveSimilarEnding("yo yo yo yo", "yo yo yo yo", 2) == 1);
    CHECK_TRUE(poemgenerator->haveSimilarEnding("yo yo yo yo", "yo yo yo he", 2) == 0);
    CHECK_TRUE(poemgenerator->haveSimilarEnding("yo yo yo weed", "yo yo yo seed", 2) == 1);
    CHECK_TRUE(poemgenerator->haveSimilarEnding("yo yo yo yooo", "yo yo yo seed", 2) == 0);
//    CHECK_TRUE(poemgenerator->haveSimilarEnding("yo yo yo yooo", "yo yo yo seed", 5) == 1);
}