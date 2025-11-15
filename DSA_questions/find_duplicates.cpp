#include <bits/stdc++.h>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

int solution(vector<int> input) {
  set<int> checking;
  for (auto l : input) {
    if (checking.find(l) != checking.end())
      return l;
    checking.insert(l);
  }
  return false;
}
int main() {
  vector<int> input = {1, 2, 3, 4, 5, 5, 6};
  cout << solution(input) << endl;
}
