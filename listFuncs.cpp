// Name: Ekachai Suriyakriengkri
// USC NetID: suriyakr@usc.edu
// CSCI 455 PA5
// Spring 2018


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}

//*************************************************************************
// put the function definitions for your list functions below

// Insert new node in the front of linked list
bool listInsert (ListType &list, string name, int score) {
  ListType p = list;
  list = new Node(name, score, p);
  return true;
}

// Find and return the address of score by using name
int* listLookUp (ListType &list, string name) {
  ListType p = list;

  while (p != NULL) {
    if (p->key == name) {
      return &p->value;
    }
    p = p->next;
  }
  return NULL;
}

// Remove and return memory of node by using name
bool listRemove (ListType &list, string name) {
  // Linked list is empty
  if (list == NULL)
    return false;

  ListType p = list;
  // If the first node is the target, move pointer to next one and remove the target
  if (p->key == name) {
    list = list->next;
    delete p;
    return true;
  }

  // If target is not the first node, create a new pointer point to node next to p
  ListType next = p->next;
  while (next != NULL) {
    // If second pointer is the target
    if (next->key  == name) {
      // Change pointer p to point to next node of the second pointer (next node that next pointer point to)
      p->next = next->next;
      // delete to target
      delete next;
      return true;
    }
    // Move both pointer to run loop
    p = p->next;
    next = next->next;
  }
  return false;
}

// Print all elements in linked list
void printList (ListType &list) {
  ListType p = list;
  while (p != NULL) {
    cout << p->key << " " << p->value << " " << endl;
    p = p->next;
  }
}

// Get size of linked list
int getSize (ListType &list) {
  int size = 0;
  ListType p = list;

  while (p != NULL) {
    ++size;
    p = p->next;
  }
  return size;
}
