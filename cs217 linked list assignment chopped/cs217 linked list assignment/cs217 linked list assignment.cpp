#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;
void DisplayMainMenu();
void UserAction(bool&, DoublyLinkedList&);
void ListStudents(DoublyLinkedList&);
void DefaultStudents(DoublyLinkedList&);
void DetailedStudent(DoublyLinkedList&, int);
int GetUserInt();
struct tester {
  int x;
};
int main() {
  tester subject;
  subject.x = 10;
  tester *ptrSubject = &subject;
  cout << ptrSubject->x;
  bool exitProgram = false;
  char usrContinue;
  DoublyLinkedList studentList;
  char loadDefaults;
  cout << "Load default students?: [y/n]" << endl;
  cin >> loadDefaults;
  if (tolower(loadDefaults) == 'y') {
    DefaultStudents(studentList);
  }
  system("cls");
  while (!exitProgram) {
    studentList.GoToHead();

    DisplayMainMenu();
    UserAction(exitProgram, studentList);

    if (!exitProgram) { 
      cout << endl << "would you like to continue? [y/n]: ";
      cin >> usrContinue;

      if (tolower(usrContinue) == 'n') {
        exitProgram = true;
      } else {  
        system("cls");
      }
    }

  } 

  cout << "Thank you for using the student index system\n" << endl;
} 
int GetUserInt() {
  int validate;
  
  do {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin >> validate;
  } while (cin.fail());
  return validate;
}
void DisplayMainMenu() {
  cout << "Welcome to the student index" << endl;
  cout << "Please select your options: " << endl << endl;
  cout << "[1] Number of students enrolled\n"  
       << "[2] Add a new student\n"
       << "[3] Delete a student\n"
       << "[4] Update a student's information\n"
       << "[5] Display a student's information\n"
       << "[0] Exit program" << endl;
} 
void UserAction(bool& exit, DoublyLinkedList& studentList) {
  char usrSelect = -1;  
  int usrInput = -1;    
  int position;
  int id = 0;
  string name;
  string phone;
  string address;

  cin >> usrSelect;
  system("cls");
  cin.ignore(1000, '\n');


  switch (usrSelect) {

    case '0':  
      exit = true;
      break;


    case '1':  
      cout << "There are currently : " << studentList.GetNumOfItems()
           << " students enrolled." << endl;
      break;


    case '2':
    {
      while (id <= 0) {
        cout << "Please enter the student's name, id, phone, address: " << endl;
        cin >> name >> id >> phone >> address;
        cout << endl;
      }

      do {
        cout << "Please enter position for new student: ";
        position = GetUserInt();
      } while (position > studentList.GetNumOfItems()+1);

      StudentInfo tempStudent = {id, name, phone, address};
      studentList.AddStudentInfo(tempStudent, position);
    } break;


    case '3':       
      ListStudents(studentList);

      while (usrInput < 0) {
        cout << "select student id or enter 0 to delete all: ";
        cin >> usrInput;
        cout << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

      studentList.GoToHead();
      for (int i = 0; i < studentList.GetNumOfItems(); i++) {
        if (usrInput == 0) {
          studentList.DelStudentInfo(0);
        } else if (studentList.GetStudentInfo().id == usrInput) {
          studentList.DelStudentInfo(i);
        }

        studentList.GoToNext();
      }
      break;


    case '4':   
      ListStudents(studentList);
      cout << "select student id: ";
      cin >> usrInput;
      cout << endl;

      studentList.GoToHead();
      for (int i = 0; i < studentList.GetNumOfItems(); i++) {

        if (studentList.RetrieveStudentInfo(i).id == usrInput) {
          cout << "enter name, id, phone, address: " << endl;
          cin >> name >> id >> phone >> address;
          cout << endl;

          StudentInfo tempStudent = {id, name, phone, address};
          studentList.UpdateStudentInfo(tempStudent, i);
          break;
        }

      }
      break;


    case '5': 
      ListStudents(studentList);

      if (studentList.GetNumOfItems() != 0) {

        do {
          cout << "Enter students ID to display or 0 to exit: ";
          cin >> usrInput;
        } while (usrInput < 0);

        if (usrInput > 0) {  
          DetailedStudent(studentList, usrInput); 
        }
      }
      break;
    default:
      cout << "unknown input" << endl;
      break;
  }  
}  
void ListStudents(DoublyLinkedList& studentList) {  
  cout << "Students:" << endl;

  int length = studentList.GetNumOfItems();

  for (int i = 0; i < length; i++) {
    cout << "ID:" << studentList.GetStudentInfo().id << " - "
         << "Name: " << studentList.GetStudentInfo().name << endl;

    studentList.GoToNext();
  }
}  
void DetailedStudent(DoublyLinkedList& studentList, int selectedId) {
  char moveSelection;
  bool detailedView = true;
  StudentInfo currentStudent;

  for (int i = 0; i < studentList.GetNumOfItems(); i++) {
    if (studentList.RetrieveStudentInfo(i).id == selectedId) {
      
      studentList.GoToIndex(i);
      currentStudent = studentList.GetCurNode()->data;
    }
  }

  while (detailedView) {  
    system("cls");

    selectedId = studentList.GetCurPos();
    currentStudent = studentList.GetCurNode()->data;


    cout << "ID: " << currentStudent.id << endl
         << "Name: " << currentStudent.name << endl
         << "Phone: " << currentStudent.phone << endl
         << "Address: " << currentStudent.address << endl
         << endl;


    if (selectedId > 1) {  
      cout << "Display first student [f]" << endl;
      cout << "Display previous student [p]" << endl;
    }
    if (selectedId < studentList.GetNumOfItems()-1) {
      cout << "Display next student [n]" << endl;
      cout << "Display last student [l]" << endl;
    }
    cout << "Exit [0]" << endl;

    cin >> moveSelection;

    if (moveSelection == '0') {
      detailedView = false;

    } else if ((moveSelection == 'p') && (selectedId > 0)) {  
      selectedId--; 
      studentList.GoToPrev();   

    } else if ((moveSelection == 'f') && (selectedId > 0)) {  
      selectedId = 0;
      studentList.GoToHead();

    } else if ((moveSelection == 'n') &&
               (selectedId < studentList.GetNumOfItems()-1)) {  
      selectedId++;
      studentList.GoToNext();

    } else if ((moveSelection == 'l') && (selectedId < studentList.GetNumOfItems()-1)) {  
      selectedId = studentList.GetNumOfItems()-1;
      studentList.GoToTail();

    } else {
      cout << "Invalid input" << endl;
      cout << "Press enter to continue";
      system("pause");

    }  
  }   
}  
void DefaultStudents(DoublyLinkedList& studentList);