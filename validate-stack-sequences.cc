#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int sz = pushed.size();
    if (sz <= 2) return true;

    int sp = 0, psp = 0;
    stack<int> sim;

    while (pushed[sp] != popped[0]) sim.push(pushed[sp++]);
    sim.push(pushed[sp++]);

    while (psp < sz) {
      if (!sim.empty() && popped[psp] == sim.top()) sim.pop();
      else {
        while (sp < sz && pushed[sp] != popped[psp]) sim.push(pushed[sp++]);
        if (sp == sz) return false;
        else sp++;
      }

      psp++;
    }
    return true;
  }
};

int main() {
  Solution solution;

  vector<int> pushed1 = {1, 2, 3, 4, 5};
  vector<int> popped1 = {4, 5, 3, 2, 1};
  cout << solution.validateStackSequences(pushed1, popped1) << endl;

  vector<int> pushed2 = {1, 2, 3, 4, 5};
  vector<int> popped2 = {4, 5, 3, 1, 2};
  cout << solution.validateStackSequences(pushed2, popped2) << endl;

  vector<int> pushed3;
  vector<int> popped3;
  cout << solution.validateStackSequences(pushed3, popped3) << endl;
}
