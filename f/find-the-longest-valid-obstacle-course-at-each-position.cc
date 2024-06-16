class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> L, ans;
    for (int o : obstacles) {
      if (L.empty() || o >= L.back()) {
        L.push_back(o);
        ans.push_back(L.size());
      }
      else {
        auto it = upper_bound(L.begin(), L.end(), o);
        assert(it != L.end());

        *it = o;
        ans.push_back(it - L.begin() + 1);
      }
    }
    return ans;
  }
};
