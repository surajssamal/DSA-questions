#include "linked_list_use.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
problem statement :-
given a linked list -> {1,2,3,4,5} and k->2
have to return {2,1,4,3,5}
have to reverse till the n-th element(2 in this case)thats how we get {2,1}{4,3}
and if the remaining is less that 2 then no need to reverse
**/

// recursive approach
ListNode *solution(ListNode *head, int k) {
  ListNode *curr = head;
  int n = 0;
  while (curr && n < k) {
    curr = curr->next;
    n++;
  }
  if (n == k) {
    curr = solution(curr, k);
    ListNode *next_ptr = nullptr;
    while (n-- > 0) {
      next_ptr = head->next;
      head->next = curr;
      curr = head;
      head = next_ptr;
    }
    head = curr;
  }
  return head;
};

// iterative method
ListNode *get_kth(ListNode *curr, int k) {
  while (k-- > 0 && curr) {
    curr = curr->next;
  }
  return curr;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> inputs(n);
  for (int &x : inputs) {
    cin >> x;
  }
  ListNode *head = inseart_ll<ListNode, vector<int>>(inputs);
  print_linkedlist(head);
  ListNode *sol = solution(head, k);
  print_linkedlist(sol);

  return 0;
}
