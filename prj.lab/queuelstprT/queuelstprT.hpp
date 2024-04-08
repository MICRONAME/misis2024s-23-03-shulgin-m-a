//
// Created by user on 08.04.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPRT_QUEUELSTPRT_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPRT_QUEUELSTPRT_HPP_

#include <stdexcept>
template<class T>

class QueueLstPrT{
 public:
  QueueLstPrT() = default;
  QueueLstPrT(const QueueLstPrT<T> &);
  QueueLstPrT(QueueLstPrT<T> &&) noexcept ;
  ~QueueLstPrT();

  QueueLstPrT<T>& operator=(const QueueLstPrT<T> &);
  QueueLstPrT<T>& operator=(QueueLstPrT<T> &&) noexcept ;

  bool IsEmpty() noexcept;
  void Pop() noexcept;
  void Push(const T&);
  T& Top();
  const T& Top() const;

  void Clear() noexcept;

 private:
  struct Node{
   Node(T value, Node *point) : el(value), pointer(point){};
   T el;
   Node *pointer = nullptr;
 };
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
};

template<class T>
void QueueLstPrT<T>::Clear() noexcept {
  while (head_ != nullptr)
    Pop();
}

template<class T>
const T &QueueLstPrT<T>::Top() const {
  if (!IsEmpty()) return head_->el;
  throw std::runtime_error("cannot get top value: queue is empty");
}

template<class T>
T &QueueLstPrT<T>::Top() {
  if (!IsEmpty()) return head_->el;
  throw std::runtime_error("cannot get top value: queue is empty");
}

template<class T>
void QueueLstPrT<T>::Push(const T &value) {
  auto* temp = new Node(value, nullptr);
  if (IsEmpty()){
    head_ = temp;
    tail_ = temp;
  }
  else
  {
    if (temp->el < head_->el){
      temp->pointer = head_;
      head_ = temp;
    }
    else {
      bool flag = true;
      auto* tempTail = head_;
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
        tail_->pointer = temp;
        tail_ = temp;
      }
    }
  }
}

template<class T>
void QueueLstPrT<T>::Pop() noexcept {
  if (!IsEmpty()){
    Node* temp = head_;
    head_ = head_->pointer;
    delete temp;
    if (head_ == nullptr)
      tail_ = nullptr;
  }
}

template<class T>
bool QueueLstPrT<T>::IsEmpty() noexcept {
  if (head_ != nullptr) return true;
  return false;
}

template<class T>
QueueLstPrT<T> &QueueLstPrT<T>::operator=(QueueLstPrT<T> && other) noexcept{
  std::swap(*this, other);
  return *this;
}

template<class T>
QueueLstPrT<T> &QueueLstPrT<T>::operator=(const QueueLstPrT<T> &rhs) {
  if (rhs.head != nullptr) {
    Node* a = head_;
    if (a == nullptr)
    {
      a = new Node(0, nullptr);
      head_ = a;
      tail_ = a;
    }
    Node* b = rhs.head;
    while (b != rhs.tail) {
      if (a == tail_)
      {
        a->pointer = new Node(0, nullptr);
        tail_ = a->pointer;
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
    tail_ = a;
  }
  else {
    while (head_ != nullptr) {
      Node* tmp = head_->pointer;
      delete head_;
      head_ = tmp;
    }
    tail_ = nullptr;
  }
  return *this;
}

template<class T>
QueueLstPrT<T>::~QueueLstPrT() {
  Clear();
}

template<class T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T> && other) noexcept {
  std::swap(*this, other);
}

template<class T>
QueueLstPrT<T>::QueueLstPrT(const QueueLstPrT<T> & rhs) {
  if (rhs.head_){
    tail_ = head_ = new Node(*rhs.head_);
    for (auto *p = rhs.head_->pointer; p; p = p->pointer)
      tail_ = tail_->pointer = new Node(*p);
    tail_->pointer = nullptr;
  }
}

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPRT_QUEUELSTPRT_HPP_
