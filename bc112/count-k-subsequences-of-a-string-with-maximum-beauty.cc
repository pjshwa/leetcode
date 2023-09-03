using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int countKSubsequencesWithMaxBeauty(string s, int k) {
    int n = s.size();
    map<char, int> f;
    for (char c : s) f[c]++;

    vector<int> cnts;
    for (auto [_, cnt] : f) cnts.push_back(cnt);

    sort(cnts.begin(), cnts.end(), greater<int>());
    while (cnts.size() > k) cnts.pop_back();

    if (cnts.size() < k) return 0;

    map<int, int> choose_cnt;
    for (int i = 0; i < cnts.size(); ++i) {
      choose_cnt[cnts[i]]++;
    }

    ll ans = 1;
    for (auto [v, cnt] : choose_cnt) {
      ll dp[27][27]{}; dp[0][0] = 1;
      for (char c = 'a'; c <= 'z'; c++) {
        int i = c - 'a' + 1;
        for (int j = 0; j <= 26; j++) dp[i][j] = dp[i - 1][j];

        int fval = f[c];
        if (fval != v) continue;

        for (int j = 1; j <= 26; j++) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * fval) % MOD;
        }
      }

      ans = ans * dp[26][cnt] % MOD;
    }
    return ans;
  }
};
