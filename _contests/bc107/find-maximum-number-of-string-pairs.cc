class Solution {
public:
  int maximumNumberOfStringPairs(vector<string>& words) {
    map<string, int> T1, T2, S;
    for (auto word : words) {
      char a = word[0], b = word.back();
      if (a == b) S[word]++;
      else if (a < b) T1[word]++;
      else T2[word]++;
    }
      
    int ans = 0;
    for (auto [_, v] : S) ans += v / 2;
    for (auto [k, v] : T1) {
      string k_rev = k; reverse(k_rev.begin(), k_rev.end());
      int r = T2[k_rev];
      ans += min(v, r);
    }
    return ans;
  }
};
