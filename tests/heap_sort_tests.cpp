#include <catch2/catch.hpp>

#include <queue>

#include "assignment/heap_sort.hpp"  // HeapSort, Heapify, BuildMaxHeap
#include "utils.hpp"                 // rand_array

using assignment::HeapSort;

using Catch::Equals;
using Catch::UnorderedEquals;

TEST_CASE("HeapSort::BuildMaxHeap") {

  GENERATE(range(0, 100));

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

  GENERATE(range(0, 100));

  HeapSort sort;

  const int size = GENERATE(range(1, 100));
  auto arr = utils::rand_array(size, -100, 100);

  const auto sorted_arr = sort.Sort(arr);

  CAPTURE(arr);

  std::sort(arr.begin(), arr.end());

  CHECK_THAT(sorted_arr, Equals(arr));
}