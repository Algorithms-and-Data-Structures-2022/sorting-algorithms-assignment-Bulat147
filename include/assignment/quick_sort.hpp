#pragma once

#include "assignment/private/sorting_strategy.hpp"  // SortingStrategy

namespace assignment {

  struct QuickSort final : SortingStrategy {

    /**
     * Реализация рекурсивного алгоритма быстрой сортировки.
     *
     * Сложность
     *  по памяти ~ O(1)
     *  по времени ~ O(n * log n) или O(n^2) если столкнемся с проблемой разбиения.
     *
     * Проблемы (для самостоятельного изучения):
     * 1. Массив со множеством повторяющихся элементов (проблема разбиения).
     * 2. Выбор опорного элемента: медиана (best), ninther, median of three, random, left/right/middle (worst).
     * 3. Скрытая сложность сортировки маленьких массивов (< 10-30 элементов).
     * 4. Проблемы эффективной параллелизации алгоритма сортировки.
     *
     * @param arr - массив элементов
     * @return отсортированный массив (в порядке неубывания)
     *
     * @see https://en.wikipedia.org/wiki/Quicksort (есть страница на русском)
     */
    std::vector<int> Sort(const std::vector<int>& arr) const override;

   private:
    /**
     * Вспомогательный метод рекурсивной быстрой сортировки.
     *
     * Алгоритм:
     *  0. Выход из рекурсии при start => stop.
     *  1. Выбор опорного элемента в области (start = 0, stop = size - 1) методом медианы из трех.
     *  2. Разбиение массива относительно опорного элемента (partitioning).
     *  3. Рекурсивный вызов метода для левой и правой областей:
     *      a. от start до pivot - 1 (левая область)
     *      b. от pivot + 1 до stop (правая область)
     *
     * @param arr - массив элементов
     * @param start - индекс левой границы области сортировки (включительно)
     * @param stop - индекс правой границы области сортировки (включительно)
     */
    void qsort_helper(std::vector<int>& arr, int start, int stop) const;
  };

}  // namespace assignment