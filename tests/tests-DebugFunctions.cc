#include "catch.hpp"
#include <ai>

TEST_CASE("Return an ID", "[DebugFunctions]"){
    REQUIRE(1 == ai::counter());
    REQUIRE(2 == ai::counter());
    REQUIRE(5 == ai::counter(5));
    REQUIRE(6 == ai::counter());
}

TEST_CASE("Return a marker with an ID", "[DebugFunctions]"){
    REQUIRE(std::string("Marker #1") == ai::marker());
    REQUIRE(std::string("Marker #2") == ai::marker());
    REQUIRE(std::string("Marker #5") == ai::marker(5));
    REQUIRE(std::string("Marker #6") == ai::marker());
}