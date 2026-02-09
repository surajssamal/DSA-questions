#include <bits/stdc++.h>
#include <climits>
using namespace std;

/*
 *observations
  >filip has rows of cell in which there are blocks
    >some blocks are empty
      >he wants to fill the empty one with water
        > action 1. he can either fill water in the empty cell
        > action 2. remove water from an empty and fill other
      > if i [2<=i<=n-1] i+1 has water and i-1 has water then we consider there
        is already water in i (cause the water flows right)
    >some are blocked where you can't pour water

 * objective :-
  to find the min number of time we have to use action 1
  note :- we dont necessarily need to minimize the action 2

 * Test cases
  inputs 1:-
  n=7
  string =##....#
  explaination:-
  string[3]=='.' -> we can fill water into it (action 1)
  string[5]=='.' -> we can fill water into it also (action 1)
  string[4]=='.' -> will automaticall be filled with cause of 3,5
  string[6]=='.' -> take water from 5 and dump in 6 (action 2)
  string[5]=='.' -> will get filled if 4,6 are filled
  output =2 (cause we're required to output number of action 1 step took)


  input 2:-10
  string =#...#..#.#
  explaination:-
  string[2]=='.' -> we can fill water into it (action 1)
  string[4]=='.' -> we can fill water into it (action 1)
  string[3]=='.' -> will automaticall be filled with cause of 2,4
  string[6]=='.' -> replace water from 4 and dump in 6 (action 2)
  string[7]=='.' -> replace water from 4 and dump in 7 (action 2)
  string[9]=='.' -> replace water from 4 and dump in 9 (action 2)
  output =2 (cause we're required to output number of action 1 step took)

  hint :- if there is water in i-1 and i+1 then if we replace water from i and
  delever it to an empty cell the i will fill automaticall and the water is in
  infite supply we dont have to do action 1 repetedly we can just perform
  action 2
*/

int solution(int n, string inputs) {
  if (n <= 1) {
    return 1 ? inputs == "." : 0;
  }
  int result = 1 ? inputs[0] == '.' : 0;
  for (int i = 1; i < n; i++) {
    if (inputs[i] == '.' && inputs[i - 1] == '.' && inputs[i + 1] == '.') {
      result = 2;
      return result;
    } else if (inputs[i] == '.') {
      result += 1;
    }
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string inputs;
    cin >> inputs;
    cout << solution(n, inputs) << endl;
  }
}

/*
 *test case
  5
  3
  ...
  7
  ##....#
  7
  ..#.#..
  4
  ####
  10
  #...#..#.#

output :
  2
  2
  5
  0
  2
*/
