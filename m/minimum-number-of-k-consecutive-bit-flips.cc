class Solution {
public:
  int minKBitFlips(vector<int>& nums, int k) {
    int N = nums.size(), ans = 0; queue<int> Q;
    for (int i = 0; i < N; ++i) {
      if (!Q.empty() && Q.front() == i) Q.pop();
      if (nums[i] ^ (Q.size() & 1)) continue;
      if (i <= N - k) Q.push(i + k), nums[i] ^= 1, ++ans;
      else return -1;
    }
    return ans;
  }
};
