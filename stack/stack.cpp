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

  std::size_t size() {
    return elements_.size();
  }

  bool empty() {
    return elements_.empty();
  }

  void clear() {
    elements_.clear();
  }

  std::string print() {
    std::stringstream result;
    result << '[';
    std::for_each(elements_.begin(), elements_.end(),
      [&](E element) { result << std::to_string(element) << ','; });
    result << ']';
    return result.str();
  }
};

} // namespace JG