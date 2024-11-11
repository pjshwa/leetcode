class Solution {
  bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

public:
  bool primeSubOperation(vector<int>& nums) {
    vector<int> primes{2};
    for (int i = 3; i <= 1000; i += 2) if (is_prime(i)) primes.push_back(i);

    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      int val = nums[i];
      for (int p : primes) {
        if (p >= val) break;
        if (i > 0 && val - p <= nums[i - 1]) break;
        nums[i] = val - p;
      }
    }

    int ok = 1;
    for (int i = 1; i < N; ++i) ok &= nums[i] > nums[i - 1];
    return ok;
  }
};
