#include <bits/stdc++.h>
using namespace std;

void print_arr(vector<int> &vec) {
  for (auto i : vec) {
    cout << i << ",";
  }
  cout << endl;
}
int main() {
  // pairs
  pair<int, int> p = {4, 2};
  cout << p.first << ":" << p.second << endl;
  // if want more that 2 like 3
  pair<int, pair<int, int>> k = {1, {2, 3}};
  cout << k.first << ":" << k.second.first << " " << k.second.second << endl;
  // if want a array of pairs here's it
  pair<int, int> s[] = {{1, 2}, {4, 5}, {6, 7}, {8, 9}};
  cout << s[0].first << endl;

  // vectors
  vector<int> v;
  // will push number into v
  v.push_back(12);
  v.emplace_back(21);
  // pair of vectors
  vector<pair<int, int>> vec;
  vec.push_back({12, 1});
  vec.emplace_back(21, 23);
  print_arr(v);
  for (auto i : vec) {
    cout << i.first << " " << i.second << endl;
  }

  // declaring vector with prepush values
  vector<int> some(5, 3);
  print_arr(some);
  // vector erase
  vector<int> l = {2, 3, 4, 5, 6};
  print_arr(l);
  l.erase(l.begin() + 1,
          l.begin() + 3); // here we're earasing the 1-3 elements in the
  print_arr(l);
  // inserting in the begining of the vector
  l.insert(l.begin() + 1, 200); // this sates that the number 200 will be added
                                // in the begining of the vectors
  print_arr(l);
  // insearting in the middle whichover position you want
  l.insert(l.begin() + 3, 2,
           12); // this appends 12 3 times in 3rd position of the vector
  print_arr(l);

  // stack in cpp
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  cout << st.top() << endl; // works on the principle of LIfo
  cout << st.size() << endl;
  cout << st.empty();

  // queue
  queue<int> qu;
  qu.push(16);
  qu.push(15);
  qu.push(14);
  qu.push(13);
  cout << qu.front() << endl;
  cout << qu.back() << endl;

  // priority queue
  priority_queue<int> pr_q;
  pr_q.push(12);
  pr_q.push(14);
  pr_q.push(13);
  cout << pr_q.top() << endl; // puts the largest amount in the top

  // set
  set<int> some_set;
  some_set.insert(12);
  some_set.insert(132);
  some_set.insert(112);
  some_set.insert(23);
  for (auto it : some_set) {
    cout << it << endl;
  }
  auto it = some_set.find((23)); // finding the element position in the set
  cout << *it << endl;

  // map
  map<int, int> mp;
  mp.insert({2, 3});
  mp.insert({3, 54});
  mp.insert({5, 4});

  for (auto it : mp) {
    cout << it.first << " " << it.second << endl;
  }
  // anthoer eg
  map<int, pair<int, int>> mpp;
  mpp.insert({1, {4, 5}});
  for (auto it : mpp) {
    cout << it.first << " " << it.second.first << "," << it.second.second
         << endl;
  }

  return 0;
}
