class Solution {
  vector<int> nums;

  int lis() {
    vector<int> lis_vector;
    lis_vector.push_back(-(1e9 + 1));

    for (int i = 0; i < nums.size(); i++) {
      int next = nums[i];

      if (next < lis_vector[0]) lis_vector[0] = next;
      else if (next >= lis_vector.back()) lis_vector.push_back(next);
      else {
        auto it = upper_bound(lis_vector.begin(), lis_vector.end(), next);
        *it = next;
      }
    }

    return (lis_vector.size() - 1);
  }

public:
  int kIncreasing(vector<int>& arr, int k) {
    int ans = 0;
    for (int st = 0; st < k; st++) {
      nums.clear();
      for (int j = st; j < arr.size(); j += k) nums.push_back(arr[j]);
      int res = lis();
      ans += (nums.size() - res);
    }
    return ans;
  }
};
