class Solution {
public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    vector<int> res; int N = nums.size();
    for (int i = 0; i <= N - k; ++i) {
      map<int, int> freq;
      for (int j = i; j < i + k; ++j) ++freq[nums[j]];

      vector<pair<int, int>> freq_vec;
      for (auto& [num, count] : freq) freq_vec.push_back({count, num});
      sort(freq_vec.begin(), freq_vec.end(), greater<pair<int, int>>());
      int Z = min(x, (int)freq_vec.size()), sum = 0;
      for (int i = 0; i < Z; ++i) {
        auto [num, count] = freq_vec[i];
        sum += num * count;
      }
      res.push_back(sum);
    }
    return res;
  }
};
