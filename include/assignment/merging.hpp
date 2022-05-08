#pragma once

#include <vector>

namespace assignment {

  /**
   * Слияние двух отсортированных подмассивов в один массив.
   *
   * Подмассивы
   *  - левый: [start, middle]
   *  - правый: [middle + 1, stop]
   *
   * @param arr - массив элементов
   * @param start - начало области левого подмассива (включительно)
   * @param middle - конец области левого подмассива (включительно)
   * @param stop - конец области правого подмассива (включительно)
   * @param buf - буфер для слияния (одинакового размера с arr)
   */
  void merge(std::vector<int>& arr, int start, int middle, int stop, std::vector<int>& buf);

}  // namespace assignment