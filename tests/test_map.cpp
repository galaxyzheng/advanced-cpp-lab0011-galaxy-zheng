#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "project/map.h"

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

TEST_CASE("Map starts empty") {
    Map map;
    REQUIRE(map.empty());
    REQUIRE(map.size() == 0u);
    REQUIRE_FALSE(map.contains("alpha"));
}

TEST_CASE("Map inserts values and reports size") {
    Map map;
    REQUIRE(map.insert("alpha", 10));
    REQUIRE(map.insert("beta", 20));
    REQUIRE(map.insert("gamma", 30));

    REQUIRE_FALSE(map.empty());
    REQUIRE(map.size() == 3u);
    REQUIRE(map.contains("alpha"));
    REQUIRE(map.contains("gamma"));
    REQUIRE_FALSE(map.contains("delta"));
}

TEST_CASE("Map rejects duplicate keys") {
    Map map;
    REQUIRE(map.insert("alpha", 10));
    REQUIRE_FALSE(map.insert("alpha", 99));
    REQUIRE(map.size() == 1u);
    REQUIRE(map.at("alpha") == 10);
}

TEST_CASE("Map update modifies an existing value") {
    Map map;
    map.insert("apple", 5);
    map.insert("banana", 7);

    REQUIRE(map.update("apple", 42));
    REQUIRE(map.at("apple") == 42);
    REQUIRE_FALSE(map.update("pear", 99));
}

TEST_CASE("Map erase removes keys and updates size") {
    Map map;
    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 3);

    REQUIRE(map.erase("two"));
    REQUIRE_FALSE(map.contains("two"));
    REQUIRE(map.size() == 2u);
    REQUIRE_FALSE(map.erase("missing"));
}

TEST_CASE("Map at throws for missing keys") {
    Map map;
    map.insert("first", 1);

    REQUIRE(map.at("first") == 1);
    REQUIRE_THROWS_AS(map.at("missing"), std::logic_error);
}

TEST_CASE("Map keys and values reflect stored entries") {
    Map map;
    map.insert("zebra", 9);
    map.insert("apple", 1);
    map.insert("mango", 3);

    auto keys = map.keys();
    auto values = map.values();

    REQUIRE(keys.size() == 3u);
    REQUIRE(values.size() == 3u);
    REQUIRE(std::find(keys.begin(), keys.end(), "apple") != keys.end());
    REQUIRE(std::find(values.begin(), values.end(), 3) != values.end());
}

TEST_CASE("Map can be checked for sorted order") {
    Map map;
    map.insert("c", 3);
    map.insert("a", 1);
    map.insert("b", 2);

    REQUIRE(map.isSorted());
}

TEST_CASE("Map handles many keys with repeated updates") {
    Map map;
    for (int i = 0; i < 10; ++i) {
        map.insert("key" + std::to_string(i), i * 10);
    }

    REQUIRE(map.size() == 10u);
    REQUIRE(map.at("key7") == 70);
    REQUIRE(map.update("key7", 777));
    REQUIRE(map.at("key7") == 777);
}

TEST_CASE("Map supports negative and zero values") {
    Map map;
    map.insert("zero", 0);
    map.insert("neg", -5);
    map.insert("positive", 25);

    REQUIRE(map.at("zero") == 0);
    REQUIRE(map.at("neg") == -5);
    REQUIRE(map.at("positive") == 25);
}
