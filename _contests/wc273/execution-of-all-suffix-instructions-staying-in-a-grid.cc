class Solution {
public:
  vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    int x = startPos[0], y = startPos[1];
    int sz = s.size();

    vector<int> ans;
    for (int i = 0; i < sz; i++) {
      string ns = s.substr(i);
      int cnt = 0, cx = x, cy = y;
      for (char c : ns) {
        if (c == 'L') cy--;
        if (c == 'R') cy++;
        if (c == 'U') cx--;
        if (c == 'D') cx++;

        if (cx < 0 || cy < 0 || cx >= n || cy >= n) break;
        else cnt++;
      }
      ans.push_back(cnt);
    }
    
    return ans;
  }
};
