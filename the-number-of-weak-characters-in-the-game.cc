class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    set<int> p;
    sort(properties.begin(), properties.end(), [](auto& a, auto& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });

    int ans = 0;
    for (auto& prop : properties) {
      auto it = p.upper_bound(prop[1]);
      if (it != p.end()) ans++;
      p.insert(prop[1]);
    }

    return ans;
  }
};
