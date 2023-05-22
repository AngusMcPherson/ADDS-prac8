#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <cmath> // for floor()

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();
  Heap(std::vector<T>);
  void insert(T);
  void remove(T);
  T getMin();
};

template <typename T>
Heap<T>::Heap() {}

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }
  int initial_parent_index = floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}
template <typename T>
void Heap<T>::insert(T value) {
   values.push_back(value);
   auto it = find(values.begin(), values.end(), value);
   int index = it - values.begin();
   int initial_parent_index = floor((index-1)/2);
  for (int parent_index = initial_parent_index; parent_index >= 0; parent_index--) {
    heapify(parent_index);
  }
   
}

template <typename T>
void Heap<T>::remove(T value) {
  int index = -1;
  for (int i = 0; i < values.size(); i++) {
    if (values[i] == value) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    values[index] = values.back();
    values.pop_back();
    heapify(index);
  }
}

template <typename T>
T Heap<T>::getMin() {
  return values.at(0);
}

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;
  }

  // move up the 'tree' to grandparent
  int grandparent = floor(parent_index/2) - 1;
  heapify(grandparent);
}

#endif