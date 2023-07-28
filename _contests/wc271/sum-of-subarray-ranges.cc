#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

const int MAX = 1000;
int rmin[MAX][MAX], rmax[MAX][MAX];

class Solution {
public:
  long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      rmin[i][i] = nums[i];
      rmax[i][i] = nums[i];

      for (int j = i + 1; j < n; j++) {
        rmin[i][j] = min(rmin[i][j - 1], nums[j]);
        rmax[i][j] = max(rmax[i][j - 1], nums[j]);
      }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans += (rmax[i][j] - rmin[i][j]);
      }
    }

    return ans;
  }
};

int main() {
  // cout << (new Solution())->closestCost({1, 7}, {3, 4}, 10) << endl;
  // cout << (new Solution())->closestCost({3, 10}, {2, 5}, 9) << endl;
  // cout << (new Solution())->closestCost({2, 3}, {4, 5, 100}, 18) << endl;
  // cout << (new Solution())->closestCost({10}, {1}, 1) << endl;
}
