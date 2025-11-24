#include "linked_list_use.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct node {
  int val;
  node *next;
  node() : val(0), next(nullptr) {};
  node(int x) : val(x), next(nullptr) {};
  node(int x, node *ptr) : val(x), next(ptr) {};
};

node *iter_rev(node *input_ll) {
  node *prev = nullptr;
  node *next_ptr = nullptr;
  node *curr = input_ll;
  while (curr) {
    next_ptr = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next_ptr;
  }
  return prev;
}
node *reccur_method(node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  node *temp = reccur_method(head->next);
  head->next->next = head;
  head->next = nullptr;
  return temp;
}

int main() {
  vector<int> input = {1, 2, 3, 4, 5, 6, 7};
  node *input_ll = inseart_ll<node, vector<int>>(input);
  node *input_copy = inseart_ll<node, vector<int>>(input);
  print_linkedlist(input_ll);
  node *result = iter_rev(input_ll);
  print_linkedlist(input_copy);
  result = reccur_method(input_copy);
  print_linkedlist(result);
  return 0;
}
