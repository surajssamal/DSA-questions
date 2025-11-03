#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *m) : val(x), next(m) {}
};
void print_linkedlist(ListNode *node) {
  ListNode *printnode = node;
  while (printnode != nullptr) {
    cout << printnode->val << endl;
    printnode = printnode->next;
  }
}
ListNode *Solution(ListNode *input) {
  ListNode *prev = nullptr;
  ListNode *current = input;
  while (current) {
    ListNode *temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
  }
  return prev;
}
int main() {
  vector<int> input = {0, 1, 2, 3};
  ListNode *head = new ListNode(input[0]);
  ListNode *current = head;
  for (int i = 1; i < input.size(); i++) {
    ListNode *input_list = new ListNode(input[i]);
    current->next = input_list;
    current = input_list;
  }
  print_linkedlist(head);

  ListNode *result = Solution(head);
  print_linkedlist(result);
  return 0;
}
