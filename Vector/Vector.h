#pragma once
#include <cstddef>
#include <initializer_list>

/**
 * Vector class - dynamically-sized array that mimics std::vector
 */
namespace JG {

template<typename E> // Element type
class Vector {
public:
  // constructors
  Vector();
  //Vector(std::initializer_list<E> initList);

  // destructor
  ~Vector();

  // accessors
  std::size_t size() const;
  std::size_t capacity() const;

  const E& operator[](std::size_t index) const;
  const E& back() const;
  const E& front() const;


  // mutators
  E& operator[](std::size_t index);
  E& back();
  E& front();
  void push_back(E element);
  void pop_back();

  void erase(std::size_t position);
  void insert(std::size_t position, E value);

  void reserve(std::size_t new_capacity);
  void shrink_to_fit();

private:
  E* data_;
  std::size_t capacity_ = 0;
  std::size_t size_ = 0;

  static constexpr std::size_t initial_capacity = 16;
  static constexpr std::size_t growth_factor = 2;

  void change_capacity(std::size_t new_capacity);
};

} //namespace JG
