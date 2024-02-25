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
  delete head;
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
  Node *temp = new Node;
  temp->el = rhs;
  if (!empty()) {
    tail->pointer = temp;
    tail = temp;
    if (head->pointer == nullptr)
      head->pointer = tail;
  }
  else{
    head = temp;
    tail = temp;
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
  // fixed
  if (this != &rhs) {
    if (rhs.head) {
      Node *helpTail = new Node;
      if (head != nullptr)
        *helpTail = *head = Node(*rhs.head);
      else
        helpTail = head = new Node(*rhs.head);

      for (auto *p = rhs.head->pointer; p; p = p->pointer) {
        if (helpTail->pointer != nullptr)
          *helpTail = *helpTail->pointer = Node(*p);
        else
          helpTail = helpTail->pointer = new Node(*p);
      }
      *tail = *helpTail;
      while (helpTail->pointer != nullptr){
        Node* temp;
        temp = helpTail;
        helpTail = helpTail->pointer;
        delete temp;
      }

      delete helpTail;
    }
  }
  return *this;
}
void Queue::clear() {
  while (head != nullptr){
    pop();
  }
  delete head;
}
