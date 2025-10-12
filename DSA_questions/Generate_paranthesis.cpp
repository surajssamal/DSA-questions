#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool is_valid(const string &s) {
    int open_param = 0;
    for (char c : s) {
      open_param += (c == '(') ? 1 : -1;
      if (open_param < 0) {
        return false;
      }
    }
    return open_param == 0;
  }
  void dfs(string s, vector<string> &res, int n) {
    if (s.length() == 2 * n) {
      if (is_valid(s)) {
        res.push_back(s);
      }
      return;
    }
    dfs(s + '(', res, n);
    dfs(s + ')', res, n);
  }
  vector<string> Generate_param(int n) {
    vector<string> res;
    dfs("", res, n);
    return res;
  }
};
class backtracking_way {
private:
  int n;
  string param_stack;
  vector<string> result;

public:
  void backtracking(int OpenN, int CloseN) {
    if (OpenN == CloseN && CloseN == n) {
      result.push_back(param_stack);
      return;
    }
    if (OpenN < n) {
      param_stack += "(";
      backtracking(OpenN + 1, CloseN);
      param_stack.pop_back();
    }
    if (CloseN < OpenN) {
      param_stack += ")";
      backtracking(OpenN, CloseN + 1);
      param_stack.pop_back();
    };
  };
  backtracking_way(int n) { this->n = n; };
  vector<string> backtrack_start() {

    backtracking(0, 0);
    return result;
  };
};
int main() {
  int n;
  cout << "give the number :- ";
  cin >> n;
  Solution *s;
  vector<string> res = s->Generate_param(n);
  for (auto s : res) {
    cout << s << endl;
  }
  cout << "using the bakctracking method" << endl;
  backtracking_way *r = new backtracking_way(n);
  vector<string> result = r->backtrack_start();
  for (auto s : result) {
    cout << s << endl;
  }
  return 0;
}
