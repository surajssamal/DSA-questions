#ifndef LINKED_LIST_USE_HPP
#define LINKED_LIST_USE_HPP
#include <iostream>
using namespace std;
template <class container> void print_linkedlist(container *head) {
  container *printnode = head;
  while (printnode != nullptr) {
    cout << printnode->val << endl;
    printnode = printnode->next;
  };
};
#endif // !LINKED_LIST_USE_HPP
