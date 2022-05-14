#include "assignment/insertion_sort.hpp"

#include <utility>  // move, swap

#include "assignment/partitioning.hpp"  // middle_of

namespace assignment {

  int linear_search(const std::vector<int>& arr, int index) {
// А тут случайно сортировка не в обратном порядке - от большего к меньшему?
    // итерация всех предыдущих элементов [0, index - 1] (они находятся в отсортированном порядке)
    for (int curr_pos = index-1; curr_pos > -1; curr_pos--) {
      // если текущий элемент меньше или равен вставляемому, позиция для вставки найдена ...
      if (arr[curr_pos] <= arr[index]){
          return curr_pos+1; // т.к. иначе один меньший эл-нт пойдет вправо, что нельзя допустить
      }
    }
    return 0;  // все эл-нты оказались больше
  }

  int binary_search(const std::vector<int>& arr, int index) {

    // начало, конец и середина области поиска места для вставки [0, index - 1]
    int start = 0; /* здесь что-то не так ... */;
    int stop = index-1; /* здесь что-то не так ... */;
    int middle = middle_of(start,stop);

    // ищем до тех пор, пока границы не схлопнулись
    while (start <= stop) {

      // возвращаем позицию для вставки
      if (arr[index] == arr[middle]) {
        return middle; /* здесь что-то не так ... */;
      }

      // обновляем границы области поиска ...
      if (arr[index] < arr[middle]){
        stop = middle-1;
      }
      else if (arr[index] > arr[middle]){
        start = middle+1;
      }
      // обновляем середину области поиска
      middle = middle_of(start, stop);  // здесь что-то не так ...
    }

    // в конечном счете возвращаем начало последней области поиска (Круто)
    return start;  // здесь что-то не так ...
  }

  void InsertionSort::Sort(std::vector<int>& arr) const {

    // - проходимся по элементам, начиная со второго
    // - после каждой итерации, слева от index будет формироваться отсортированный массив
    // - первый элемент слева считается отсортированным
    for (int index = 1; index < static_cast<int>(arr.size()); index++) {

      // поиск индекса для вставки элемента с индексом index в область [0, index - 1]
      const int ins_index = searcher_(arr, index);

      // если индекс вставки не совпадает с текущей позицией элемента,
      // производим вставку элемента на вычисленную позицию (std::copy или цикл for) ...
      if (ins_index != index){
        int last;
        int temp;
        for (int i = ins_index; i < index+1; i++){
          if (i==ins_index){
            last = arr[i];
            arr[i] = arr[index];
          }
          else{
            temp = arr[i];
            arr[i] = last;
            last = temp;
          }
        }
      }
    }
  }

  InsertionSort::InsertionSort(Searcher searcher) : searcher_{std::move(searcher)} {}

}  // namespace assignment