#include <queuelst/queuelst.hpp>

#include <stdexcept>

QueueLst::QueueLst(const QueueLst &rhs) {
  if (rhs.head) {
    tail = head = new Node(*rhs.head); // this is making a pair pointer to new node within rhs.head value
    for (auto *p = rhs.head->pointer; p; p = p->pointer) // as pointer here is p of type Node, until p is nullptr
      tail = tail->pointer = new Node(*p); // makes tail pointer value and tail->next pointer valur as p

    tail->pointer = nullptr; //fixing making last tail->next pointer being Node
    size = rhs.size;
  }
}

QueueLst::~QueueLst() {
  Clear();
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
  //надо подумать где неправильно написано
  if (rhs.head != nullptr) {
    Node* a = head;
    if (a == nullptr)
    {
      a = new Node(Complex(), nullptr);
      head = a;
      tail = a;
    }
    Node* b = rhs.head;
    while (b != rhs.tail) {
      if (a == tail)
      {
        a->pointer = new Node(Complex(), nullptr);
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

bool QueueLst::IsEmpty() const noexcept{
  if (head == nullptr) return true;
  return false;
}

void QueueLst::Pop() noexcept{
  if (!IsEmpty()) {
    Node *tmp = head->pointer;
    delete head;
    head = tmp;
    if (head == nullptr)
      tail = nullptr;
    size--;
  }
}


void QueueLst::Push(const Complex& rhs) {
  Node *temp = new Node(Complex(), nullptr);
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

Complex& QueueLst::Top() {
  if (!IsEmpty())
    return head->el;
  else throw std::runtime_error("cannot get Top value: QueueLst is Empty");
}

const Complex& QueueLst::Top() const {
  if (!IsEmpty())
    return head->el;
  else throw std::runtime_error("cannot get Top value: QueueLst is Empty");
}

void QueueLst::Clear() noexcept{
  while (head != nullptr){
    Pop();
  }
}