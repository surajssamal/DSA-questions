#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {};
  ListNode(int x) : val(x), next(nullptr) {};
  ListNode(int x, ListNode *m) : val(x), next(m) {};
};

void print_linklist(ListNode *input) {
  ListNode *print_val = input;
  while (print_val) {
    cout << print_val->val;
    if (print_val->next != nullptr) {
      cout << "->";
    }
    print_val = print_val->next;
  }
  cout << endl;
}

ListNode *insearting(vector<int> input) {
  int n = input.size();
  ListNode *base = new ListNode(input[0]);
  ListNode *current = base;
  for (int i = 1; i < n; i++) {
    ListNode *temp = new ListNode(input[i]);
    current->next = temp;
    current = temp;
  }
  return base;
};
// solving this
ListNode *Sorting_ll(ListNode *inp1, ListNode *inp2) {
  if (inp1 == nullptr) {
    return inp2;
  }
  if (inp2 == nullptr) {
    return inp1;
  }
  ListNode *l = inp1;
  ListNode *r = inp2;
  ListNode *result;
  if (l->val < r->val) {
    result = new ListNode(l->val);
    l = l->next;
  } else {
    result = new ListNode(r->val);
    r = r->next;
  }
  ListNode *current = result;

  while (l && r) {
    if (l->val <= r->val) {
      ListNode *temp = new ListNode(l->val);
      l = l->next;
      current->next = temp;
      current = temp;
    } else {
      ListNode *temp = new ListNode(r->val);
      r = r->next;
      current->next = temp;
      current = temp;
    }
  }
  while (l) {
    ListNode *temp = new ListNode(l->val);
    l = l->next;
    current->next = temp;
    current = temp;
  }
  while (r) {
    ListNode *temp = new ListNode(r->val);
    r = r->next;
    current->next = temp;
    current = temp;
  }

  return result;
}

int main() {
  vector<int> inp_2 = {1, 3, 5};
  vector<int> inp_1 = {1, 2, 4};
  ListNode *inp1 = insearting(inp_1);
  ListNode *inp2 = insearting(inp_2);
  ListNode *result = Sorting_ll(inp1, inp2);
  print_linklist(result);
  return 0;
}
