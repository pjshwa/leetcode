#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasGroupsSizeX(vector<int>& deck) {
    map<int, int> counts;
    for (auto &el : deck) {
      auto found = counts.find(el);
      if (found != counts.end()) found->second++;
      else counts.insert({el, 1});
    }

    int g = counts.begin()->second;
    for (auto &item : counts) {
      g = __gcd(g, item.second);
    }

    return g != 1;
  }
};

int main() {
  Solution solution;

}

