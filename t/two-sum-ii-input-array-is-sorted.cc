class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int ep = n - 1;
    for (int sp = 0; sp < n; sp++) {
      while (ep > sp && numbers[sp] + numbers[ep] > target) ep--;
      if (ep > sp && numbers[sp] + numbers[ep] == target) return {sp + 1, ep + 1};
    }
    return {};
  }
};
