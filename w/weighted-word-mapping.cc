#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string mapWordWeights(vector<string>& words, vector<int>& weights) {
    string ans = "";
    for (auto& w : words) {
      int sum = 0;
      for (auto& c : w) sum = (sum + weights[c - 'a']) % 26;
      ans += (char)('a' + 25 - sum);
    }
    return ans;
  }
};
