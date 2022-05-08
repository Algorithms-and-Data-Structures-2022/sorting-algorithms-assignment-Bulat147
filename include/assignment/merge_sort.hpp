#pragma once

#include "assignment/private/sorting_strategy.hpp"  // SortingStrategy

namespace assignment {

  struct MergeSort final : SortingStrategy {

    /**
     * Рекурсивная реализация сортировки слиянием (Merge Sort).
     *
     * Сложность ~ O(n * log n).
     *
     * Элементы массива сортируются в порядке неубывания.
     *
     * Проблемы:
     *  1. Требуется выделение буфера для реализации операции слияния.
     *
     * @param arr - массив элементов
     *
     * @see https://en.wikipedia.org/wiki/Merge_sort (страницы на русском так себе)
     */
    void Sort(std::vector<int>& arr) const override;

   private:
    /**
     * Вспомогательный метод для реализации сортировки слиянием.
     *
     * 0. Выход из рекурсии при start >= stop.
     * 1. Разбиение массива на подмассивы по середине области.
     * 2. Слияние отсортированных подмассивов (merge).
     *
     * @param arr
     * @param start
     * @param stop
     * @param buf
     */
    void merge_sort(std::vector<int>& arr, int start, int stop, std::vector<int>& buf) const;
  };

}  // namespace assignment