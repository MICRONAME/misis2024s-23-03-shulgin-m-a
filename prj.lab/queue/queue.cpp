//
// Created by user on 19.02.2024.
//
#include <queue/queue.hpp>
#include <stdexcept>

Queue::Queue(const Queue &rhs) {
  if (rhs.head) {
    tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
    for (auto *p = rhs.head->pointer; p; p = p->pointer) // as pointer here is p of type Node, until p is nullptr
      tail = tail->pointer = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

    tail->pointer = nullptr; //fixing making last tail->next pointer being Node
  }
}

Queue::~Queue() {
  while (head->pointer != nullptr){
    pop();
  }
}
Complex Queue::top() {
  if (!empty())
    return head->el;
  else throw std::runtime_error("cannot get top value: queue is empty");
}

bool Queue::empty() {
  if (head == nullptr) return true;
  return false;
}
void Queue::push(const Complex& rhs) {
  auto *temp = new Node;
  temp->el = rhs;
  if (!empty()) {
    head->pointer = temp;
    tail = temp;
  }
  else{
    temp->pointer = head;
    head = temp;
  }
}
void Queue::pop() {
  if (empty()){
    throw std::runtime_error("cannot pop value: stack is empty");
  }
  Node* temp;
  temp = head;
  head = head->pointer;
  delete temp;
}
Queue &Queue::operator=(const Queue &rhs) {
  // same as stacklist
  if (this != &rhs) {
    if (rhs.head) {
      tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
      for (auto *p = rhs.head->pointer; p; p = p->pointer) // as pointer here is p of type Node, until p is nullptr
        tail = tail->pointer = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

      tail->pointer = nullptr; //fixing making last tail->next pointer being Node
    }
  }
  return *this;
}
