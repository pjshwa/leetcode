class Solution {
  bool isPunishmentNumber(int n) {
    string str = to_string(n * n);
    int z = str.size();
    for (int s = 0; s < (1 << (z - 1)); ++s) {
      int sum = 0;
      int prev = 0;
      for (int i = 0; i < z - 1; ++i) {
        if (s & (1 << i)) {
          sum += stoi(str.substr(prev, i - prev + 1));
          prev = i + 1;
        }
      }
      sum += stoi(str.substr(prev));
      if (sum == n) return true;
    }
    return false;
  }

public:
  int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (isPunishmentNumber(i)) ans += i * i;
    }
    return ans;
  }
};
