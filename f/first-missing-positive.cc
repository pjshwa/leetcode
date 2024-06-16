const int MAX = 1e5;

class Solution {
  int E[MAX + 1];
public:
  int firstMissingPositive(vector<int>& nums) {
    memset(E, 0, sizeof(E));
    for (int num : nums) {
      if (num <= 0 || num > MAX) continue;
      E[num] = 1;
    }

    for (int i = 1; i <= MAX; i++) {
      if (E[i] == 0) return i;
    }
    return MAX + 1;
  }
};
