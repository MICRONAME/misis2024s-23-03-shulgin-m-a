//
// Created by user on 19.02.2024.
//
#include <queuelst/queuelst.hpp>
#include <stdexcept>

QueueLst::QueueLst(const QueueLst &rhs) {
  size = rhs.size;
  if (rhs.head) {
    tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
    for (auto *p = rhs.head->pointer; p; p = p->pointer) // as pointer here is p of type Node, until p is nullptr
      tail = tail->pointer = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

    tail->pointer = nullptr; //fixing making last tail->next pointer being Node
  }
}

QueueLst::~QueueLst() {
  while (head != nullptr){
    Pop();
  }
}

Complex& QueueLst::Top() {
  if (!IsEmpty())
    return head->el;
  else throw std::runtime_error("cannot get Top value: QueueLst is Empty");
}

bool QueueLst::IsEmpty() const noexcept{
  if (head == nullptr) return true;
  return false;
}

void QueueLst::Push(const Complex& rhs) {
  Node *temp = new Node;
  temp->el = rhs;
  if (!IsEmpty()) {
    tail->pointer = temp;
    tail = temp;
    if (head->pointer == nullptr)
      head->pointer = tail;
  }
  else{
    head = temp;
    tail = temp;
  }
  size++;
}

void QueueLst::Pop() noexcept{
  if (head != nullptr) {
    Node *temp;
    temp = head;
    head = head->pointer;
    delete temp;
    size--;
  }
}

QueueLst &QueueLst::operator=(const QueueLst &rhs) {
  // fixed
  size = rhs.size;
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
void QueueLst::Clear() noexcept{
  while (head != nullptr){
    Pop();
  }
  delete head;
}
const Complex& QueueLst::Top() const {
  if (!IsEmpty())
    return head->el;
  else throw std::runtime_error("cannot get Top value: QueueLst is Empty");
}
