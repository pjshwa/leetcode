class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for (int e : asteroids) {
      if (e > 0 || ans.empty()) ans.push_back(e);
      else {
        while (!ans.empty() && ans.back() > 0 && ans.back() < -e) ans.pop_back();
        if (ans.empty() || ans.back() < 0) ans.push_back(e);
        else if (ans.back() == -e) ans.pop_back();
      }
    }
    return ans;
  }
};
