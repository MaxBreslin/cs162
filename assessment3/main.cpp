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
 * The print() function prints the list
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
          head = insert(head,word);
     }
     cout << "\nList of Words:" << endl;
     print(head);
     erase(head);
     return 0;
}

// *** DO NOT CHANGE CODE ABOVE THIS LINE ***

// Print the linked list in reverse order
void print(node * head) {
 // *** TASK 1: Implement print function to print list 
 // ***         in REVERSE order. NO RECURSION IS PERMITTED. 

 // *** ADD CODE HERE
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
        cout << *seen[i]->data << endl;
    }

    delete[] seen;
}

// Erase the linked list
void erase(node *& head) {
// *** TASK 2: Implement erase function to erase all elements
// ***         in the list.  NO RECURSION IS PERMITTED.

// *** ADD CODE HERE
    node * temp = head;
    while(temp) {
        head = temp->next;
        delete temp;
        temp = head;
    }
}

// *** DO NOT CHANGE CODE BELOW THIS LINE ***

// Insert word into the linked list.
// (a) No duplicates
// (b) Ordered by length ascending
// (c) same length ordered by ascii
node * insert(node *& head, string word)
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


     
