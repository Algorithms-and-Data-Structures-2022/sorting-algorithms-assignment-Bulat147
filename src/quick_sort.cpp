#include "assignment/quick_sort.hpp"

#include "assignment/partitioning.hpp"  // partition, median_of_three

namespace assignment {

  std::vector<int> QuickSort::Sort(const std::vector<int>& arr) const {

    // копируем массив
    std::vector<int> sorted_arr = arr;

    // Напишите здесь свой код ...
    // qsort_helper ...

    return sorted_arr;
  }

  void QuickSort::qsort_helper(std::vector<int>& arr, int start, int stop) const {

    // выходим из рекурсии
    if (start >= stop) {
      return;
    }

    // вычисляем индекс опорного элемента
    int pivot_index = -1 /* напишите здесь свой код ... */;

    // производим разбиение относительно опорного элемента ...
    // рекурсивно повторяем процедуру над левой и правой частью ...
  }

}  // namespace assignment
