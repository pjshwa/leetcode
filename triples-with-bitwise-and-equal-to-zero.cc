const int MAXV = 1 << 16;

class Solution {
public:
  int countTriplets(vector<int>& nums) {
    int valuesCounts[MAXV]{};
    for (int e1 : nums) for (int e2 : nums) valuesCounts[e1 & e2]++;

    int ans = 0;
    for (int e3 : nums) for (int value = 0; value < MAXV; value++) {
      if (e3 & value) continue;
      ans += valuesCounts[value];
    }

    return ans;
  }
};
