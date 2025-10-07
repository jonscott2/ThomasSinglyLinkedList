#include <string>
#include "SinglyLinkedList.h"

using namespace std;

SinglyLinkedList::SinglyLinkedList() {
	head = new Node;
	head->next = nullptr;
}
void SinglyLinkedList::Push(Node* newStudent) {
	Node* tempStudent = head;
	while (tempStudent->next != nullptr) {
		tempStudent = tempStudent->next;
	}
	tempStudent->next = newStudent;
}
Node* SinglyLinkedList::Pop() {
	Node* tempStudent = head;
	while (tempStudent->next != nullptr) {
		tempStudent = tempStudent->next;
	}
	return(tempStudent);
}
bool SinglyLinkedList::IsEmpty() {
	if (head != nullptr) {
		return (false);
	}
	else {
		return (true);
	}
}
