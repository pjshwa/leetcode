class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int N = nums.size(); vector<int> res;
    for (int i = 0; i < N; ++i) for (int j = i - k; j <= i + k; ++j) {
      if (j < 0 || j >= N) continue;
      if (nums[j] == key) {
        res.push_back(i);
        break;
      }
    }
    return res;
  }
};
