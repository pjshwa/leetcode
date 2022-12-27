class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    vector<int> diffs; int n = capacity.size();
    for (int i = 0; i < n; i++) diffs.push_back(capacity[i] - rocks[i]);
    sort(diffs.begin(), diffs.end());

    int acc = 0;
    for (int i = 0; i < n; i++) {
      acc += diffs[i];
      if (acc > additionalRocks) return i;
    }
    return n;
  }
};
