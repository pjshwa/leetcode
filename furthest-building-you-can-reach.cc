class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    int left = 0, right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      vector<int> need;
      for (int i = 0; i < mid; i++) {
        if (heights[i] >= heights[i + 1]) continue;
        need.push_back(heights[i + 1] - heights[i]);
      }
      sort(need.begin(), need.end());
      reverse(need.begin(), need.end());

      int nsize = 0;
      for (int i = ladders; i < need.size(); i++) nsize += need[i];

      if (nsize > bricks) right = mid;
      else left = mid + 1;
    }

    return left - 1;
  }
};
