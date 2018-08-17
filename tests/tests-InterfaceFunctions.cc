#include "catch.hpp"
#include <ai>

TEST_CASE("Show progress-bar", "[InterfaceFunctions]"){
    REQUIRE_THROWS_AS(ai::showProgressBar(0.5, 10), std::runtime_error);
}

TEST_CASE("Print line", "[InterfaceFunctions]"){
    REQUIRE_THROWS_AS(ai::printLine("line", 10), std::runtime_error);
}