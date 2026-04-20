class Solution {
public:
  int maxDistance(vector<int>& colors) {
    int N = colors.size(), ans = 0;
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      if (colors[i] != colors[j]) ans = max(ans, j - i);
    }
    return ans;
  }
};
