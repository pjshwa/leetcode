class Solution {
public:
  int longestPalindrome(string s) {
    sort(s.begin(), s.end());

    int ans = 0; string st;
    for (char c : s) {
      if (!st.empty() && st.back() == c) {
        st.pop_back();
        ans += 2;
      }
      else st.push_back(c);
    }
    if (st.size()) ++ans;
    return ans;
  }
};
