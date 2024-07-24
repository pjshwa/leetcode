class Solution {
public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    auto map = [&](int e) {
      string e_str = to_string(e);
      string mapped_str = "";
      for (char c : e_str) {
        mapped_str += to_string(mapping[c - '0']);
      }
      return stoi(mapped_str);
    };

    vector<tuple<int, int, int>> mapped; int N = nums.size();
    for (int i = 0; i < N; ++i) {
      int e = nums[i];
      mapped.push_back({map(e), i, e});
    }
    sort(mapped.begin(), mapped.end());

    vector<int> ans;
    for (auto [_, i, e] : mapped) ans.push_back(e);
    return ans;
  }
};
