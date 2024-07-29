class Solution {
public:
  int numTeams(vector<int>& rating) {
    int N = rating.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      int sl = 0, sr = 0;
      for (int j = 0; j < i; ++j) sl += rating[j] < rating[i];
      for (int j = i + 1; j < N; ++j) sr += rating[j] < rating[i];
  
      int ll = i - sl, lr = N - i - 1 - sr;
      ans += sl * lr + sr * ll;
    }
    return ans;
  }
};
