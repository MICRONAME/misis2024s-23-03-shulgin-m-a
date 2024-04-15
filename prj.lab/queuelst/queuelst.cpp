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
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      Clear();
    } else {
      // TODO: faster and smarter
      QueueLst copy(rhs);
      std::swap(head, copy.head);
      std::swap(tail, copy.tail);
    }
  }
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
  Node *temp = new Node(rhs, nullptr);
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

QueueLst::QueueLst(QueueLst && rhs) noexcept : head(rhs.head), tail(rhs.tail) {
  rhs.head = nullptr;
  rhs.tail = nullptr;
}

QueueLst &QueueLst::operator=(QueueLst && rhs) noexcept {
  if (this != &rhs){
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
  }
  return *this;
}
