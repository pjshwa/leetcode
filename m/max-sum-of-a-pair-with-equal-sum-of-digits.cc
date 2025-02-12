const int MAXD = 100;

class Solution {
public:
  int maximumSum(vector<int>& nums) {
    vector<int> V[MAXD];
    for (int e : nums) {
      int dsum = 0;
      for (auto c : to_string(e)) dsum += c - '0';
      V[dsum].push_back(e);
    }

    int ans = -1;
    for (int i = 0; i < MAXD; i++) {
      auto& v = V[i];
      sort(v.begin(), v.end(), greater<int>());
      if (v.size() >= 2) ans = max(ans, v[0] + v[1]);
    }
    return ans;
  }
};
