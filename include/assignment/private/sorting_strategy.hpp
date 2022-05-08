#pragma once

#include <vector>

namespace assignment {

  struct SortingStrategy {

    virtual ~SortingStrategy() = default;

    /**
     * Сортировка массива в порядке неубывания.
     *
     * @param arr - массив элементов
     */
    virtual void Sort(std::vector<int> &arr) const = 0;
  };

}  // namespace assignment