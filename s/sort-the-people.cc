class Solution {
public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> v; int N = names.size();
    for (int i = 0; i < N; ++i) v.emplace_back(heights[i], names[i]);
    sort(v.begin(), v.end(), greater<>());

    vector<string> ans;
    for (auto& [h, n] : v) ans.push_back(n);
    return ans;
  }
};
