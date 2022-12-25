class Solution {
public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    vector<int> indices; int n = words.size();
    for (int i = 0; i < n; ++i) {
      string w = words[i];
      if (w == target) indices.push_back(i);
    }
    if (indices.empty()) return -1;

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < indices.size(); ++i) {
      int index = indices[i];
      if (index > startIndex) {
        ans = min(ans, index - startIndex);
        ans = min(ans, n - index + startIndex);
      }
      else if (index < startIndex) {
        ans = min(ans, startIndex - index);
        ans = min(ans, n - startIndex + index)
      }
      else {
        ans = min(ans, 0);
      }
    }
    return ans;
  }
};
