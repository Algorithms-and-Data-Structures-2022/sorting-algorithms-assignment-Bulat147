#include <iostream>

#include "assignment/partitioning.hpp"
#include "assignment/quick_sort.hpp"

#include "assignment/heap_sort.hpp"

using namespace std;
using namespace assignment;

int main() {

  std::vector<int> arr = {62, 66, -13};

  HeapSort sort;
  for (int item : sort.Sort(arr)) {
    cout << item << '\n';
  }



  return 0;
}
