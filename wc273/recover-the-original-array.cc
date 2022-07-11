class Solution {
public:
  vector<int> recoverArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> ks;
    for (int i = 1; i < nums.size(); i++) {
      int diff = nums[i] - nums[0];
      if (diff % 2 == 0) ks.push_back(diff / 2);
    }

    unordered_map<int, int> t;
    for (int i = 0; i < nums.size(); i++) {
      t[nums[i]]++;
    }
  
    vector<int> ans;

    for (int k : ks) {
      if (k == 0) continue;
      unordered_map<int, int> ct = t;
      bool able = true;
      for (int num : nums) {
        if (!ct[num]) continue;
        else {
          ct[num]--, ct[num + 2 * k]--;
          if (ct[num] < 0 || ct[num + 2 * k] < 0) {
            able = false;
            break;
          }
        }
      }

      if (able) {
        unordered_map<int, int> ct = t;
        for (int num : nums) {
          if (ct[num]) {
            ans.push_back(num + k);
            ct[num]--;
            ct[num + 2 * k]--;
          }
        }
        break;
      }
    }

    return ans;
      
  }
};
