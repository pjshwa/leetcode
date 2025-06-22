class Solution {
public:
  vector<string> divideString(string s, int k, char fill) {
    int N = s.size();
    vector<string> res;
    for (int i = 0; i < N; i += k) {
      string part = s.substr(i, k);
      if (part.size() < k) {
        part.append(k - part.size(), fill);
      }
      res.push_back(part);
    }
    return res;
  }
};
