//
// Created by user on 04.03.2024.
//

#ifndef MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPR_QUEUELSTPR_HPP_
#define MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPR_QUEUELSTPR_HPP_

#include <cstdint>

class QueueLstPr{
 public:
  QueueLstPr() = default;

  QueueLstPr(const QueueLstPr&);

  ~QueueLstPr();

  QueueLstPr& operator=(const QueueLstPr&);

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const float& val);

  [[nodiscard]] float& Top();

  [[nodiscard]] const float& Top() const;

  void Clear() noexcept;
  int64_t Size(){return size;};

 private:
  struct Node{
    Node(const float& v, Node* n) : el(v), pointer(n) {}
    float el;
    Node* pointer = nullptr;
  };
  Node* head = nullptr;
  Node* tail = nullptr;
  int64_t size = 0;
};

#endif //MISIS2023F_23_03_SHULGIN_M_A_PRJ_LAB_QUEUELSTPR_QUEUELSTPR_HPP_
