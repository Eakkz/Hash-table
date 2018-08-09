// Name: Ekachai Suriyakriegnkri
// USC NetID: suriyakr@usc.edu
// CSCI 455 PA5
// Spring 2018

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
  // Initialize hash size to default value (constant value 9973)
  hashSize = HASH_SIZE;
  // Initialize number of entries to 0
  entriesSize = 0;
  // Initialize hash table with size and set all entries to NULL
  hashTable = new ListType[hashSize]();
}


Table::Table(unsigned int hSize) {
  // Initialize hash size to user input's value
  hashSize = hSize;
  // Initialize number of entries to 0
  entriesSize = 0;
  // Initialize hash table with custom size and set all entries to NULL
  hashTable = new ListType[hashSize]();
}


int * Table::lookup(const string &key) {
  // Get hash code from input key
  int hashKey = hashCode (key);
  // Lookup for key in hash table if contain return that key's address (pointer), if not return NULL pointer
  int * lookupAddress = listLookUp (hashTable[hashKey], key);

  return lookupAddress;
}

bool Table::remove(const string &key) {
  // Get hash code from input key
  int hashKey = hashCode(key);

  if(listRemove(hashTable[hashKey], key)) {
    entriesSize--;
    return true;
  }
  return false;
}

// Insert elements into linkedlist, reference by hashKey index
bool Table::insert(const string &key, int value) {
  // Get hash code from input key
  int hashKey = hashCode(key);

  // If insert element successfully, increase number of entries by 1
  if(listInsert(hashTable[hashKey], key, value)) {
    entriesSize++;
    return true;
  }

  return false;
}

// Return number of entries
int Table::numEntries() const {
  return entriesSize;
}

// Print all elements in hash table
void Table::printAll() const {
  int i = 0;
  for (i = 0; i < hashSize; i++) {
    // Print all elements in bucket i
    printList(hashTable[i]);
  }
}

// Print status of hash table
void Table::hashStats(ostream &out) const {
  out << "number of buckets: " << hashSize << endl;
  out << "number of entries: " << entriesSize << endl;
  out << "number of non-empty buckets: " << nonEmptyBuckets() <<  endl;
  out << "longest chain: " << longestChain() <<  endl;
}


// add definitions for your private methods here

// Return the index that contains element (not equal to NULL)
int Table::nonEmptyBuckets() const {
  int numBuckets = 0;
  int i = 0;
  for (i = 0; i < hashSize; i++) {
    if (hashTable[i] != NULL) {
      ++numBuckets;
    }
  }
  return numBuckets;
}

// Return the index that has the longest linkedlist (bucket that has the most elements)
int Table::longestChain() const {

  int maxChain = 0;
  int tempChain = 0;
  int i = 0;
  for (i = 0; i < hashSize; i++) {
    if (hashTable[i] != NULL)
    {
      tempChain = getSize(hashTable[i]);
      if (tempChain > maxChain)
	     maxChain = tempChain;
    }
  }
  return maxChain;
}
