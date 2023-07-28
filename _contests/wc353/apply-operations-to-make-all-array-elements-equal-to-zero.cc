using ll = long long;

class Solution {
public:
  bool checkArray(vector<int>& nums, int k) {
    int N = nums.size();

    ll d[N + 1]; memset(d, 0, sizeof(d));

    ll dt = 0;
    for (int i = 0; i < N; i++) {
      dt += d[i];
      if (dt > nums[i]) return false;

      if (i + k > N) {
        ll dif = nums[i] - dt;
        if (dif != 0) return false;
      }
      else {
        ll dif = nums[i] - dt;
        dt += dif;
        d[i + k] -= dif;
      }
    }

    return true;
  }
};
