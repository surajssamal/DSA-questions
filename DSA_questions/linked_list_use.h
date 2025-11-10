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

template <class container, class vec_set> container *inseart_ll(vec_set input) {
  container *head = new container(input[0]);
  container *current = head;
  for (int i = 1; i < input.size(); i++) {
    container *temp = new container(input[i]);
    current->next = temp;
    current = temp;
  }
  return head;
}

#endif // !LINKED_LIST_USE_HPP
