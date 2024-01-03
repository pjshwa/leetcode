class Solution {
public:
  int numberOfBeams(vector<string>& bank) {
    int m = bank[0].size();
    string none = "";
    for (int i = 0; i < m; i++) none += '0';

    vector<string> real;
    for (auto& s : bank) if (s != none) real.push_back(s);

    int ans = 0;
    int n = real.size();
    for (int i = 0; i < n - 1; i++) {
      string r1 = real[i];
      string r2 = real[i + 1];
      int c1 = 0, c2 = 0;
      for (char c : r1) if (c == '1') c1++;
      for (char c : r2) if (c == '1') c2++;

      ans += c1 * c2;
    }

    return ans;
  }
};
