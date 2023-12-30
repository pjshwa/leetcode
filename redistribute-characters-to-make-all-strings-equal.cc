class Solution {
public:
  bool makeEqual(vector<string>& words) {
    int C[26]{};
    for (auto word : words) for (char c : word) ++C[c - 'a'];

    int Z = words.size();
    for (int ci = 0; ci < 26; ++ci) if (C[ci] % Z) return false;
    return true;
  }
};
