#pragma once

#include "assignment/private/sorting_strategy.hpp"  // SortingStrategy

namespace assignment {

  struct QuickSort final : SortingStrategy {

    /**
     * Реализация рекурсивного алгоритма быстрой сортировки (Quick Sort).
     *
     * Сложность ~ от O(n * log n) до O(n^2).
     * Элементы массива сортируются в порядке неубывания.
     *
     * Проблемы (для самостоятельного изучения):
     *  1. Массив со множеством повторяющихся элементов (проблема разбиения).
     *  2. Выбор опорного элемента: медиана (best), median of three, random, left/right/middle (worst).
     *  3. Скрытая сложность сортировки маленьких массивов (< 10-30 элементов).
     *
     * @param arr - массив элементов
     *
     * @see https://en.wikipedia.org/wiki/Quicksort (есть страница на русском)
     */
    void Sort(std::vector<int>& arr) const override;

   private:
    /**
     * Вспомогательный метод для реализации быстрой сортировки.
     *
     * Алгоритм:
     *  0. Выход из рекурсии при start => stop.
     *  1. Выбор опорного элемента в области методом медианы из трех.
     *  2. Разбиение массива относительно опорного элемента (partitioning).
     *  3. Рекурсивный вызов метода для левой и правой областей.
     *
     * @param arr - массив элементов
     * @param start - индекс левой границы области сортировки (включительно)
     * @param stop - индекс правой границы области сортировки (включительно)
     */
    void quick_sort(std::vector<int>& arr, int start, int stop) const;
  };

}  // namespace assignment