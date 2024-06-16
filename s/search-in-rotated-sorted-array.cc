class Solution {
public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] < nums[right]) right = mid;
      else left = mid + 1;
    }

    int bias = left;
    left = 0, right = n - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[(mid + bias) % n] < target) left = mid + 1;
      else right = mid;
    }

    return nums[(left + bias) % n] == target ? (left + bias) % n : -1;
  }
};
