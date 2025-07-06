class FindSumPairs {
  vector<int> nums1, nums2;
  unordered_map<int, int> cMap;

public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (int num : nums2) ++cMap[num];
  }

  void add(int index, int val) {
    --cMap[nums2[index]];
    nums2[index] += val;
    ++cMap[nums2[index]];
  }

  int count(int tot) {
    int ans = 0;
    for (int num : nums1) {
      int t = tot - num;
      if (cMap.find(t) != cMap.end()) ans += cMap[t];
    }
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
