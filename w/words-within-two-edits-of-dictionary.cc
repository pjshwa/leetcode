class Solution {
public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> ans; int Z = queries[0].size();
    for (auto& q : queries) {
      int ok = 0;
      for (auto& w : dictionary) {
        int dif = 0;
        for (int i = 0; i < Z; ++i) dif += q[i] != w[i];
        if (dif <= 2) { ok = 1; break; }
      }
      if (ok) ans.push_back(q);
    }
    return ans;
  }
};
