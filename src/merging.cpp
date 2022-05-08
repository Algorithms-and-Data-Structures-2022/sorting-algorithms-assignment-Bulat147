#include "assignment/merging.hpp"

#include <cassert>    // assert
#include <algorithm>  // copy

namespace assignment {

  void merge(std::vector<int>& arr, int start, int middle, int stop, std::vector<int>& buf) {
    assert(start >= 0 && start < arr.size() && stop >= start && stop < arr.size() && middle >= start && middle <= stop);

    // индексы текущих элементов левого и правого подмассивов
    int left_offset = start;
    int right_offset = middle + 1;

    // индекс текущей позиции буфера (туда будут сливаться подмассивы)
    int buf_offset = -1 /* здесь что-то не так */;

    // слияния подмассивов (пока не достигли конца одного из подмассивов)
    while (left_offset <= middle && right_offset <= stop) {

      // копируем элемент с наименьшим значением в буфер ...

      // перемещаем текущую позицию вставки в буфер
      buf_offset += 1;
    }

    // сливаем остатки подмассивов (останутся элементы только одного из двух подмассивов)
    for (/* ... */; left_offset <= middle; left_offset++) {
      buf[buf_offset] = arr[left_offset];
      buf_offset += 1;
    }

    // реализуйте сливание остатков правого подмассива ...

    // копируем результат слияния подмассивов из буфера в оригинальный массив ... std::copy или цикл for ...
  }

}  // namespace assignment