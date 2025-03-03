class Solution {
public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> res, post; int pivot_cnt = 0;
    for (int e : nums) {
      if (e < pivot) res.push_back(e);
      else if (e == pivot) ++pivot_cnt;
      else post.push_back(e);
    }
    res.insert(res.end(), pivot_cnt, pivot);
    res.insert(res.end(), post.begin(), post.end());
    return res;
  }
};
