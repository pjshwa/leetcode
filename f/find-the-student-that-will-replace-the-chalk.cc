class Solution {
public:
  int chalkReplacer(vector<int>& chalk, int k) {
    long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
    k %= sum;

    int N = chalk.size();
    for (int i = 0; i < N; ++i) {
      if (chalk[i] > k) return i;
      k -= chalk[i];
    }
    return -1;
  }
};
