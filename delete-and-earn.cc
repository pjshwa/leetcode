class Solution {
  int t[10001], d[10001];
public:
  int deleteAndEarn(vector<int>& nums) {
    memset(t, 0, sizeof(t));
    memset(d, 0, sizeof(d));

    sort(nums.begin(), nums.end());
    vector<int> u;
    for (int num : nums) {
      if (u.empty() || num != u.back()) u.push_back(num);
      t[num]++;
    }
    if (u.size() == 1) return u[0] * t[u[0]];

    d[0] = 0, d[1] = u[0] * t[u[0]];
    for (int i = 1; i < u.size(); i++) {
      int addend = u[i] * t[u[i]];
      if (u[i] == u[i - 1] + 1) d[i + 1] = max(d[i - 1] + addend, d[i]);
      else d[i + 1] = d[i] + addend;
    }
    return *max_element(d, d + u.size() + 1);
  }
};
