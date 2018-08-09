// Name: Ekachai Suriyakriengkri
// USC NetID: suriyakr@usc.edu
// CSCI 455 PA5
// Spring 2018

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>
#include <sstream>

// Function for insert name and score into hash table
void insert (Table * &grades, istringstream &input) {
  string name;
  int score;
  //Pass string stream of string which in pattern [name] [score]
  input >> name;
  input >> score;

  // Check  the name is already in table, if not create a new one
  // If alread existed, print show user that this name already existed
  if(grades->lookup(name) == NULL) {
    grades->insert(name, score);
  }

  else
    cout << "The input name is already in the table." << endl;
}

// Change current score to the new one by using name
void change (Table * &grades, istringstream &input) {
  string name;
  int newScore;
  //Pass string stream of string which in pattern [name] [score]
  input >> name;
  input >> newScore;

  // Find the address of score, if existed replace with new value
  int* oldScore = grades->lookup(name);
  if (oldScore != NULL)
    *oldScore = newScore;
  // If not promt user that unable to change the score
  else
    cout << "Cannot modify the score, the input name is not in the table." << endl;
}

// Find and print the score of input name
void lookup (Table * &grades, istringstream &input) {
  string name;
  //Pass string stream of string which in pattern [name]
  input >> name;

  // Get score address by name
  int *getScore = grades->lookup(name);
  // If score is in thr table, print to the user
  if (getScore != NULL) {
    cout << name << "'s score: " << *getScore << endl;
  }
  // If not, promt user that this name is not in the table
  else
    cout << "The input student is not in the table." << endl;
}

// Remove by name
void remove (Table * &grades, istringstream &input) {
  string name;
  //Pass string stream of string which in pattern [name]
  input >> name;

  // If cannot remove (not existing name), promt error to user
  if(!grades->remove(name))
    cout << "Cannot remove " << name << " , this name is not in the table." << endl;
}

// Print all element in hash table
void print (Table * &grades) {
  grades->printAll();
}

// Get number of elements in hash table
void size (Table * &grades) {
  cout << "The number of entries in the table: " << grades->numEntries() << endl;
}

// Show stats of current hash table (bucket size, longest chain, number of entries)
void stats (Table * &grades) {
  cerr << "Hash stats: " << endl;
  grades->hashStats(cerr);
}

// Print help command
void help () {
  cout << "********** Help comannd summary **********" << endl;
  cout << "Command: insert [name] [score]" << endl;
  cout << "Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;
  cout << "******************************************" << endl;
  cout << "Command: change [name] [score]" << endl;
  cout << "Change the score for name. Print an appropriate message if this name isn't present. " << endl;
  cout << "******************************************" << endl;
  cout << "Command: lookup [name]" << endl;
  cout << "Lookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;
  cout << "******************************************" << endl;
  cout << "Command: remove [name] " << endl;
  cout << "Remove this student. If this student wasn't in the grade table, print a message to that effect." << endl;
  cout << "******************************************" << endl;
  cout << "Command: print " << endl;
  cout << "Prints out all names and scores in the table. " << endl;
  cout << "******************************************" << endl;
  cout << "Command: size" << endl;
  cout << "Prints out the number of entries in the table." << endl;
  cout << "******************************************" << endl;
  cout << "Command: stats" << endl;
  cout << "Prints out statistics about the hash table at this point." << endl;
  cout << "******************************************" << endl;
  cout << "Command: help" << endl;
  cout << "Prints out a brief command summary." << endl;
  cout << "******************************************" << endl;
  cout << "Command: quit" << endl;
  cout << "Exits the program." << endl;
  cout << "******************************************" << endl;
}

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;
  string input;
  string command;
  bool exit;
  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number"
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*
  exit = false;
  // Run until user input "quit"
  while (!exit) {

    // Promt for user to input command
    cout << "cmd> ";
    getline (cin, input); //Get whole line of input from user

    // Put user line in to stringstream
    istringstream streamInput(input);
    // Extract first word from line
    streamInput >> command;

    // Check command
    if (command == "insert") {
      insert(grades, streamInput);
    }

    else if (command == "change") {
      change(grades, streamInput);
    }

    else if (command == "lookup") {
      lookup(grades, streamInput);
    }

    else if (command == "remove") {
      remove(grades, streamInput);
    }

    else if (command == "print") {
      print(grades);
    }

    else if (command == "size") {
      size(grades);
    }

    else if (command == "stats") {
      stats(grades);
    }

    else if (command == "help") {
      help();
    }

    else if (command == "quit") {
      exit = true;
    }
    // If user input command that not unavaible
    else {
      cout << "ERROR: invalid command" << endl;
      cout << "Please enter 'help' for more information" << endl;
    }
  }
  return 0;
}
