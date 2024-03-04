//
// Created by user on 04.03.2024.
//
#include <queuelstpr/queuelstpr.hpp>
#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr &rhs) {
  if (rhs.head) {
    tail = head = new Node(*rhs.head);
    for (auto *p = rhs.head->pointer; p; p = p->pointer)
      tail = tail->pointer = new Node(*p);

    tail->pointer = nullptr;
    size = rhs.size;
  }
}

QueueLstPr::~QueueLstPr() {
  Clear();
}

QueueLstPr &QueueLstPr::operator=(const QueueLstPr &rhs) {
  if (rhs.head != nullptr) {
    Node* a = head;
    if (a == nullptr)
    {
      a = new Node(0, nullptr);
      head = a;
      tail = a;
    }
    Node* b = rhs.head;
    while (b != rhs.tail) {
      if (a == tail)
      {
        a->pointer = new Node(0, nullptr);
        tail = a->pointer;
      }
      a->el = b->el;
      a = a->pointer;
      b = b->pointer;
    }
    a->el = b->el;
    while (a->pointer != nullptr)
    {
      Node* tmp = a->pointer;
      a->pointer = a->pointer->pointer;
      delete tmp;
    }
    tail = a;
  }
  else {
    while (head != nullptr) {
      Node* tmp = head->pointer;
      delete head;
      head = tmp;
    }
    tail = nullptr;
  }
  size = rhs.size;
  return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
  if (head == nullptr) return true;
  else return false;
}

void QueueLstPr::Pop() noexcept {
  if (!IsEmpty()) {
    Node *tmp = head->pointer;
    delete head;
    head = tmp;
    if (head == nullptr)
      tail = nullptr;
    size--;
  }
}

void QueueLstPr::Push(const float &val) {
  auto* temp = new Node(val, nullptr);
  if (IsEmpty()){
    head = temp;
    tail = temp;
  }
  else
  {
    if (temp->el < head->el){
      temp->pointer = head;
      head = temp;
    }
    else {
      bool flag = true;
      auto* tempTail = head;
      while (tempTail->pointer != nullptr){
        if (temp->el <= tempTail->pointer->el) {
          auto *temp2 = tempTail->pointer;
          temp->pointer = temp2;
          tempTail->pointer = temp;
          flag = false;
          break;
        }
        tempTail = tempTail->pointer;
      }
      if (flag){
        tail->pointer = temp;
        tail = temp;
      }
    }
  }
  size++;
}

float &QueueLstPr::Top() {
  if (!IsEmpty())
    return head->el;
  else throw std::runtime_error("cannot get top value: queue is empty");
}

const float &QueueLstPr::Top() const {
  if (!IsEmpty())
    return head->el;
  else throw std::runtime_error("cannot get top value: queue is empty");
}

void QueueLstPr::Clear() noexcept {
  while (head != nullptr)
    Pop();
}
