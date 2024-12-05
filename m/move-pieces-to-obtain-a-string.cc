class Solution {
public:
  bool canChange(string start, string target) {
    vector<pair<char, int>> A, B; int N = start.size();
    for (int i = 0; i < N; ++i) {
      if (start[i] != '_') A.push_back({start[i], i});
      if (target[i] != '_') B.push_back({target[i], i});
    }
    if (A.size() != B.size()) return false;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i].first != B[i].first) return false;
      char c = A[i].first;
      int ap = A[i].second, bp = B[i].second;
      if (c == 'L' && ap < bp) return false;
      if (c == 'R' && ap > bp) return false;
    }
    return true;
  }
};
