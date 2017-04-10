#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;
/**
 * link list declaration
 **/

struct HashEntry {
 public:
  int value;
  struct HashEntry *next;
};

/**
 * HashMap Class Declaration
 **/

class HashMap {
 private:
 HashEntry **table;

 public:
  HashMap();
  int HashFunc(int value);
  void Insert(int value);
  int Search(int value);
  void Remove(int value);
  void Display();
};

/**
 *  Hash Function
 **/

HashMap::HashMap() {
//  HashEntry **table;
  table = new HashEntry *[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;
}

int HashMap::HashFunc(int value) { return value % TABLE_SIZE; }

/**
 * Insert Element at a key
 **/

void HashMap::Insert(int value) {
  int key = HashFunc(value);
  struct HashEntry *temp = table[key];
  if (temp == NULL) {
    temp = new HashEntry;
    temp->value = value;
    table[key] = temp;
    temp->next = NULL;
  } else {
    while (temp->next != NULL) temp = temp->next;
    struct HashEntry *current = new HashEntry;
    current->value = value;
    current->next = NULL;
    temp->next = current;
  }
}

/**
 *   Search Element at a key
 **/

int HashMap::Search(int value) {
  int key = HashFunc(value);
  struct HashEntry *temp = table[key];
  if (temp == NULL) {
    cout << "Search element unavailable in hash table\n";
    return 0;
  }
  while (temp != NULL) {
    if (temp->value == value) {
      cout << " stored value is: " << temp->value << "at index position" << key;
      break;
    }
    temp = temp->next;
  }
}

/**
 *  Remove Element at a key
 **/

void HashMap::Remove(int value) {
  int key = HashFunc(value);
  struct HashEntry *temp = table[key];
  if (temp == NULL) {
    cout << "No entries available\n";
    return;
  }
  if (temp->value == value) {
    table[key] = temp->next;
    delete temp;
  } else {
    struct HashEntry *prev = temp;
    temp = temp->next;
    while (temp != NULL) {
      if (temp->value == value) {
        prev->next = temp->next;
        delete temp;
        cout << "Element Deleted" << endl;
        break;
      }
      temp = temp->next;
    }
    if (temp == NULL) cout << "Element not found\n";
  }
}

/**
 *  Display
 **/

void HashMap::Display() {
  struct HashEntry *temp;
  int i;
  for (i = 0; i < TABLE_SIZE; i++) {
    temp = table[i];

    cout << i << "-->";
    while (temp != NULL) {
      cout << temp->value << "-->";
      temp = temp->next;
    }
    cout << "null\n\n";
  }
  return;
}  // end of display()

/**
 *  Main function
 **/

int main() {
  HashMap hash;
  int value;
  int choice;
  while (1) {
    cout << "Select Operation on Hash Table" << endl;
    cout << "\n----------------------" << endl;
    cout << "1.Insert element into the table" << endl;
    cout << "2.Search element by value" << endl;
    cout << "3.Delete element" << endl;
    cout << "4.Display hashmap" << endl;
    cout << "5.Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1: {
        cout << "Enter element to be inserted: ";
        cin >> value;
        hash.Insert(value);
        break;
	}
      case 2: {
        cout << "Enter value of the element to be searched: ";
        cin >> value;
        hash.Search(value);
        break;
	}
      case 3: {
        cout << "Enter value of the element to be deleted: ";
        cin >> value;
        hash.Remove(value);
        break;
	}
      case 4: {
        cout << "Displaying hashmap" << endl;
        hash.Display();
        break;
	}
      case 5:
        exit(1);
      default: {
	cout << "enter valid input" << endl;  
	}
    }
  }
  return 0;
}
