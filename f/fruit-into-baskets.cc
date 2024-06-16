class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();

    int t[n], z = 0, r = 0;
    memset(t, 0, sizeof(t));
    auto inc = [&] (int i) { if (t[i] == 0) z++; t[i]++; };
    auto dec = [&] (int i) { if (t[i] == 1) z--; t[i]--; };

    int ans = 0;
    for (int l = 0; l < n; l++) {
      while (r < n && (z < 2 || t[fruits[r]] > 0)) {
        inc(fruits[r]);
        r++;
      }
      ans = max(ans, r - l);
      dec(fruits[l]);
    }
    return ans;
  }
};
