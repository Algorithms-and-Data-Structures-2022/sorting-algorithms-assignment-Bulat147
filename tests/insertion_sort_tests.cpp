#include <catch2/catch.hpp>

#include <algorithm>  // is_sorted

#include "assignment/insertion_sort.hpp"  // InsertionSort
#include "utils.hpp"                      // rand_array

using Catch::Equals;

using assignment::binary_search;
using assignment::InsertionSort;
using assignment::linear_search;

TEST_CASE("InsertionSort::Sort") {

  SECTION("Linear Search") {
    auto sort = InsertionSort(linear_search);

    GENERATE(range(0, 10));

    const int size = GENERATE(range(1, 100), 1000, 10000);
    auto arr = utils::rand_array(size, -100, 100);

    auto arr_expected = arr;
    std::sort(arr_expected.begin(), arr_expected.end());

    sort.Sort(arr);

    REQUIRE(std::is_sorted(arr.begin(), arr.end()));
    CHECK_THAT(arr_expected, Equals(arr));
  }

  SECTION("Binary Search") {
    auto sort = InsertionSort(binary_search);

    GENERATE(range(0, 10));

    const int size = GENERATE(range(1, 100), 1000, 10000);
    auto arr = utils::rand_array(size, -100, 100);

    auto arr_expected = arr;
    std::sort(arr_expected.begin(), arr_expected.end());

    sort.Sort(arr);

    REQUIRE(std::is_sorted(arr.begin(), arr.end()));
    CHECK_THAT(arr_expected, Equals(arr));
  }
}