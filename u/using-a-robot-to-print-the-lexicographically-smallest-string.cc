class Solution {
public:
  string robotWithString(string s) {
    int N = s.size();
    vector<char> stack, Ps(N, s.back());
    for (int i = N - 2; i >= 0; --i) {
      Ps[i] = min(Ps[i + 1], s[i]);
    }

    string ans = "";
    for (int i = 0; i < N; ++i) {
      stack.push_back(s[i]);
      while (!stack.empty() && i < N - 1 && stack.back() <= Ps[i + 1]) {
        char c = stack.back(); stack.pop_back();
        ans.push_back(c);
      }
    }
    while (!stack.empty()) {
      char c = stack.back(); stack.pop_back();
      ans += c;
    }
    return ans;
  }
};
