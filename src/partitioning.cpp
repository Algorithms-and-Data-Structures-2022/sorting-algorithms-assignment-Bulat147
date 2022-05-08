#include "assignment/partitioning.hpp"

#include <utility>  // swap
#include <cassert>  // assert

namespace assignment {

  int middle_of(int start, int stop) {

    // вычисляем размер области
    const int size = stop - start + 1;

    // случай 1: нечетный размер
    if (size % 2 == 1) {
      return start + (size - 1) / 2;
    }

    // случай 2: четный размер
    return start + size / 2;
  }

  int median_of_three(const std::vector<int>& arr, int start, int stop) {
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    // вычисляем размер области
    const int size = stop - start + 1;

    // В случае отсутствия как минимум 3 элементов в указанной области,
    // возвращаем индекс правой границы.
    if (size < 3) {
      return stop;
    }

    // вычисляем индекс середины заданной области
    const int middle = middle_of(start, stop);

    // поиск медианы среди трех элементов по индексам start, middle и stop

    // Здесь должна быть ваша реализация ...

    return -1;
  }

  int partition(std::vector<int>& arr, int start, int stop, int pivot) {
    assert(pivot >= start && pivot <= stop);
    assert(!arr.empty() && start >= 0 && stop < arr.size() && start <= stop);

    // Tips:
    // 1. Переместите опорный элемент в конец области (потом вернем на нужно место)
    // 2. Заведите переменную "индекс опорного элемента" = начало области (он будет обновляться)
    // 3. Пройдитесь в цикле по всем индексам (конец исключительно) и произведите разбиение,
    //    передвигая "индекс опорного элемента" в определенных случая вправо.
    // 4. По завершении цикла в "индексе опорного элемента" находится значение корректной позиции для опорного элемента,
    //    переместите опорный элемент на корректную позицию.

    // значение опорного элемента
    const int pivot_value = arr[pivot];

    // переместить опорный элемент в конец (чтобы не мешался)
    std::swap(arr[pivot], arr[stop]);

    // индекс опорного элемента (будет вычисляться далее, изначально находится в начале области)
    int curr_pivot_index = start;

    // вычисление индекса опорного элемента и перемещение элементов по правилу разбиения
    for (int index = start; index < stop; index++) {
      // Напишите здесь ваш код ...
    }

    // Напишите здесь ваш код ...

    // возвращаем индекс опорного элемента
    return curr_pivot_index;
  }

}  // namespace assignment