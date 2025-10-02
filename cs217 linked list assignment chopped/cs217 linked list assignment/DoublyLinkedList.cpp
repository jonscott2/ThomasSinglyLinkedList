#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
  Node* head_ = nullptr;               // Pointer to the first student
  Node* tail_ = nullptr;               // Pointer to the last student
  unsigned short num_entries_ = 0;  // Number of inserted students
  Node* current_pos_ = head_;        // pointer to the current position
}
Node::Node(StudentInfo newData, Node* next = nullptr, Node* prev = nullptr) {
  data = newData;
}
void DoublyLinkedList::GoToHead() {
    current_pos_ = head_;
}
void DoublyLinkedList::GoToNext() {
  if (current_pos_ != nullptr && current_pos_ != tail_) {
    current_pos_ = current_pos_->next;
  }
}
void DoublyLinkedList::GoToPrev() {
  if (current_pos_ != nullptr && current_pos_ != head_) {
    current_pos_ = current_pos_->prev;
  }
}
void DoublyLinkedList::GoToTail() {
    current_pos_ = tail_;
}
void DoublyLinkedList::GoToIndex(int index) {
  GoToHead();
  for (int i = 0; i < index; i++) {
    GoToNext();
  }
}
Node* DoublyLinkedList::GetCurNode() 
{ return current_pos_; }
int DoublyLinkedList::GetCurPos() { 
    Node* tempPos = head_;
    int length = GetNumOfItems();

    for (int i = 0; i < length; i++) {
      if (tempPos == GetCurNode()) {
        return i;

      } else {
        tempPos = tempPos->next;
      }
    }
    return -1;
}
short DoublyLinkedList::GetNumOfItems() {
 
  Node* tempNode = head_;
  short length = 0;
  if (tempNode != nullptr) {
    length++;
    while (tempNode != tail_) {
      tempNode = tempNode->next;
      length++;
    }
  }
  return length;
}
StudentInfo DoublyLinkedList::GetStudentInfo() {  
    return GetCurNode()->data; }
StudentInfo DoublyLinkedList::RetrieveStudentInfo(unsigned short position) {
  Node* tempPos = head_;

  for (int i = 0; i < position; i++) {
    tempPos = tempPos->next;
  }
  return tempPos->data;

}
void DoublyLinkedList::DisplayStudentInfo(unsigned short position) 
{
    

}
void DoublyLinkedList::AddStudentInfo(StudentInfo new_Student,
                                      unsigned short position) {
  Node* newNode = new Node(new_Student);
  GoToIndex(position);
  Node* currentNode = GetCurNode();
  num_entries_++;
  if (head_ == nullptr) {
    head_ = newNode;
    tail_ = newNode;
  }
   else if (position == 0 || (currentNode->prev == nullptr)) { 
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;

  } else if (position > GetNumOfItems()) {
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
  }

  else {
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    if (GetNumOfItems() != 1) {
      newNode->prev->next = newNode;
    } else {
      head_ = newNode;
    }
    currentNode->prev = newNode;
  }
}
void DoublyLinkedList::DelStudentInfo(unsigned short position) {
  GoToIndex(position);
  Node* deadNode = GetCurNode();
  num_entries_--;

  if (deadNode == head_) {  
    head_ = deadNode->next;
    head_->prev = nullptr;
  }

  else if (deadNode != tail_) {  

    deadNode->prev->next = deadNode->next;
    deadNode->next->prev = deadNode->prev;


  } else { 
    tail_ = deadNode->prev;
    tail_->next = nullptr;
  }
}

void DoublyLinkedList::UpdateStudentInfo(StudentInfo temp_Student,
                                         unsigned short position) {
  Node* tempPos = head_;
  for (int i = 0; i < position; i++) {
    tempPos = tempPos->next;
  }
  tempPos->data = temp_Student;
}
