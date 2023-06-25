
class Solution {
public:
  int minimizeConcatenatedLength(vector<string>& words) {
    int N = words.size();
    int d[N][26][26]; memset(d, 0x3f, sizeof(d));
    
    d[0][words[0][0] - 'a'][words[0].back() - 'a'] = words[0].size();
    for (int i = 1; i < N; i++) {
      int f = words[i][0] - 'a', b = words[i].back() - 'a';
      int z = words[i].size();

      // put in back
      for (int p1 = 0; p1 < 26; p1++) for (int p2 = 0; p2 < 26; p2++) {
        d[i][p1][b] = min(d[i][p1][b], d[i - 1][p1][p2] + z - (p2 == f));
      }

      // put in front
      for (int p1 = 0; p1 < 26; p1++) for (int p2 = 0; p2 < 26; p2++) {
        d[i][f][p2] = min(d[i][f][p2], d[i - 1][p1][p2] + z - (p1 == b));
      }
    }

    int ans = 0x3f3f3f3f;
    for (int p1 = 0; p1 < 26; p1++) for (int p2 = 0; p2 < 26; p2++) {
      ans = min(ans, d[N - 1][p1][p2]);
    }
    return ans;
  }
};
