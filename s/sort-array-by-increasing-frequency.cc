class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    map<int, int> tal;
    for (int e : nums) ++tal[e];

    vector<pair<int, int>> V;
    for (auto& [k, v] : tal) V.emplace_back(v, k);
    sort(V.begin(), V.end(), [](auto& a, auto& b) {
      return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    vector<int> ans;
    for (auto& [k, v] : V) ans.insert(ans.end(), k, v);
    return ans;
  }
};
