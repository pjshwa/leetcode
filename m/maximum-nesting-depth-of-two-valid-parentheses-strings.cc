class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans; int C[2]{};
    for (auto c : seq) {
      if (c == '(') {
        int k = C[0] != C[1];
        ans.push_back(k);
        ++C[k];
      } else {
        int k = C[0] == C[1];
        ans.push_back(k);
        --C[k];
      }
    }
    return ans;
  }
};
