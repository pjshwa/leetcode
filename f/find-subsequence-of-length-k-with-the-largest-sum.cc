class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<pair<int, int>> nums_i; int N = nums.size();
    for (int i = 0; i < N; ++i) nums_i.push_back({nums[i], i});
    sort(nums_i.begin(), nums_i.end(), greater<>());

    vector<int> indices;
    for (int i = 0; i < k; ++i) indices.push_back(nums_i[i].second);
    sort(indices.begin(), indices.end());

    vector<int> ans;
    for (int i = 0; i < k; ++i) ans.push_back(nums[indices[i]]);
    return ans;
  }
};
