class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int n = nums.size(), pivot = 0;
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] > nums[i + 1]) {
        pivot = i + 1;
        break;
      }
    }

    int left = 0, right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      int idx = (mid + pivot) % n;

      if (nums[idx] == target) return true;
      else if (nums[idx] < target) left = mid + 1;
      else right = mid;
    }

    return false;
  }
};
