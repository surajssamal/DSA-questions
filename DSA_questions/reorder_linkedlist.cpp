#include "linked_list_use.h"
#include <bits/stdc++.h>
#include <locale>
#include <unistd.h>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *m) : val(0), next(m) {}
};
ListNode *rec(ListNode *root, ListNode *curr) {
  if (curr == nullptr) {
    return root;
  }
  root = rec(root, curr->next);
  if (root == nullptr) {
    return nullptr;
  }
  ListNode *temp = nullptr;
  if (root == curr || root->next == curr) {
    curr->next = nullptr;
  } else {
    temp = root->next;
    root->next = curr;
    curr->next = temp;
  }
  return temp;
}
void reccursion_method(ListNode *head) { head = rec(head, head->next); };

void brute_force(ListNode *head) {
  vector<ListNode *> values;
  ListNode *curr = head;
  while (curr) {
    values.push_back(curr);
    curr = curr->next;
  }
  int left = 0, right = values.size() - 1;
  while (left < right) {
    values[left]->next = values[right];
    left += 1;
    if (left >= right) {
      break;
    }
    values[right]->next = values[left];
    right -= 1;
  }
  values[left]->next = nullptr;
}

ListNode *solution(ListNode *head) {
  int n = 0;
  ListNode *idn = head;
  while (idn) {
    n += 1;
    idn = idn->next;
  }
  idn = head;
  int k = 0;
  while (k != n / 2) {
    idn = idn->next;
    k++;
  }
  ListNode *curr = new ListNode(idn->val);
  while (idn->next) {
    idn = idn->next;
    ListNode *temp = new ListNode(idn->val);
    temp->next = curr;
    curr = temp;
  }
  idn = head;
  ListNode *result = new ListNode(idn->val);
  ListNode *m = result;
  k = 0;
  while (k != n / 2) {
    ListNode *temp = new ListNode(curr->val);
    m->next = temp;
    m = m->next;
    idn = idn->next;
    ListNode *temp2 = new ListNode(idn->val);
    m->next = temp2;
    m = m->next;
    curr = curr->next;
    k += 1;
  }
  return result;
}

int main() {
  vector<int> input_1 = {2, 4, 6, 8, 10, 11};
  int n = input_1.size();
  ListNode *head = inseart_ll<ListNode, vector<int>>(input_1);
  print_linkedlist(solution(head));
  cout << endl;
  reccursion_method(head);
  print_linkedlist(head);
  cout << endl;
  ListNode *head1 = inseart_ll<ListNode, vector<int>>(input_1);
  brute_force(head1);
  print_linkedlist(head1);
  return 0;
}
