#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    // from the right, search for first index that has smaller element in front
    // if not found sort asc
    // else swap the location of the two + sort all elements in the right asc
    int size = nums.size();
    int smaller_element_index = -1;
    int smallest_element_on_rs = 2e9;
    int smallest_element_on_rs_index = -1;

    for (int i = size - 1; i > 0; i--) {
      if (nums[i] > nums[i - 1]) {
        smaller_element_index = i - 1;
        break;
      }
    }

    if (smaller_element_index == -1) {
      sort(nums.begin(), nums.end());
    }
    else {
      for (int i = smaller_element_index + 1; i < size; i++) {
        if (smallest_element_on_rs > nums[i] && nums[i] > nums[smaller_element_index]) {
          smallest_element_on_rs = nums[i];
          smallest_element_on_rs_index = i;
        }
      }

      // swap smaller_element_index - 1 and the smallest element in the right
      int temp = nums[smaller_element_index];
      nums[smaller_element_index] = smallest_element_on_rs;
      nums[smallest_element_on_rs_index] = temp;

      sort(nums.begin() + smaller_element_index + 1, nums.end());
    }
  }
};

int main() {
  Solution solution;

  vector<int> nums1{ 1, 2, 3 };
  solution.nextPermutation(nums1);
  for (auto &el : nums1) cout << el << ' ';
  cout << endl;

  vector<int> nums2{ 3, 2, 1 };
  solution.nextPermutation(nums2);
  for (auto &el : nums2) cout << el << ' ';
  cout << endl;

  vector<int> nums3{ 1, 1, 5 };
  solution.nextPermutation(nums3);
  for (auto &el : nums3) cout << el << ' ';
  cout << endl;

  vector<int> nums4{ 1, 1, 1 };
  solution.nextPermutation(nums4);
  for (auto &el : nums4) cout << el << ' ';
  cout << endl;

  vector<int> nums5{ 1, 2 };
  solution.nextPermutation(nums5);
  for (auto &el : nums5) cout << el << ' ';
  cout << endl;
}
