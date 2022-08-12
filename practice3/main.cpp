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
 * The print() function prints the list in REVERSE order, so the display
 * is by length DESCENDING
 *
 * EOF marks end of input, so a file can be piped to program
 */
using namespace std;
int main()
{
     string         word;
     node      *    head      = nullptr;
     while(cin.good() == true && cin.peek() != EOF) {
          cin  >> word;
          if (cin.good() != true) continue;
          insert(head,word);
     }
     cout << "\nList of Words:" << endl;
     print(head);
     erase(head);
     return 0;
}

// **** DO NOT CHANGE CODE ABOVE THIS LINE ***

// Insert word into the linked list.
// (a) No duplicates
// (b) Ordered by length ascending
// (c) If words are thesame length then  ordered by ascii
void insert(node *& head, string word)
{
     node * temp = new node;
     temp->data = new string(word);
     if (!head) {
          head = temp;
          return;
     }
     node * curr = head;
     node * prev = nullptr;
     while (curr) {
          if (word == *curr->data) {
               delete temp;
               return;
          }
          if (word.length() < curr->data->length()) {
               break;
          }
          if (word.length() == curr->data->length()) {
               if (word < *curr->data) {
                    break;
               }
          }
          prev = curr;
          curr = curr->next;
     }
     if (!prev) {
          temp->next = head;
          head = temp;
          return;
     }
     if (!curr) {
          prev->next = temp;
          return;
     }
     prev->next = temp;
     temp->next = curr;
}

//**** DO NOT CHANGE CODE BELOW THIS LINE ***

// Print the linked list 
void print(node * head) {
     if (head == nullptr) return;
     cout << *head->data << endl;
     print(head->next);
}

// Erase the linked list
void erase(node *& head) {
     if (head == nullptr) return;
     erase(head->next);
     delete head;
     head = nullptr;
}

     
