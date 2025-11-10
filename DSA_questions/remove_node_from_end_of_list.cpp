#include "linked_list_use.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {};
  ListNode(int x) : val(x), next(nullptr) {};
  ListNode(int x, ListNode *m) : val(x), next(m) {};
};

ListNode *rec(ListNode *head, int n) {
  if (!head) {
    return NULL;
  }
  head->next = rec(head->next, n);
  n--;
  if (n == 0) {
    return head->next;
  }
  return head;
};
ListNode *recurssion(ListNode *head, int n) { return rec(head, n); };

ListNode *removenth(ListNode *head, int n) {
  ListNode *curr = head;
  vector<ListNode *> values;
  while (curr) {
    values.push_back(curr);
    curr = curr->next;
  }
  n = values.size() - n;
  if (n == 0) {
    return head->next;
  }
  values[n - 1]->next = values[n]->next;

  return head;
}

int main() {
  vector<int> input = {5, 2, 3};
  ListNode *head = inseart_ll<ListNode, vector<int>>(input);
  print_linkedlist(head);
  cout << endl;
  ListNode *result = removenth(head, 1);
  print_linkedlist(result);
  return 0;
}
