// Name: Ekachai Suriyakriengkri
// USC NetID: suriyakr@usc.edu
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

int main() {

  ListType list = new Node("Z",100);

  listInsert(list, "A", 10);
  listInsert(list, "B", 20);
  listInsert(list, "C", 30);
  cout << getSize(list) << endl;
  cout << "a list: " << endl;
  printList(list);
  listUpdate(list, "C", 50);
  cout << "a change list: ";
  printList(list);
  listRemove(list, "C");
  cout << "a remove list: ";
  printList(list);
  cout << "Look up: " << listLookUp(list, "A") << endl;
  return 0;
}
