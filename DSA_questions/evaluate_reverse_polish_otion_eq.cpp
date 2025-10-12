#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;
int eval_RPN(vector<string> &token) {
  stack<int> equation;
  for (const string &c : token) {
    if (c == "+") {
      int a = equation.top();
      equation.pop();
      int b = equation.top();
      equation.pop();
      equation.push(b + a);
    } else if (c == "-") {
      int a = equation.top();
      equation.pop();
      int b = equation.top();
      equation.pop();
      equation.push(b - a);
    } else if (c == "*") {
      int a = equation.top();
      equation.pop();
      int b = equation.top();
      equation.pop();
      equation.push(b * a);
    } else if (c == "/") {
      int a = equation.top();
      equation.pop();
      int b = equation.top();
      equation.pop();
      equation.push(b / a);
    } else {
      equation.push(stoi(c));
    }
  }
  return equation.top();
}
int main() {

  vector<string> rev_polish_eq = {"1", "2", "+", "3", "*", "4", "-"};
  int res = eval_RPN(rev_polish_eq);
  cout << res << endl;
  return 0;
}
