//
// Created by user on 12.02.2024.
//
#include <Stacklst/Stacklst.hpp>
#include <stdexcept>

Stacklst::Stacklst(const Stacklst &rhs) {

}

Stacklst::~Stacklst() {

}

Stacklst &Stacklst::operator=(const Stacklst &rhs) {

}

void Stacklst::push(const Complex &rhs) {
  struct Node *n;
  n = new Node;
  n->el = rhs;
  if (empty()){
    head = n->next;
  }
  else {

  }
}

void Stacklst::pop() {

}

bool Stacklst::empty() const {
  if (head == nullptr) return true;
  return false;
}

Complex Stacklst::top() const {
  if (empty()) throw std::runtime_error("cannot get the top value: stack is empty");
  else{
    return
  }
}

Stacklst::Stacklst(const std::ptrdiff_t size) {

}
