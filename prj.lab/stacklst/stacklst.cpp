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
  auto *temp = new Node;
  temp->el = rhs;
  temp->prev = head;
  head = temp;
}

void Stacklst::pop() {
  if (empty()){
    throw std::runtime_error("cannot pop value: stack is empty");
  }
  Node* temp;
  temp = head;
  head = head->prev;
  delete temp;
}

bool Stacklst::empty() const noexcept{
  if (head == nullptr) return true;
  return false;
}

Complex Stacklst::top() const {
  if (empty()) throw std::runtime_error("cannot get the top value: stack is empty");
  else{
    return head->el;
  }
}