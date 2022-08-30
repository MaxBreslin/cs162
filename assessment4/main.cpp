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
 * The update function changes all matching strings to new value.  The
 * list is then reordered based on the new string length / ASCII ordering
 *
 */
using namespace std;

int main() {
     string input, search, replace, word;
     node *head = nullptr;

     // Accept input.  BLANK LINE marks end of input since EOF
     // seems to be forever with g++ and cin
     cout << "Enter input text (BLANK LINE to end):" << endl;
     do {
          getline(cin, input);
          if (input.length() == 0 || cin.good() != true) continue;
          istringstream stream(input);
          while (stream >> word) {
               head = insert(head, word);
          }
          stream.clear();
          stream.str();
     } while (input.length() > 0 && cin.good() == true);

     // Display the list of words
     cout << "\nList of Words:" << endl;
     print(head);

     // Update test: replace search string with replace string in all items
     cout << "\nEnter search string: ";
     cin >> search;
     cout << "Enter replacement string: ";
     cin >> replace;
     cout << "Replacing \"" << search << "\" with \"" << replace
          << "\" in all list entries." << endl << "Updated List:" << endl;
     head = update(head, search, replace);
     print(head);

     // Erase to clean up memory
     erase(head);
     return 0;
}
//****** DO NOT CHANGE ANY CODE ABOVE THIS LINE *****

node *update(node *head, string match, string value) {

// **** TASK 1: IMPLEMENT UPDATE FUNCTION HERE

}

// ***** DO NOT CHANGE ANY CODE AFTER THIS LINE

// Print the linked list
node *print(node *head) {
     if (head == nullptr) return head;
     cout << *head->data << " (" << head->data->length() << ")" << endl;
     print(head->next);
     return head;
}

// Erase the linked list
node *erase(node *head) {
     if (head == nullptr) return head;
     erase(head->next);
     delete head;
     head = nullptr;
     return head;
}

// Insert word into the linked list.
node *insert(node *head, string word) {
     if (head == nullptr || head->data->length() > word.length()) {
          return new node(word, head);
     }
     if (*head->data == word) {
          return head;
     }
     if (head->data->length() == word.length()) {
          if (*head->data > word) {
               return new node(word, head);
          }
     }
     head->next = insert(head->next, word);
     return head;
}
