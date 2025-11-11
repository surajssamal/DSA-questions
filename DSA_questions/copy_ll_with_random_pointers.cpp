#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *random;
  Node *next;

  Node() : val(), random(), next() {};
  Node(int x) : val(x), random(), next() {};
  Node(int x, Node *n) : val(x), random(), next(n) {};
  Node(int x, Node *n, Node *r) : val(x), random(r), next(n) {};
};

Node *copyRandomList(Node *head) {
  unordered_map<Node *, Node *> record;
  Node *curr = head;
  while (curr) {
    Node *temp = new Node(curr->val);
    record[curr] = temp;
    curr = curr->next;
  }
  curr = head;
  while (curr) {
    Node *copy = record[curr];
    copy->next = record[curr->next];
    copy->random = record[curr->random];
    curr = curr->next;
  }
  return record[head];

  int main() { return 0; }
