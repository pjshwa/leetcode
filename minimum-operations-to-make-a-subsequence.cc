class Solution {
public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    map<int, int> vmap;
    for (int i = 0; i < target.size(); ++i) vmap[target[i]] = i;

    vector<int> seq;
    for (int e : arr) if (vmap.count(e)) seq.push_back(vmap[e]);

    // Longest increasing subsequence in seq.
    vector<int> lis;
    for (int e : seq) {
      auto it = lower_bound(lis.begin(), lis.end(), e);
      if (it == lis.end()) lis.push_back(e);
      else *it = e;
    }

    return target.size() - lis.size();
  }
};
