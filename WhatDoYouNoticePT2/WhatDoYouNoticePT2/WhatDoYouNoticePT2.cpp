// WhatDoYouNoticePT2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main()
{
    int selection;
    SinglyLinkedList myList;

    cout << "Manage your students, choose an option:" << endl;
    cout << "(1) Push a student to the list" << endl;
    cout << "(2) Pop a student from the list" << endl;
    cout << "(0) Exit" << endl;

    do {
        try {
            cin >> selection;
        }
        catch (exception e) {
            cout << "Input a number 1, 2, or 0" << endl << endl;
        }
    } while (selection == 0 || selection == 1 || selection == 2);

    switch (selection) {
    case 0:
        cout << "Exiting Program...";
        break;
    case 1:
        cout << "1" << endl;

        Node* newNode;

        cout << "Student name: ";
        cin >> newNode->data.name;
        cout << "Student id: ";
        cin >> newNode->data.id;
        cout << "Student phone: ";
        cin >> newNode->data.phone;
        cout << "Student address: ";
        cin >> newNode->data.address;

        myList.Push(newNode);    
        delete newNode;

        break;
    case 2:
        cout << "2" << endl;

        Node* tempStudent = myList.Pop();

        cout << "Student name: " << tempStudent->data.name << endl;
        cout << "Student id: " << tempStudent->data.id << endl;
        cout << "Student phone: " << tempStudent->data.phone << endl;
        cout << "Student address: " << tempStudent->data.address << endl;
        break;
    /*default:
        cout << "An exception occured..." << endl;
        */
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
