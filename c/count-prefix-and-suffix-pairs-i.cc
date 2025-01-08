class Solution {
  bool isPrefixAndSuffix(string& a, string& b) {
    int az = a.size(), bz = b.size();
    if (az > bz) return false;

    for (int i = 0; i < az; i++) {
      if (a[i] != b[i]) return false;
      if (a[i] != b[bz - az + i]) return false;
    }
    return true;
  }

public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int ans = 0, N = words.size();
    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
      if (isPrefixAndSuffix(words[i], words[j])) ++ans;
    }
    return ans;
  }
};
