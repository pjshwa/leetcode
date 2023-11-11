class Solution {
public:
  int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
    int tr = tree[0], tc = tree[1], sr = squirrel[0], sc = squirrel[1];

    int ans = 0, mdist = -INT_MAX;
    for (auto& nut : nuts) {
      int nr = nut[0], nc = nut[1];
      
      int tdist = abs(nr - tr) + abs(nc - tc);
      ans += 2 * tdist;

      mdist = max(mdist, tdist - abs(nr - sr) - abs(nc - sc));
    }

    return ans - mdist;
  }
};
