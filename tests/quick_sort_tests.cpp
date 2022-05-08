#include <catch2/catch.hpp>

#include <algorithm>  // is_sorted

#include "assignment/quick_sort.hpp"  // QuickSort
#include "utils.hpp"                  // rand_array

using assignment::QuickSort;
using Catch::Equals;

TEST_CASE("QuickSort::Sort") {

  QuickSort sort;

  GENERATE(range(0, 50));

  const int size = GENERATE(range(1, 100));
  auto arr = utils::rand_array(size, -100, 100);

  auto arr_expected = arr;
  std::sort(arr_expected.begin(), arr_expected.end());

  sort.Sort(arr);

  REQUIRE(std::is_sorted(arr.begin(), arr.end()));
  CHECK_THAT(arr_expected, Equals(arr));
}