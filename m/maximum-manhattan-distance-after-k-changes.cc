class Solution {
public:
  int maxDistance(string s, int k) {
    vector<pair<char, char>> s1 = {{'N', 'S'}, {'S', 'N'}};
    vector<pair<char, char>> s2 = {{'E', 'W'}, {'W', 'E'}};

    int ans = 0;
    for (auto& [f1, t1] : s1) for (auto& [f2, t2] : s2) {
      int x = 0, y = 0, ck = k;
      for (char c : s) {
        if (c == f1 && ck) c = t1, --ck;
        if (c == f2 && ck) c = t2, --ck;

        if (c == 'N') ++y;
        if (c == 'S') --y;
        if (c == 'E') ++x;
        if (c == 'W') --x;
        ans = max(ans, abs(x) + abs(y));
      }
    }
    return ans;
  }
};
