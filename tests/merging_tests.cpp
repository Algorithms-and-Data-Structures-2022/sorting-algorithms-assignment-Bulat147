#include <catch2/catch.hpp>

#include <algorithm>  // is_sorted

#include "assignment/merging.hpp"  // merge
#include "utils.hpp"               // rand_array

using assignment::merge;
using Catch::Equals;

TEST_CASE("Merging::Merge") {

  GENERATE(range(0, 10));

  const int size = GENERATE(range(1, 32));
  const int middle = GENERATE_REF(range(0, size));

  auto arr = utils::rand_array(size, -100, 100, true);

  // sort the left and right sub-arrays
  std::sort(arr.begin(), arr.begin() + middle + 1);
  std::sort(arr.begin() + middle + 1, arr.end());

  CAPTURE(arr, size, middle);

  // sorted array
  auto sorted_arr = arr;
  std::sort(sorted_arr.begin(), sorted_arr.end());

  auto buf = std::vector<int>(arr.size());
  merge(arr, 0, middle, size - 1, buf);

  REQUIRE(std::is_sorted(arr.begin(), arr.end()));
  CHECK_THAT(arr, Equals(sorted_arr));
}