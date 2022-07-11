#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        bool dp[11][20001];
        memset(dp, 0, sizeof(dp));
        
        int m = toppingCosts.size();
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) for (int w = 0; w <= 2e4; w++) {
          dp[i][w] |= dp[i - 1][w];
          if (w >= toppingCosts[i - 1]) dp[i][w] |= dp[i - 1][w - toppingCosts[i - 1]];
          if (w >= toppingCosts[i - 1] * 2) dp[i][w] |= dp[i - 1][w - toppingCosts[i - 1] * 2];
        }
        
        vector<int> avail;
        for (int i = 0; i <= m; i++) for (int w = 0; w <= 2e4; w++) if (dp[i][w]) avail.push_back(w);
        compress(avail);

        int n = baseCosts.size();
        int mv = 1e9, md = 1e9;
        for (int i = 0; i < n; i++) {
            int ftarget = target - baseCosts[i];
            int fi = lower_bound(avail.begin(), avail.end(), ftarget) - avail.begin();
            int cp = avail[fi] + baseCosts[i];
            if (abs(target - cp) < md || (abs(target - cp) == md && cp < mv)) {
              md = abs(target - cp);
              mv = cp;
            }
            if (fi > 0) {
              int cp = avail[fi - 1] + baseCosts[i];
              if (abs(target - cp) < md || (abs(target - cp) == md && cp < mv)) {
                md = abs(target - cp);
                mv = cp;
              }
            }
            
        }
        
        return mv;
        
    }
};

int main() {
  // cout << (new Solution())->closestCost({1, 7}, {3, 4}, 10) << endl;
  // cout << (new Solution())->closestCost({3, 10}, {2, 5}, 9) << endl;
  // cout << (new Solution())->closestCost({2, 3}, {4, 5, 100}, 18) << endl;
  // cout << (new Solution())->closestCost({10}, {1}, 1) << endl;
}
