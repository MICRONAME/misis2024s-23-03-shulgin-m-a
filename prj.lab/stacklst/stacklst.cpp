//
// Created by user on 12.02.2024.
//
#include <Stacklst/Stacklst.hpp>
#include <stdexcept>

Stacklst::Stacklst(const Stacklst &rhs) {
  if (rhs.head){
    auto *tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
    for (auto* p = rhs.head->prev; p; p = p->prev) // as pointer here is p of type Node, until p is nullptr
      tail = tail->prev = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

    tail->prev = nullptr; //fixing making last tail->next pointer being Node
  }
}

Stacklst::~Stacklst() {
  while (head != nullptr)
    pop();
}

Stacklst &Stacklst::operator=(const Stacklst &rhs) {
  // дописать оператор= при разной длине стеков
  if (this != &rhs){
    if (rhs.head){
      auto *tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
      for (auto* p = rhs.head->prev; p; p = p->prev) // as pointer here is p of type Node, until p is nullptr
        tail = tail->prev = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

      tail->prev = nullptr; //fixing making last tail->next pointer being Node
    }
  }
  return *this;
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