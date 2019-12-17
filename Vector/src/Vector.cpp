#include <cstring>
#include <cassert>
#include "../Vector.h"

namespace JG {

template <typename E>
std::size_t Vector<E>::size() const {
  return size_;
}

template <typename E>
std::size_t Vector<E>::capacity() const {
  return capacity_;
}

template<typename E>
Vector<E>::Vector() {
  data_ = new E[initial_capacity];
  capacity_ = initial_capacity;
  size_ = 0;
}

template<typename E>
Vector<E>::~Vector() {
  assert(data_ != nullptr);
  delete[] data_;
}

template<typename E>
void Vector<E>::reserve(std::size_t new_capacity) {
  if (new_capacity <= capacity_) return;
  change_capacity(new_capacity);
}

template<typename E>
void Vector<E>::change_capacity(std::size_t new_capacity)
{
  if (new_capacity == capacity_) {
    return;
  }

  E* new_array = new E[new_capacity];
  assert(data_ != nullptr);
  auto new_vec_size = size_ < new_capacity ? size_ : new_capacity;
  // Use memcpy as source and destination do not overlap.
  std::memcpy(new_array, data_, sizeof(E) * new_vec_size);
  delete[] data_;

  data_ = new_array;
  size_ = new_vec_size;
  capacity_ = new_capacity;
}

template<typename E>
void Vector<E>::erase(std::size_t position)
{
  assert(position >= 0 && position < size_);
  std::size_t dst_index = position;
  std::size_t src_index = dst_index + 1;
  auto num_elems_to_copy = size_ - src_index;
  // use memmove here because of overlapping source and destination memory blocks
  std::memmove(data_ + dst_index, data_ + src_index, sizeof(E) * num_elems_to_copy);

  --size_;
}

template<typename E>
void Vector<E>::insert(std::size_t position, E value)
{
  assert(position >= 0 && position < size_);
  if (capacity_ < size_ + 1) {
    reserve(capacity_ * growth_factor);
  }

  std::size_t dst_index = position + 1;
  std::size_t src_index = position;
  auto num_elems_to_copy = size_ - src_index;
  assert(data_ != nullptr);
  // use memmove here because of overlapping source and destination memory blocks
  std::memmove(data_ + dst_index, data_ + src_index, sizeof(E) * num_elems_to_copy);
  ++size_;

  data_[position] = value;
}

template<typename E>
void Vector<E>::shrink_to_fit()
{
  change_capacity(size_);
}

template<typename E>
void Vector<E>::push_back(E element) {
  // check that space is available, if not grow the Vector
  auto new_size = size_ + 1;
  if (new_size > capacity_) {
    reserve(capacity_ * growth_factor);
  }
  assert(capacity_ >= new_size);

  // add the new element and increment size
  data_[size_++] = element;
}

template<typename E>
void Vector<E>::pop_back()
{
  --size_;
}

template<typename E>
E& Vector<E>::operator[](std::size_t index) {
  return data_[index];
}
template<typename E>
E& Vector<E>::back()
{
  assert(size_ > 0);
  return data_[size_ - 1];
}

template<typename E>
E& Vector<E>::front()
{
  assert(size_ > 0);
  return data_[0];
}

} // namespace JG