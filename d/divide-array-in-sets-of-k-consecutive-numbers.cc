#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    int n = nums.size();
    if (n % k) return false;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      auto found = cnt.find(nums[i]);
      if (found == cnt.end()) cnt.insert({nums[i], 1});
      else found->second++;
    }
    sort(nums.begin(), nums.end());

    int nsp = 0;
    for (int i = 0; i < n / k; i++) {
      while (!cnt[nums[nsp]]) nsp++;
      for (int j = 0; j < k; j++) {
        if (cnt[nums[nsp] + j]) cnt[nums[nsp] + j]--;
        else return false;
      }
    }

    return true;
  }
};

int main() {
  Solution solution;

  vector<int> nums1{1,2,3,3,4,4,5,6};
  cout << solution.isPossibleDivide(nums1, 4) << endl;

  vector<int> nums2{3,2,1,2,3,4,3,4,5,9,10,11};
  cout << solution.isPossibleDivide(nums2, 3) << endl;

  vector<int> nums3{3,3,2,2,1,1};
  cout << solution.isPossibleDivide(nums3, 3) << endl;

  vector<int> nums4{1,2,3,4};
  cout << solution.isPossibleDivide(nums4, 3) << endl;

  vector<int> nums5{1};
  cout << solution.isPossibleDivide(nums5, 1) << endl;
}
