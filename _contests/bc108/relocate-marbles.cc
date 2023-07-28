class Solution {
public:
  vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
    set<int> U;
    for (int e : nums) U.insert(e);

    int N = moveFrom.size();
    for (int i = 0; i < N; i++) {
      int from = moveFrom[i], to = moveTo[i];
      if (U.find(from) == U.end()) continue;
      U.erase(from);
      U.insert(to);
    }
    return vector<int>(U.begin(), U.end());
  }
};
