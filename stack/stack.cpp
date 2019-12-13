#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

namespace JG {

template<typename E>
class Stack {
  std::vector<E> elements_;

public:
  Stack<E>() = default;

  void push(E element) {
    elements_.push_back(element);
  }

  E pop() {
    auto back_element = elements_.back();
    elements_.pop_back();
    return back_element;
  }

  void clear() {
    elements_.clear();
  }

  template<typename T>
  friend std::string print(const JG::Stack<T>&);
};

template<typename E>
std::string print(const JG::Stack<E>& stack) {
  std::stringstream result;
  result << '[';
  std::for_each(stack.elements_.begin(), stack.elements_.end(),
    [&](E element) { result << std::to_string(element) << ','; });
  result << ']';
  return result.str();
}

} // namespace JG