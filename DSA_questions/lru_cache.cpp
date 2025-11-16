#include "linked_list_use.h"
#include "printcpp.hpp"
#include <bits/stdc++.h>
#include <cstddef>
#include <unordered_map>
using namespace std;
struct node {
  int key;
  int val;
  node *next;
  node *prev;
  // initialiazations
  node() : key(0), val(0), next(nullptr), prev(nullptr) {};
  node(int k) : key(k), val(0), next(nullptr), prev(nullptr) {};
  node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {};
  node(int k, int v, node *nex) : key(k), val(v), next(nex), prev(nullptr) {};
  node(int k, int v, node *nex, node *pre)
      : key(k), val(v), next(nex), prev(pre) {};
};

class LRUCache {
private:
  int cap;
  unordered_map<int, node *> cache;
  node *left;
  node *right;

  void remove(node *n) {
    node *prev = n->prev;
    node *nxt = n->next;
    prev->next = nxt;
    nxt->prev = prev;
  }
  void insert(node *n) {
    node *prev = right->prev;
    prev->next = n;
    n->prev = prev;
    n->next = right;
    right->prev = n;
    print_linkedlist(left);
  }

public:
  LRUCache(int capacity) {
    cap = capacity;
    cache.clear();
    left = new node();
    right = new node();
    left->next = right;
    right->prev = left;
  };

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      remove(cache[key]);
    }
    node *temp = new node(key, value);
    cache[key] = temp;
    insert(temp);
    if (cache.size() > cap) {
      node *lru = left->next;
      remove(lru);
      cache.erase(lru->key);
      delete lru;
    }
  };
  int get(int key) {
    if (cache.find(key) != cache.end()) {
      node *n = cache[key];
      remove(n);
      insert(n);
      return n->val;
    };
    return -1;
  };
};

int main() {
  LRUCache instance(2);
  instance.put(1, 12);
  cout << instance.get(1) << endl;
  instance.put(2, 14);
  cout << instance.get(2) << endl;
  instance.put(3, 16);
  instance.put(5, 35);
  cout << instance.get(3) << endl;
  cout << instance.get(1) << endl;
  return 0;
}
