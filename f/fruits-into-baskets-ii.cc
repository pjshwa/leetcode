class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int ans = fruits.size();
    for (int f : fruits) {
      for (int& b : baskets) {
        if (b < f) continue;
        b = -1; --ans;
        break;
      }
    }
    return ans;
  }
};
