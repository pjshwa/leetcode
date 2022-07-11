class Solution {
  int t[1000][26] = {0};

  bool overlaps(int i, int j) {
    int res = 0;
    for (int l = 0; l < 26; l++) res += t[i][l] * t[j][l];
    return res > 0;
  }
  
public:
  int maxProduct(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; i++) {
      for (char c : words[i]) t[i][c - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      if (overlaps(i, j)) continue;
      ans = max(ans, (int)words[i].size() * (int)words[j].size());
    }

    return ans;
  }
};
