#pragma once

#include <functional>  // function

#include "assignment/private/sorting_strategy.hpp"  // SortingStrategy

namespace assignment {

  /**
   * Линейный поиск позиции вставки элемента в левый подмассив.
   *
   * @param arr - массив элементов
   * @param index - текущая позиция вставляемого элемента
   * @return позиция вставки элемента
   */
  int linear_search(const std::vector<int>& arr, int index);

  /**
   * Двоичный поиск позиции вставки элемента в левый подмассив.
   *
   * @param arr - массив элементов
   * @param index - текущая позиция вставляемого элемента
   * @return позиция вставки элемента
   */
  int binary_search(const std::vector<int>& arr, int index);

  struct InsertionSort final : SortingStrategy {

    // тип данных: функция от ссылки на вектор и целого числа, возвращающая целое число
    using Searcher = std::function<int(std::vector<int>&, int)>;

    /**
     * Создание объекта сортировки вставками.
     *
     * @param searcher - алгоритм поиска места вставки
     */
    explicit InsertionSort(Searcher searcher = linear_search);

    /**
     * Реализация алгоритма сортировки вставками.
     *
     * Сложность ~ от O(n) до O(n^2).
     *
     * Отлично подходит для сортировки небольших массивов (размерности не более ~ 30).
     *
     * @param arr - массив элементов
     */
    void Sort(std::vector<int>& arr) const override;

   private:
    // алгоритм (функция) поиска позиции вставки
    const Searcher searcher_;
  };

}  // namespace assignment