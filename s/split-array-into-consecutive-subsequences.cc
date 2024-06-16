class Solution {
public:
  bool isPossible(vector<int>& nums) {
    map<int, int> t, valid;
    for (int num : nums) t[num]++;
    for (int num : nums) {
      if (t[num] == 0) continue;
      t[num]--;

      if (valid[num - 1]) {
        valid[num - 1]--;
        valid[num]++;
      }
      else if (t[num + 1] && t[num + 2]) {
        t[num + 1]--;
        t[num + 2]--;
        valid[num + 2]++;
      }
      else return false;
    }

    return true;
  }
};
