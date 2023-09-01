class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ret;

    for (int i = 0; i <= n; ++i) {
      int num = i, one_cnt = 0;
      while (num) {
        if (num % 2) one_cnt += 1;
        num /= 2;
      }
      ret.push_back(one_cnt);
    }

    return ret;
  }
};
