class Solution {
public:
  int countCharacters(vector<string>& words, string chars) {
    int D[26] = {0}, ans = 0;
    for (char c : chars) D[c - 'a']++;

    for (auto word : words) {
      int S[26] = {0};
      for (char c : word) S[c - 'a']++;

      bool ok = true;
      for (int i = 0; i < 26; i++) ok &= S[i] <= D[i];
      if (ok) ans += word.size();
    }
    return ans;
  }
};
