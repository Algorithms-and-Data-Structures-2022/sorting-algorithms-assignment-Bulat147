#pragma once

#include "assignment/private/sorting_strategy.hpp"  // SortingStrategy

#include <vector>

namespace assignment {

  struct HeapSort final : SortingStrategy {

    /**
     * Реализация итеративного алгоритма сортировки кучей.
     *
     * Сложность
     *  по памяти ~ O(1)
     *  по времени ~ O(n * log n)
     *
     *  В реализации используется максимальная двоичная куча.
     *
     * Проблемы (для самостоятельного изучения):
     * 1. Сложность не зависит от степени отсортированности входного массива.
     * 2. В процесс работы производит хаотичный доступ к памяти (плохо сочетается с кешированием).
     * 3. Не подлежит распараллеливанию.
     *
     * @param arr - массив элементов
     * @return отсортированный массив (в порядке неубывания)
     *
     * @see https://en.wikipedia.org/wiki/Heapsort (есть страница на русском)
     */
    std::vector<int> Sort(const std::vector<int>& arr) const override;

    /**
     * Построение максимальной двоичной кучи.
     *
     * Сложность ~ O(n).
     *
     * Перемещение элементов входного массива таким образом,
     * чтобы массив удовлетворял свойствам максимальной двоичной кучи.
     *
     * @param arr - массив элементов
     *
     * @see https://www.geeksforgeeks.org/building-heap-from-array
     */
    static void BuildMaxHeap(std::vector<int>& arr);

    /**
     * Итеративная реализация спуска элемента вниз по двоичной куче.
     *
     * @param arr - массив элементов
     * @param heap_size - размер двоичной кучи (от 0 до heap_size - 1)
     * @param index индекс спускаемого элемента
     */
    static void Heapify(std::vector<int>& arr, int heap_size, int index);

    // вспомогательные методы для вычисления индексов в двоичной куче
    static int Parent(int index);
    static int LeftChild(int index);
    static int RightChild(int index);
  };

}  // namespace assignment