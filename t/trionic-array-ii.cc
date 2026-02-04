using ll = long long;

class Solution {
public:
  long long maxSumTrionic(vector<int>& nums) {
    int N = nums.size(), runi = N;
    nums.insert(nums.begin(), -1);
    vector<ll> PL(N + 5, 0), PR(N + 5, 0), PD(N + 5, N);

    for (int i = 1; i <= N; ++i) PL[i] = PL[i - 1] + nums[i];
    for (int i = N; i >= 1; --i) PR[i] = PR[i + 1] + nums[i];
    for (int i = N - 1; i >= 1; --i) {
      if (nums[i] <= nums[i + 1]) runi = i;
      PD[i] = runi;
    }

    ll ans = -1e18;
    for (int i = 1; i <= N; ++i) {
      if (i > 1 && i != PD[i] && PD[i] != PD[i - 1] && PD[i] < N) {
        int li = i - 1, ri = PD[i] + 1;
        if (nums[li] >= nums[i] || nums[ri] <= nums[PD[i]]) continue;

        ll runl = 0, suml = 0, mli = li;
        while (li > 1 && nums[li - 1] < nums[li]) {
          runl += nums[li - 1];
          // if (runl < 0) runl = 0;
          if (suml < runl) {
            suml = runl;
            mli = li - 1;
          }
          --li;
        }

        ll runr = 0, sumr = 0, mri = ri;
        while (ri < N && nums[ri + 1] > nums[ri]) {
          runr += nums[ri + 1];
          // if (runr < 0) runr = 0;
          if (sumr < runr) {
            sumr = runr;
            mri = ri + 1;
          }
          ++ri;
        }

        // cout << "i = " << i << ", PD[i] = " << PD[i] << ", mli = " << mli << ", mri = " << mri << "\n";
        ans = max(ans, PL[mri] - PL[mli - 1]);
      }
    }
    return ans;
  }
};
