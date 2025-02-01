const int MAXV = 1e5;

class Solution {
public:
  vector<int> distinctNumbers(vector<int>& nums, int k) {
    int N = nums.size(), cnt = 0;
    vector<int> tal(MAXV + 1, 0);

    auto inc = [&](int x, int d) {
      if (tal[x] == 0) ++cnt;
      tal[x] += d;
      if (tal[x] == 0) --cnt;
    };
    for (int i = 0; i < k; ++i) inc(nums[i], 1);

    vector<int> res = {cnt};
    for (int i = 1; i < N - k + 1; ++i) {
      inc(nums[i - 1], -1);
      inc(nums[i + k - 1], 1);
      res.push_back(cnt);
    }
    return res;
  }
};
