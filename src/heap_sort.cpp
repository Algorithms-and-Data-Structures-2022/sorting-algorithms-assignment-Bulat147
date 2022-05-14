#include "assignment/heap_sort.hpp"

#include <utility>  // swap
#include <cassert>  // assert

namespace assignment {

  void HeapSort::Sort(std::vector<int>& arr) const {

    // строим двоичную кучу ... BuildMaxHeap ...
    BuildMaxHeap(arr);

    // обходим элементы кучи с конца до корня (не включительно)
    for (int index = static_cast<int>(arr.size()) - 1; index > 0; index--) {
      // обмениваем местами корень (максимальный элемент) и последний элемент кучи ... std::swap ...
      // спускаем новый корневой узел вниз ... Heapify ...
      std::swap(arr[index], arr[0]);
      Heapify(arr, index-1, 0);
    }
  }

  void HeapSort::BuildMaxHeap(std::vector<int>& arr) {

    // Комментарии:
    // - построение начинается с последнего не листового узла (листовые узлы спускать не нужно - лишняя операция)
    // - индекс последнего не листового узла = parent (size - 1) = ((size - 1) - 1) / 2 = size / 2 - 1
    // - индекс идет до корня (включительно)

    const int size = static_cast<int>(arr.size());
    if (size <= 1){
      return;
    }
    int list_index = Parent(size-1);
    for (int i = list_index; i > -1; i--){
      Heapify(arr, size, i);
    }
  }

  void HeapSort::Heapify(std::vector<int>& arr, int heap_size, int index) {
    assert(heap_size >= 0 && heap_size <= arr.size() && index >= 0 && index < heap_size);

    // максимальный элемент устанавливаем в значение текущего индекса
    for (int largest = index; largest < heap_size;) {

      // вычисляем индексы потомков для текущего элемента
      const int left_child = LeftChild(index);
      const int right_child = RightChild(index);

      // поиск наибольшего элемента среди текущего элемента и его потомков ...
      int maxim;
      if (arr[largest] > arr[left_child]){
        if (arr[largest] > arr[right_child]){
          maxim = largest;
        }
        else{
          maxim = right_child;
        }
      }
      else{
        if (arr[left_child] > arr[right_child]){
          maxim = left_child;
        }
        else{
          maxim = right_child;
        }
      }

      // если текущий элемент больше своих потомков, то он находится на правильном месте (свойство макс. кучи)
      if (maxim == largest) {
        return;  // завершаем спуск
      }

      // обмениваем местами текущий элемент с его потомком ... std::swap ...
      std::swap(arr[largest], arr[maxim]);

      // продолжаем спуск c нового места (после операции обмена местами);
      largest = maxim;
    }
  }

  int HeapSort::Parent(int index) {
    assert(index >= 0);
    return (index - 1) / 2;
  }

  int HeapSort::LeftChild(int index) {
    assert(index >= 0);
    return 2 * index + 1;
  }

  int HeapSort::RightChild(int index) {
    assert(index >= 0);
    return 2 * index + 2;
  }

}  // namespace assignment
