const int MOD = 1e9 + 7;

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    deque<int> dq(forget, 0);
    dq.back() = 1;

    int it = n;
    while (--it) {
      dq.pop_front();

      int cur = 0;
      for (int i = 0; i < forget - delay; ++i) {
        cur = (cur + dq[i]) % MOD;
      }
      dq.push_back(cur);
    }

    return accumulate(dq.begin(), dq.end(), 0LL) % MOD;
  }
};
