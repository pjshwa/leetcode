class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    string chars[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    set<string> c[5];
    c[0].insert("");

    for (int i = 0; i < digits.size(); i++) {
      int digit = digits[i] - '0';
      for (auto& p : c[i]) for (char& ch : chars[digit]) c[i + 1].insert(p + ch);
    }

    vector<string> ans{c[digits.size()].begin(), c[digits.size()].end()};
    return ans;
  }
};
