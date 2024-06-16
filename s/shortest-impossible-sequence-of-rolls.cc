class Solution {
public:
  int shortestSequence(vector<int>& rolls, int k) {
    int ans = 1; set<int> U;
    for (int roll : rolls) {
      U.insert(roll);
      if (U.size() == k) {
        ans++;
        U.clear();
      }
    }
    return ans;
  }
};
