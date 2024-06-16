class Solution {
public:
  string removeDuplicates(string s) {
    vector<char> ans;
    for (char c : s) {
      if (!ans.empty() && ans.back() == c) ans.pop_back();
      else ans.push_back(c);
    }
    return string(ans.begin(), ans.end());
  }
};
