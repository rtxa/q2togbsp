#include <doctest/doctest.h>

#include <parser/QuakeParser.h>
#include <parser/QuakeParserException.h>
#include <structures/QuakeMap.h>

#include <iostream>
#include <string>

TEST_CASE("Test EOF while parsing") {
    QuakeMap map;

    SUBCASE("Expect EOF while parsing brush") {
        CHECK_THROWS(QuakeParser().parse("test_data/eof_in_brushface.map"));
    }

    SUBCASE("Expect EOF while parsing entity") {
        CHECK_THROWS(QuakeParser().parse("test_data/eof_in_entity.map"));
    }
}