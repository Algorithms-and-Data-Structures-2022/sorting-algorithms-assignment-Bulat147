#include <catch2/catch.hpp>

#include "assignment/quick_sort.hpp"  // QuickSort
#include "utils.hpp"                  // rand_array

using assignment::QuickSort;
using Catch::Equals;

TEST_CASE("QuickSort::Sort") {

  QuickSort sort;

  GENERATE(range(0, 100));

  const int size = GENERATE(range(0, 100));
  auto arr = utils::rand_array(size, -100, 100);

  const auto sorted_arr = sort.Sort(arr);

  std::sort(arr.begin(), arr.end());

  CHECK_THAT(sorted_arr, Equals(arr));
}