class Solution {
public:
  long long largestPerimeter(vector<int>& nums) {
    long long sum = 0;
    for (int e : nums) sum += e;

    sort(nums.begin(), nums.end(), greater<int>());
    for (int e : nums) {
      sum -= e;
      if (sum > e) return sum + e;
    }
    return -1;
  }
};
