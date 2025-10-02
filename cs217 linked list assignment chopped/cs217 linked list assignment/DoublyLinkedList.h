#pragma once
#include <iostream>
#include <string>

using namespace std;

struct StudentInfo {
	int id;
	string name, phone, address;
};

struct Node {
	Node(StudentInfo, Node*, Node*);
	StudentInfo data;
	Node* next;
	Node* prev;
};

class DoublyLinkedList {
 private:
	 Node* head_, * tail_;
	 unsigned short num_entries_;
	 Node* current_pos_;
 public:
	DoublyLinkedList();
	void GoToHead();
	void GoToNext();
	void GoToPrev();
	void GoToTail();
	void GoToIndex(int);

	Node* GetCurNode();

	int GetCurPos();
	short GetNumOfItems();
	StudentInfo GetStudentInfo();
	StudentInfo RetrieveStudentInfo(unsigned short position);
	void AddStudentInfo(StudentInfo temp_Student, unsigned short position);
    void DelStudentInfo(unsigned short position);
    void UpdateStudentInfo(StudentInfo temp_Student, unsigned short position);
	void DisplayStudentInfo(unsigned short position);
};
