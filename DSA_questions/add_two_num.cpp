#include "linked_list_use.h"
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(), next() {};
  ListNode(int x) : val(x), next() {};
  ListNode(int x, ListNode *n) : val(x), next(n) {};
};
ListNode *bruteforce(ListNode *l1, ListNode *l2) {
  ListNode *result = new ListNode();
  ListNode *curr = result;
  int carry = 0;
  while (l1 || l2 || carry) {
    int l1_node = (l1 != nullptr) ? l1->val : 0;
    int l2_node = (l2 != nullptr) ? l2->val : 0;
    int res = l1_node + l2_node + carry;
    carry = res / 10;
    res = res % 10;
    ListNode *temp = new ListNode(res);
    curr->next = temp;
    curr = curr->next;
    l1 = (l1 != nullptr) ? l1->next : nullptr;
    l2 = (l2 != nullptr) ? l2->next : nullptr;
  }
  ListNode *res = result->next;
  delete result;
  return res;
}
int main() {
  vector<int> input_1 = {1, 2, 3};
  vector<int> input_2 = {4, 5, 6};
  ListNode *input1 = inseart_ll<ListNode, vector<int>>(input_1);
  ListNode *input2 = inseart_ll<ListNode, vector<int>>(input_2);
  print_linkedlist(input1);
  print_linkedlist(input2);
  ListNode *result = bruteforce(input1, input2);
  cout << "answer -> ";
  print_linkedlist(result);
  return 0;
}
