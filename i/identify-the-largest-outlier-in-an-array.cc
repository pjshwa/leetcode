class Solution {
public:
  int getLargestOutlier(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    map<int, int> tal; int sum = 0;
    for (int num : nums) sum += num, ++tal[num];
    for (int num : nums) {
      --tal[num];
      int psum = sum - num;
      if (psum % 2 == 0 && tal[psum / 2] > 0) return num;
      ++tal[num];
    }
    return -1;
  }
};
  