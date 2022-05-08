#include <catch2/catch.hpp>

#include <algorithm>  // is_sorted

#include "assignment/heap_sort.hpp"  // HeapSort, Heapify, BuildMaxHeap
#include "utils.hpp"                 // rand_array

using assignment::HeapSort;

using Catch::Equals;
using Catch::UnorderedEquals;

TEST_CASE("HeapSort::BuildMaxHeap") {

  GENERATE(range(0, 50));

  const int size = GENERATE(range(0, 100));
  const auto arr = utils::rand_array(size, -100, 100);

  auto heap = arr;
  HeapSort::BuildMaxHeap(heap);

  for (int index = 0; index < heap.size(); index++) {

    const int left_child = HeapSort::LeftChild(index);
    const int right_child = HeapSort::LeftChild(index);

    if (left_child >= heap.size()) {
      break;
    }

    CHECK(heap[index] >= heap[left_child]);

    if (right_child >= heap.size()) {
      break;
    }

    CHECK(heap[index] >= heap[right_child]);
  }

  CHECK_THAT(heap, UnorderedEquals(arr));
}

TEST_CASE("HeapSort::Sort") {

  HeapSort sort;

  GENERATE(range(0, 50));

  const int size = GENERATE(range(1, 100));
  auto arr = utils::rand_array(size, -100, 100);

  auto arr_expected = arr;
  std::sort(arr_expected.begin(), arr_expected.end());

  sort.Sort(arr);

  REQUIRE(std::is_sorted(arr.begin(), arr.end()));
  CHECK_THAT(arr_expected, Equals(arr));
}