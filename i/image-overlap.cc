#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    int N = img1.size(), ans = 0;
    auto oob = [&](int i, int j) {
      return i < 0 || i >= N || j < 0 || j >= N;
    };
    for (int i2 = -N; i2 < N; ++i2) for (int j2 = -N; j2 < N; ++j2) {
      int cnt = 0;
      for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        if (oob(i + i2, j + j2)) continue;
        cnt += img1[i][j] & img2[i + i2][j + j2];
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};
