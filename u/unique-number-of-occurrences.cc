class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    int n = arr.size();
    map<int, int> t;
    for (int i = 0; i < n; i++) {
      t[arr[i]]++;
    }

    set<int> u;
    for (auto [_, v] : t) u.insert(v);
    return u.size() == t.size();
  }
};
