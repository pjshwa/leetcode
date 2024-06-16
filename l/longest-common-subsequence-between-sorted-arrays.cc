class Solution {
  vector<int> lcsOfTwo(vector<int> a, vector<int> b) {
    vector<int> res; int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i] == b[j]) res.push_back(a[i]), ++i, ++j;
      else if (a[i] < b[j]) ++i;
      else ++j;
    }
    return res;
  }

public:
  vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
    int N = arrays.size();
    vector<int> ans = arrays[0];
    for (int i = 1; i < N; ++i) {
      ans = lcsOfTwo(ans, arrays[i]);
    }
    return ans;
  }
};
