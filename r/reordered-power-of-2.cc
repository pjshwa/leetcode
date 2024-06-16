class Solution {
public:
  bool reorderedPowerOf2(int n) {
    vector<string> candidates;
    int c = 1;
    while (c <= 1e9) {
      string s = to_string(c);
      sort(s.begin(), s.end());
      candidates.push_back(s);
      c *= 2;
    }

    string s = to_string(n);
    sort(s.begin(), s.end());
    return find(candidates.begin(), candidates.end(), s) != candidates.end();
  }
};
