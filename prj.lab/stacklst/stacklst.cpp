//
// Created by user on 12.02.2024.
//
#include <stacklst/stacklst.hpp>
#include <stdexcept>

StackLst::StackLst(const StackLst &rhs) {
  if (rhs.head){
    auto *tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
    for (auto* p = rhs.head->prev; p; p = p->prev) // as pointer here is p of type Node, until p is nullptr
      tail = tail->prev = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

    tail->prev = nullptr; //fixing making last tail->next pointer being Node
  }
}

StackLst::~StackLst() {
  while (head != nullptr)
    Pop();
}

StackLst &StackLst::operator=(const StackLst &rhs) {
  // дописать оператор= при разной длине стеков
  if (this != &rhs){
    if (rhs.head){
      Node* tail;
      if (head->prev != nullptr)
        *tail = *head = Node(*rhs.head);
      else
        tail = head = new Node(*rhs.head);
      //auto *tail = head = new Node(*rhs.head);
      for (auto* p = rhs.head->prev; p; p = p->prev) {
        if (tail->prev != nullptr)
          *tail = *tail->prev = Node(*p);
        else
          tail = tail->prev = new Node(*p);
      }
      while (tail->prev != nullptr){
        Node* temp;
        temp = tail;
        tail = tail->prev;
        delete temp;
      }
      //tail->prev = nullptr; //fixing making last tail->next pointer being Node
    }
  }
  return *this;
}

void StackLst::Push(const Complex &rhs) {
  auto *temp = new Node;
  temp->el = rhs;
  temp->prev = head;
  head = temp;
}

void StackLst::Pop() noexcept{
  Node* temp;
  temp = head;
  head = head->prev;
  delete temp;
}

bool StackLst::IsEmpty() const noexcept{
  if (head == nullptr) return true;
  return false;
}

const Complex& StackLst::Top() const {
  if (IsEmpty()) throw std::runtime_error("cannot get the Top value: stack is empty");
  else{
    return head->el;
  }
}

void StackLst::Clear() noexcept {
  while (head->prev != nullptr)
    Pop();
}
Complex& StackLst::Top() {
  if (IsEmpty()) throw std::runtime_error("cannot get the Top value: stack is empty");
  else{
    return head->el;
  }
}
