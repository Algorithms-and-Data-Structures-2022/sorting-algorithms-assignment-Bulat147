#include <catch2/catch.hpp>

#include <cmath>  // min

#include "assignment/partitioning.hpp"  // partition, median_of_three
#include "utils.hpp"                    // rand_array

using assignment::median_of_three;
using assignment::partition;

TEST_CASE("Partition::MedianOfThree") {

  GENERATE(range(0, 10));

  SECTION("array size < 3") {

    const int size = GENERATE(range(1, 16));
    const auto arr = utils::rand_array(size, -100, 100, true);

    const int start = GENERATE_REF(range(0, size));
    const int stop = GENERATE_REF(range(start, std::min(start + 2, size)));

    const int pivot = median_of_three(arr, start, stop);

    CAPTURE(arr, start, stop, pivot);

    CHECK(pivot == stop);
    CHECK(arr[pivot] == arr[stop]);
  }

  SECTION("array size >= 3") {

    const int size = GENERATE(range(3, 16));
    const auto arr = utils::rand_array(size, -100, 100, true);

    const int start = GENERATE_REF(range(0, std::min(size - 2, 3)));
    const int stop = GENERATE_REF(range(start + 2, size));
    const int mid_index = assignment::middle_of(start, stop);

    const int pivot = median_of_three(arr, start, stop);

    CAPTURE(arr, start, mid_index, stop, pivot);

    REQUIRE(pivot >= start);
    REQUIRE(pivot <= stop);

    std::vector<int> arr_start_mid_stop = {arr[start], arr[mid_index], arr[stop]};
    std::sort(arr_start_mid_stop.begin(), arr_start_mid_stop.end());

    CHECK(arr[pivot] >= arr_start_mid_stop.front());
    CHECK(arr[pivot] <= arr_start_mid_stop.back());

    CHECK((pivot == mid_index || pivot == start || pivot == stop));
  }
}

TEST_CASE("Partition::Partition") {

  GENERATE(range(0, 10));

  const int size = GENERATE(range(1, 16));
  auto arr = utils::rand_array(size, -100, 100);

  const int start = GENERATE_REF(range(0, size));
  const int stop = GENERATE_REF(range(start, size));

  int pivot = median_of_three(arr, start, stop);
  pivot = partition(arr, start, stop, pivot);

  CAPTURE(arr, start, stop, pivot, arr[pivot]);

  for (int index = start; index < pivot; index++) {
    CHECK(arr[index] < arr[pivot]);
  }

  for (int index = pivot + 1; index <= stop; index++) {
    CHECK(arr[index] >= arr[pivot]);
  }
}
