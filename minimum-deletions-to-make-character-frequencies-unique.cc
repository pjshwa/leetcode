class Solution {
public:
  int minDeletions(string s) {
    map<char, int> freq;
    for (auto c : s) freq[c]++;

    int freq_max = 0;
    for (auto [_, f] : freq) freq_max = max(freq_max, f);

    int ans = 0;
    for (int fc = freq_max; fc >= 1; fc--) {
      bool first = true;
      for (auto& [_, f] : freq) {
        if (f != fc) continue;
        if (first) first = false;
        else f--, ans++;
      }
    }
    return ans;
  }
};
