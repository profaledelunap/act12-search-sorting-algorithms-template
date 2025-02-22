// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include <fstream>
#include <vector>
#include "catch.h"
#include "sort.h"
#include "vectorExtras.h"

using namespace std;

TEST_CASE("Testing ordering algorithms", "[orderingAlgos]")
{
    vector<int> vec, vecBubble;
    int compBubble = 0, compInsert = 0, compSelect = 0;

    read(vec, "files/output1vec.txt");
    read(vecBubble, "files/input1vec.txt");
    vector<int> vecInsert(vecBubble);
    vector<int> vecSelect(vecBubble);

    bubbleSort(vecBubble, compBubble);
    insertionSort(vecInsert, compInsert);
    selectionSort(vecSelect, compSelect);

    SECTION("Number of comparisons")
    {
        bool compBubbleB = 73829 <= compBubble && compBubble <= 73892 ? true : false;
        REQUIRE(compBubbleB);
        REQUIRE(compInsert == 37107);
        REQUIRE(compSelect == 73920);
    }
    SECTION("Ordered vectors")
    {
        REQUIRE(vec == vecBubble);
        REQUIRE(vec == vecInsert);
        REQUIRE(vec == vecSelect);
    }
}
