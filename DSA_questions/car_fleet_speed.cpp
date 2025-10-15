#include "print_array.h"
#include <bits/stdc++.h>
#include <stack>
using namespace std;

int car_fleet(vector<int> &position, vector<int> &velocity, int target) {
  vector<pair<int, int>> position_velocity_pair;
  for (int i = 0; i < position.size(); i++) {
    position_velocity_pair.push_back({position[i], velocity[i]});
  }
  sort(position_velocity_pair.rbegin(), position_velocity_pair.rend());
  vector<double> stack;
  for (int i = 0; i < position_velocity_pair.size(); i++) {
    stack.push_back((double)(target - position_velocity_pair[i].first) /
                    position_velocity_pair[i].second);
    if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) {
      stack.pop_back();
    }
  }
  return stack.size();
}

int main() {
  vector<int> position = {4, 1, 0, 7};
  vector<int> velocity = {2, 2, 1, 1};
  int target = 12;
  cout << car_fleet(position, velocity, target) << endl;

  return 0;
}
