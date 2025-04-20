const int MAXU = 1000;

class Solution {
public:
  int numRabbits(vector<int>& answers) {
    int U[MAXU] = {0};
    for (int e : answers) ++U[e];
    
    int ans = 0;
    for (int i = 0; i < MAXU; ++i) {
      int g = i + 1;
      ans += (U[i] + i) / g * g;
    }
    return ans;
  }
};
