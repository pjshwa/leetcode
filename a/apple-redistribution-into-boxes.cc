class Solution {
public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int M = capacity.size(), asum = accumulate(apple.begin(), apple.end(), 0), csum = 0;
    sort(capacity.rbegin(), capacity.rend());
    for (int i = 0; i < M; ++i) {
      csum += capacity[i];
      if (csum >= asum) return i + 1;
    }
    return -1;
  }
};
