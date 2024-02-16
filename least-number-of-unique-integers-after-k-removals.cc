class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    map<int, int> t;
    for (int e : arr) ++t[e];

    vector<int> vs;
    for (auto& [_, v] : t) vs.push_back(v);
    sort(vs.begin(), vs.end());

    int acc = 0, ans = 0;
    for (int v : vs) {
      if (acc + v <= k) {
        acc += v;
        ++ans;
      }
      else break;
    }
    return vs.size() - ans;
  }
};
