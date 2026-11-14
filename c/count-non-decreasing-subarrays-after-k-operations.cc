#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
    int N = nums.size();
    vector<int> nxt(N, N), st;

    for (int i = 0; i < N; ++i) {
      while (!st.empty() && nums[st.back()] <= nums[i]) {
        nxt[st.back()] = i;
        st.pop_back();
      }
      st.push_back(i);
    }

    deque<int> dq;
    ll l = 0, cost = 0, ans = 0;

    for (int r = 0; r < N; ++r) {
      while (!dq.empty() && nums[dq.back()] <= nums[r]) dq.pop_back();
      dq.push_back(r);
      cost += nums[dq.front()] - nums[r];

      while (cost > k) {
        int end = min(nxt[l], r + 1), j = l + 1;
        while (j < end) {
          int t = min(nxt[j], end);
          cost -= 1LL * (nums[l] - nums[j]) * (t - j);
          j = t;
        }
        if (dq.front() == l) dq.pop_front();
        ++l;
      }
      ans += r - l + 1;
    }
    return ans;
  }
};
