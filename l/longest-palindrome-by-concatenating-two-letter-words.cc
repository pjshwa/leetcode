class Solution {
public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> tal;
    for (auto& word : words) ++tal[word];

    int ans = 0, o = 0;
    for (char c1 = 'a'; c1 <= 'z'; ++c1) for (char c2 = c1 + 1; c2 <= 'z'; ++c2) {
      string s1(1, c1); s1 += c2;
      string s2(1, c2); s2 += c1;
      ans += min(tal[s1], tal[s2]) * 4;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      string s(2, c);
      ans += (tal[s] / 2) * 4;
      if (tal[s] % 2) o = 2;
    }
    return ans + o;
  }
};
