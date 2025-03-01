class Solution {
public:
  int minSwaps(vector<int>& data) {
    int ocnt = 0, N = data.size();
    for (int e : data) ocnt += e;

    int ans = 0;
    for (int i = 0; i < ocnt; ++i) ans += data[i] == 0;

    int cur = ans;
    for (int i = ocnt; i < N; ++i) {
      cur += data[i] == 0;
      cur -= data[i - ocnt] == 0;
      ans = min(ans, cur);
    }
    return ans;
  }
};
