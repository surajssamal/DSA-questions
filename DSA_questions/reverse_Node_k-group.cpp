#include "linked_list_use.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v), next(nullptr) {}
  ListNode(int v, ListNode *addr) : val(v), next(addr) {}
};
ListNode *one_sol(ListNode *head, int k) {
  ListNode *curr = head;
  int n = 0;
  ListNode *next_ptr = nullptr;
  ListNode *prev = nullptr;
  while (n < k) {
    if (n == k) {
      next_ptr = curr->next;
      curr->next = nullptr;
      prev = curr;
      curr = next_ptr;
      break;
    }
    next_ptr = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next_ptr;
    n++;
  }
  head->next = next_ptr;
  return prev;
}
ListNode *two_sol(ListNode *head, int k) {
  ListNode *curr = head;
  int n = 0;
  ListNode *next_ptr = nullptr;
  ListNode *prev = nullptr;
  ListNode *new_head = nullptr;
  while (curr) {
    if (n == k) {
      new_head = prev;
      next_ptr = curr->next;
      curr->next = nullptr;
      prev = curr;
      curr = next_ptr;
    }
    next_ptr = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next_ptr;
    n++;
  }
  head->next = prev;
  // print_linkedlist(new_head);
  return new_head;
}
ListNode *solution(ListNode *head, int k) {
  int n = 0;
  ListNode *curr = head;
  while (curr) {
    curr = curr->next;
    n++;
  }
  ListNode *sol = nullptr;
  if ((n - k) >= k) {
    sol = two_sol(head, k);
  } else {
    sol = one_sol(head, k);
  }
  return sol;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> inputs(n);
  for (int &x : inputs)
    cin >> x;
  ListNode *head = inseart_ll<ListNode, vector<int>>(inputs);
  print_linkedlist(head);

  ListNode *sol = solution(head, k);
  print_linkedlist(sol);
}
