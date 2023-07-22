class Solution {
public:
  int trap(vector<int>& height) {
    int N = height.size();

    int L[N], R[N];
    {
      deque<int> S;
      for (int i = 0; i < N; i++) {
        while (!S.empty() && S.back() <= height[i]) S.pop_back();
        L[i] = S.empty() ? 0 : S.front();
        S.push_back(height[i]);
      }
    }
    {
      deque<int> S;
      for (int i = N - 1; i >= 0; i--) {
        while (!S.empty() && S.back() <= height[i]) S.pop_back();
        R[i] = S.empty() ? 0 : S.front();
        S.push_back(height[i]);
      }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
      int h = min(L[i], R[i]);
      ans += max(0, h - height[i]);
    }
    return ans;
  }
};
