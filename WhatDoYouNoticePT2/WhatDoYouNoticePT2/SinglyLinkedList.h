#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Student {
	int id;
	string name, phone, address;
};

struct Node {
	Student data;
	Node* next;
};

class SinglyLinkedList {
public:
	SinglyLinkedList();
	void Push(Node*);
	Node* Pop();
	bool IsEmpty();
private:
	Student* studentList;
	Node* head;
};