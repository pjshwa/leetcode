class Solution {
public:
  bool buddyStrings(string s, string goal) {
    int Z1 = s.size(), Z2 = goal.size();
    if (Z1 != Z2) return false;

    vector<int> diff_idx, cnt(26, 0);
    for (int i = 0; i < Z1; i++) {
      if (s[i] != goal[i]) diff_idx.push_back(i);
      cnt[s[i] - 'a']++;
    }

    if (diff_idx.size() == 0) {
      for (int i = 0; i < 26; i++) if (cnt[i] > 1) return true;
    }
    else if (diff_idx.size() == 2) {
      swap(s[diff_idx[0]], s[diff_idx[1]]);
      return s == goal;
    }
    return false;
  }
};
