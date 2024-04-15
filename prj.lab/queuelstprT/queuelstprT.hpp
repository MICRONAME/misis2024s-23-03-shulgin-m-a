//
// Created by user on 08.04.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPRT_QUEUELSTPRT_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPRT_QUEUELSTPRT_HPP_

///CLASS
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

///DEFINITIONS
//Clear
template<class T>
void QueueLstPrT<T>::Clear() noexcept {
  while (head_ != nullptr)
    Pop();
}

//const Top
template<class T>
const T &QueueLstPrT<T>::Top() const {
  if (!IsEmpty()) return head_->el;
  throw std::runtime_error("cannot get top value: queue is empty");
}

//Top
template<class T>
T &QueueLstPrT<T>::Top() {
  if (!IsEmpty()) return head_->el;
  throw std::runtime_error("cannot get top value: queue is empty");
}

//Push
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

//Pop
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

//IsEmpty
template<class T>
bool QueueLstPrT<T>::IsEmpty() noexcept {
  if (head_ == nullptr) return true;
  return false;
}

//operator= &&
template<class T>
QueueLstPrT<T> &QueueLstPrT<T>::operator=(QueueLstPrT<T> && other) noexcept{
  std::swap(*this, other);
  return *this;
}

//operator= &
template<class T>
QueueLstPrT<T> &QueueLstPrT<T>::operator=(const QueueLstPrT<T> &rhs) {
  if (this != &rhs) {
    if (rhs.IsEmpty()) {
      Clear();
    } else {
      // TODO: faster and smarter
      QueueLstPrT<T> copy(rhs);
      std::swap(head_, copy.head_);
      std::swap(tail_, copy.tail_);
    }
  }
  return *this;
}

//DESTRUCTOR
template<class T>
QueueLstPrT<T>::~QueueLstPrT() {
  Clear();
}

//swap constructor
template<class T>
QueueLstPrT<T>::QueueLstPrT(QueueLstPrT<T> && other) noexcept {
  std::swap(*this, other);
}

//copy constructor
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
