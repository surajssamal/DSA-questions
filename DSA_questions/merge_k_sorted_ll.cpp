#include "linked_list_use.h"
#include <algorithm>
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
// merge sort helper function
ListNode *merge_sort(ListNode *l1, ListNode *l2) {
  ListNode *dummy = new ListNode();
  ListNode *curr = dummy;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      curr->next = l1;
      l1 = l1->next;
    } else {
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }
  if (l1) {
    curr->next = l1;
  } else {
    curr->next = l2;
  }

  return dummy->next;
};
// via merge sort
ListNode *merge_sort_way(vector<ListNode *> &inputs_ll_copy) {
  if (inputs_ll_copy.empty())
    return NULL;
  for (int i = 1; i < inputs_ll_copy.size(); i++) {
    inputs_ll_copy[i] = merge_sort(inputs_ll_copy[i - 1], inputs_ll_copy[i]);
  }
  return inputs_ll_copy.back();
}

// brute force method
ListNode *brute_force(vector<ListNode *> input_ll) {
  vector<int> nums;
  for (auto s : input_ll) {
    while (s) {
      nums.push_back(s->val);
      s = s->next;
    }
  }
  sort(nums.begin(), nums.end());
  ListNode *result = new ListNode(nums[0]);
  ListNode *curr = result;
  for (int i = 1; i < nums.size(); i++) {
    ListNode *temp = new ListNode(nums[i]);
    curr->next = temp;
    curr = curr->next;
  }

  return result;
};

int main() {
  vector<vector<int>> input = {{1, 2, 4, 9, 12}, {1, 3, 5}, {3, 6}};
  vector<ListNode *> inputs_ll;

  for (auto s : input) {
    inputs_ll.push_back(inseart_ll<ListNode, vector<int>>(s));
  }
  for (auto k : inputs_ll) {
    print_linkedlist(k);
    ListNode *head = brute_force(inputs_ll);
    cout << endl;
    print_linkedlist(head);
    vector<ListNode *> input_ll_copy(inputs_ll);
    ListNode *head_merge = merge_sort_way(input_ll_copy);
    print_linkedlist(head_merge);
    return 0;
  };
};
