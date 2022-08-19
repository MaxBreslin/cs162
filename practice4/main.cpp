#include "main.h"
/*
 * Create a linked list of words from stdin.
 * The linked list is
 * (a) Ordered by word length in ASCENDING order
 * (b) Has no duplicates
 * (c) If two words have the same length they are ordered by ASCII
 *
 * The erase() function deletes the list
 *
 * The print() function prints the  list
 * 
 * The remove function removes all strings of the specified length
 *
 * The update function changes all matching strings to new value
 *
 * EOF marks end of input, so a file can be piped to program
 */
using namespace std;
int main()
{
     string         input, search, replace, word;
     node      *    head      = nullptr;
     size_t         length    = 0;

     // Accept input.  BLANK LINE marks end of input since EOF
     // seems to be forever with g++ and cin
     cout << "Enter input text (BLANK LINE to end):" << endl;
     do {
          getline(cin,input);
          if (input.length() == 0 || cin.good() != true) continue;
          istringstream stream(input);
          while(stream >> word) {
               head = insert(head,word);
          }
          stream.clear();
          stream.str();
     } while(input.length() > 0 && cin.good() == true);

     // Display the list of words
     cout << "\nList of Words:" << endl;
     print(head);
    
     // Update test: replace search string with replace string in all items
     cout << "\nEnter search string: ";
     cin >> search;
     cout << "Enter replacement string: ";
     cin >> replace;
     cout << "Replacing \"" << search << "\" with \""
          << replace << "\" in all list entries." << endl
          << "Updated List:" << endl;
     head = update(head,search,replace);
     print(head);

     // Remove test: remove all items with specified string length
     cout << "\nEnter target string length for remove: ";
     cin >> length;
     cin.ignore(8192,'\n');
     cout << "Removing all entries with string length of " 
          << length << "." << endl
          << "Updated List:" << endl;
     head = remove(head,length);
     head = print(head);


     // Erase to clean up memory
     erase(head);
     return 0;
}
//*** DO NOT CHANGE CODE ABOVE THIS LINE ***

//*** TASK 1: IMPLEMENT THE print() FUNCTION
//***         Display the string and its length
//***         for each node in the list.
//***
//***         Print the list in REVERSE ORDER.
//***         DO NOT USE ANY RECURSION ***
node * print(node * head) {
     int size = 0;
     node * curr = head;
     node * * seen = nullptr;
     node * * temp = nullptr;

     while (curr) {
          if (seen) {
               temp = new node * [size + 1];
               for (int i = 0; i < size; i ++) {
                    temp[i] = seen[i];
               }
               delete[] seen;
               seen = temp;
               seen[size ++] = curr;
          } 
          else {
               seen = new node * [size + 1];
               seen[0] = curr;
               size = 1;
          }
          curr = curr->next;
     }

     for (int i = size - 1; i >= 0; i --) {
          cout << *seen[i]->data << " (" << seen[i]->data->length() << ")" << endl;
     }

     delete[] seen;
     return head;
}

//*** TASK 2: IMPLEMENT THE remove FUNCTION
//***         Remove and delete all nodes  whose string
//***         is of the specified length
//***         DO NOT USE ANY RECURSION ***
node * remove(node * head, size_t length) {
     node * curr = head;
     node * prev = nullptr;
     node * next = nullptr;
     while (curr) {
          next = curr->next;
          if (curr->data->length() == length) {
               if (prev) {
                    prev->next = next;
               }
               else {
                    head = next;
               }
               delete curr;
          }
          else {
               prev = curr;
          }
          curr = next;
     }
     return head;
}

//*** DO NOT CHANGE CODE BELOW THIS LINE ***

// Update strings: replace match with value
node * update(node * head, string match, string value) {
     if (head == nullptr) return head;
     if (head->data->find(match) != string::npos) {
          head->data->replace(head->data->find(match),match.length(),value);
     }
     update(head->next,match,value);
     return head;
}

// Erase the linked list
node * erase(node * head) {
     if (head == nullptr) return head;
     erase(head->next);
     delete head;
     head = nullptr;
     return head;
}
// Insert word into the linked list.
// (a) No duplicates
// (b) Ordered by length ascending
// (c) same length ordered by ascii
node * insert(node * head, string word)
{
     if (head == nullptr || head->data->length() >  word.length()) {
          return new node(word,head);
     }
     if (*head->data == word) {
          return head;
     }
     if (head->data->length() == word.length()) {
          if (*head->data > word) {
               return new node(word,head);
          }
     }
     head->next = insert(head->next,word);
     return head;
}
