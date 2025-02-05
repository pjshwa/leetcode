class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int N = s1.size();
    vector<int> pos_d;
    for (int i = 0; i < N; ++i) {
      if (s1[i] != s2[i]) pos_d.push_back(i);
    }
    if (pos_d.empty()) return true;
    if (pos_d.size() != 2) return false;
    swap(s1[pos_d[0]], s1[pos_d[1]]);
    return s1 == s2;
  }
};
