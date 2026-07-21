class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    vector<int> Z; int str = 0, ans = 0;
    auto push = [&](int v) {
      if (v > 0) Z.push_back(v);
    };
    for (auto& c : s) {
      if (c == '0') ++str;
        else {
        push(str);
        str = 0;
        ++ans;
      }
    }
    push(str);

    int add = 0;
    for (int i = 1; i < Z.size(); ++i) {
      add = max(add, Z[i] + Z[i - 1]);
    }
    return ans + add;
  }
};
