#include "linked_list_use.h"
#include "print_array.h"
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
struct nodeT {
  int val;
  nodeT *next;
  nodeT() : val(0), next(nullptr) {}
  nodeT(int x) : val(x), next(nullptr) {}
  nodeT(int x, nodeT *m) : val(0), next(m) {}
};

bool o1_method(nodeT *head) {
  nodeT *slow = head;
  nodeT *fast = head;

  while (fast && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

bool solution(nodeT *head) {
  nodeT *current = head;
  set<nodeT *> checking;
  while (current) {
    if (checking.count(current->next)) {
      return true;
    }
    checking.insert(current->next);
    current = current->next;
  }
  return false;
}

int main() {
  vector<int> input = {
      1,
      2,
      3,
      4,
  };
  nodeT *head = new nodeT(input[0]);
  nodeT *current = head;
  for (int i = 1; i < input.size() - 1; i++) {
    nodeT *temp = new nodeT(input[i]);
    current->next = temp;
    current = temp;
  };
  current->next = head;
  cout << solution(head) << endl;
  cout << o1_method(head) << endl;
  return 0;
}
