void calculate_pi(vector<int>& pi, const vector<int>& str) {
  pi[0] = -1;
  for (int i = 1, j = -1; i < str.size(); i++) {
    while (j >= 0 && str[i] != str[j + 1]) j = pi[j];
    if (str[i] == str[j + 1])
      pi[i] = ++j;
    else
      pi[i] = -1;
  }
}

vector<int> kmp(const vector<int>& text, const vector<int>& pattern) {
  vector<int> pi(pattern.size()), ans;
  if (pattern.size() == 0) return ans;
  calculate_pi(pi, pattern);

  for (int i = 0, j = -1; i < text.size(); i++) {
    while (j >= 0 && text[i] != pattern[j + 1]) j = pi[j];
    if (text[i] == pattern[j + 1]) {
      j++;
      if (j + 1 == pattern.size()) {
        ans.push_back(i - j);
        j = pi[j];
      }
    }
  }
  return ans;
}

class Solution {
public:
  int strStr(string haystack, string needle) {
    vector<int> text, pattern;
    for (auto c : haystack) text.push_back(c);
    for (auto c : needle) pattern.push_back(c);

    auto res = kmp(text, pattern);
    if (res.empty()) return -1;
    return res[0];
  }
};
