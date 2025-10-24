#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {

public:
  unordered_map<string, unordered_map<int, vector<string>>> command;
  TimeMap() {};
  void set(string name, string emothion, int timelaps) {
    command[name][timelaps].push_back(emothion);
  };
  string get(string name, int timelaps) {
    if (command.find(name) == command.end()) {
      return "";
    }
    int seen = 0;

    for (auto &[time, _] : command[name]) {
      if (time <= timelaps) {
        seen = max(seen, time);
      }
    }
    return seen == 0 ? "" : command[name][seen].back();
  }
};

class Binary_search_Timemap {
public:
  unordered_map<string, vector<pair<int, string>>> command;
  Binary_search_Timemap() {}
  void set(string name, string emotion, int timestamp) {
    command[name].push_back({timestamp, emotion});
  }
  string get(string name, int timestamp) {
    auto &value = command[name];
    int left = 0;
    int right = value.size() - 1;
    string result = "";

    while (left <= right) {
      int mid = (left + right) / 2;
      if (value[mid].first <= timestamp) {
        result = value[mid].second;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return result;
  }
};

int main() {
  TimeMap timemap = *new TimeMap();
  timemap.set("alice", "happy", 1);
  cout << timemap.get("alice", 1) << endl;
  cout << timemap.get("alice", 2) << endl;
  // using binary soart method
  Binary_search_Timemap timemap_2 = *new Binary_search_Timemap;

  timemap_2.set("alice", "sad", 1);
  cout << timemap_2.get("alice", 1) << endl;
  cout << timemap_2.get("alice", 2) << endl;
  return 0;
}
