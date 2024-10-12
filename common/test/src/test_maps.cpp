#include <doctest/doctest.h>

#include <parser/QuakeParser.h>

#include <iostream>
#include <string>

TEST_CASE("Test working maps") {
    SUBCASE("Basic Room") {
        QuakeMap map;
        CHECK_NOTHROW(QuakeParser().parse("test_data/basic_room.map"));
    }
}